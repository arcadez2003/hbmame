// license:GPL-2.0+
// copyright-holders:Dirk Best
/***************************************************************************

    ACT Apricot PC/Xi

    TODO:
    - External RS232 data transfers to the Apricot are usually garbage (but
      sending to an external target works fine)
    - Dump of the keyboard MCU ROM needed (can be dumped using test mode)

***************************************************************************/

#include "emu.h"
#include "bus/apricot/expansion/expansion.h"
#include "bus/apricot/keyboard/keyboard.h"
#include "bus/centronics/ctronics.h"
#include "bus/rs232/rs232.h"
#include "cpu/i86/i86.h"
#include "cpu/i8089/i8089.h"
#include "formats/apridisk.h"
#include "imagedev/floppy.h"
#include "machine/clock.h"
#include "machine/ram.h"
#include "machine/74153.h"
#include "machine/i8255.h"
#include "machine/pic8259.h"
#include "machine/pit8253.h"
#include "machine/wd_fdc.h"
#include "machine/z80sio.h"
#include "sound/sn76496.h"
#include "video/mc6845.h"
#include "emupal.h"
#include "screen.h"
#include "softlist.h"
#include "speaker.h"


//**************************************************************************
//  TYPE DEFINITIONS
//**************************************************************************

class apricot_state : public driver_device
{
public:
	apricot_state(const machine_config &mconfig, device_type type, const char *tag) :
		driver_device(mconfig, type, tag),
		m_cpu(*this, "ic91"),
		m_iop(*this, "ic71"),
		m_ram(*this, RAM_TAG),
		m_crtc(*this, "ic30"),
		m_ppi(*this, "ic17"),
		m_pic(*this, "ic31"),
		m_pit(*this, "ic16"),
		m_sio(*this, "ic15"),
		m_rs232(*this, "rs232"),
		m_centronics(*this, "centronics"),
		m_fdc(*this, "ic68"),
		m_floppy0(*this, "ic68:0"),
		m_floppy1(*this, "ic68:1"),
		m_palette(*this, "palette"),
		m_screen_buffer(*this, "screen_buffer"),
		m_video_mode(0),
		m_display_on(1),
		m_display_enabled(0),
		m_centronics_fault(1),
		m_centronics_perror(1),
		m_bus_locked(0)
	{ }

	void apricot(machine_config &config);
	void apricotxi(machine_config &config);

private:
	DECLARE_FLOPPY_FORMATS(floppy_formats);

	DECLARE_WRITE_LINE_MEMBER(i8086_lock_w);
	DECLARE_WRITE8_MEMBER(i8089_ca1_w);
	DECLARE_WRITE8_MEMBER(i8089_ca2_w);
	DECLARE_WRITE8_MEMBER(i8255_portb_w);
	DECLARE_READ8_MEMBER(i8255_portc_r);
	DECLARE_WRITE8_MEMBER(i8255_portc_w);
	DECLARE_WRITE_LINE_MEMBER(fdc_intrq_w);
	DECLARE_READ8_MEMBER(sio_da_r);
	DECLARE_READ8_MEMBER(sio_ca_r);
	DECLARE_READ8_MEMBER(sio_db_r);
	DECLARE_READ8_MEMBER(sio_cb_r);

	DECLARE_WRITE_LINE_MEMBER(write_centronics_fault);
	DECLARE_WRITE_LINE_MEMBER(write_centronics_perror);

	DECLARE_WRITE_LINE_MEMBER(apricot_hd6845_de) { m_display_enabled = state; };

	MC6845_UPDATE_ROW(crtc_update_row);
	uint32_t screen_update_apricot(screen_device &screen, bitmap_rgb32 &bitmap, const rectangle &cliprect);

	void apricot_io(address_map &map);
	void apricot_mem(address_map &map);

	virtual void machine_start() override;

	required_device<i8086_cpu_device> m_cpu;
	required_device<i8089_device> m_iop;
	required_device<ram_device> m_ram;
	required_device<hd6845_device> m_crtc;
	required_device<i8255_device> m_ppi;
	required_device<pic8259_device> m_pic;
	required_device<pit8253_device> m_pit;
	required_device<z80sio_device> m_sio;
	required_device<rs232_port_device> m_rs232;
	required_device<centronics_device> m_centronics;
	required_device<wd2797_device> m_fdc;
	required_device<floppy_connector> m_floppy0;
	required_device<floppy_connector> m_floppy1;
	required_device<palette_device> m_palette;
	required_shared_ptr<uint16_t> m_screen_buffer;

	bool m_video_mode;
	bool m_display_on;

	int m_display_enabled;

	int m_centronics_fault;
	int m_centronics_perror;

	int m_bus_locked;
};


//**************************************************************************
//  I/O
//**************************************************************************

WRITE8_MEMBER( apricot_state::i8089_ca1_w )
{
	m_iop->sel_w(0);
	m_iop->ca_w(1);
	m_iop->ca_w(0);
}

WRITE8_MEMBER( apricot_state::i8089_ca2_w )
{
	m_iop->sel_w(1);
	m_iop->ca_w(1);
	m_iop->ca_w(0);
}

WRITE_LINE_MEMBER( apricot_state::write_centronics_fault )
{
	m_centronics_fault = state;
	m_sio->syncb_w(state);
	m_ppi->pc2_w(state);
}

WRITE_LINE_MEMBER( apricot_state::write_centronics_perror )
{
	m_centronics_perror = state;
}

READ8_MEMBER( apricot_state::i8255_portc_r )
{
	uint8_t data = 0;

	data |= m_centronics_perror << 0;
	// schematic page 294 says pc1 is centronics pin 34, which is n/c.
	data |= m_centronics_fault << 2;
	data |= m_display_enabled << 3;

	return data;
}

WRITE8_MEMBER( apricot_state::i8255_portb_w )
{
	// bit 0, crt reset
	// bit 1, not connected

	m_display_on = BIT(data, 3);
	m_video_mode = BIT(data, 4);

	floppy_image_device *floppy = nullptr;

	// bit 5, enable disk select
	// bit 6, disk select
	if (!BIT(data, 5))
		floppy = BIT(data, 6) ? m_floppy1->get_device() : m_floppy0->get_device();

	m_fdc->set_floppy(floppy);

	// bit 2, head load (motor on is wired to be active once a disk has been inserted)
	// we just let the motor run all the time for now
	if (floppy)
		floppy->mon_w(0);

	// switch video modes
	m_crtc->set_clock(15_MHz_XTAL / (m_video_mode ? 10 : 16));
	m_crtc->set_hpixels_per_column(m_video_mode ? 10 : 16);

	// PB7 Centronics transceiver direction. 0 = output, 1 = input
}

WRITE8_MEMBER( apricot_state::i8255_portc_w )
{
//  schematic page 294 says pc4 outputs to centronics pin 13, which is the "select" output from the printer.
	m_centronics->write_strobe(BIT(data, 5));
//  schematic page 294 says pc6 outputs to centronics pin 15, which is unused
}

READ8_MEMBER( apricot_state::sio_da_r )
{
	if (m_bus_locked)
		return m_sio->m1_r();

	return m_sio->da_r(space, offset);
}

READ8_MEMBER( apricot_state::sio_ca_r )
{
	if (m_bus_locked)
		return m_sio->m1_r();

	return m_sio->ca_r(space, offset);
}

READ8_MEMBER( apricot_state::sio_cb_r )
{
	if (m_bus_locked)
		return m_sio->m1_r();

	return m_sio->cb_r(space, offset);
}

READ8_MEMBER( apricot_state::sio_db_r )
{
	if (m_bus_locked)
		return m_sio->m1_r();

	return m_sio->db_r(space, offset);
}


//**************************************************************************
//  FLOPPY
//**************************************************************************

WRITE_LINE_MEMBER( apricot_state::fdc_intrq_w )
{
	m_pic->ir4_w(state);
	m_iop->ext1_w(state);
}

FLOPPY_FORMATS_MEMBER( apricot_state::floppy_formats )
	FLOPPY_APRIDISK_FORMAT
FLOPPY_FORMATS_END

static void apricot_floppies(device_slot_interface &device)
{
	device.option_add("d31v", SONY_OA_D31V);
	device.option_add("d32w", SONY_OA_D32W);
}


//**************************************************************************
//  VIDEO EMULATION
//**************************************************************************

uint32_t apricot_state::screen_update_apricot(screen_device &screen, bitmap_rgb32 &bitmap, const rectangle &cliprect)
{
	if (!m_display_on)
		m_crtc->screen_update(screen, bitmap, cliprect);
	else
		bitmap.fill(rgb_t::black(), cliprect);

	return 0;
}

MC6845_UPDATE_ROW( apricot_state::crtc_update_row )
{
	const pen_t *pen = m_palette->pens();

	for (int i = 0; i < x_count; i++)
	{
		uint16_t code = m_screen_buffer[(ma + i) & 0x7ff];
		uint16_t offset = ((code & 0x7ff) << 5) | (ra << 1);
		uint16_t data = m_cpu->space(AS_PROGRAM).read_word(offset);

		if (m_video_mode)
		{
			int fill = 0;

			if (i == cursor_x) fill = 1; // cursor?
			if (BIT(code, 12) && BIT(data, 14)) fill = 1; // strike-through?
			if (BIT(code, 13) && BIT(data, 15)) fill = 1; // underline?

			// draw 10 pixels of the character
			for (int x = 0; x <= 10; x++)
			{
				int color = fill ? 1 : BIT(data, x);
				color ^= BIT(code, 15); // reverse?
				bitmap.pix32(y, x + i*10) = pen[color ? 1 + BIT(code, 14) : 0];
			}
		}
		else
		{
			// draw 16 pixels of the cell
			for (int x = 0; x <= 16; x++)
				bitmap.pix32(y, x + i*16) = pen[BIT(data, x)];
		}
	}
}

//**************************************************************************
//  MACHINE EMULATION
//**************************************************************************

void apricot_state::machine_start()
{
	membank("ram")->set_base(m_ram->pointer());
}

WRITE_LINE_MEMBER( apricot_state::i8086_lock_w )
{
	m_bus_locked = state;
}


//**************************************************************************
//  ADDRESS MAPS
//**************************************************************************

void apricot_state::apricot_mem(address_map &map)
{
	map(0x00000, 0x3ffff).bankrw("ram");
	map(0xf0000, 0xf0fff).mirror(0x7000).ram().share("screen_buffer");
	map(0xf8000, 0xfbfff).mirror(0x4000).rom().region("bootstrap", 0);
}

void apricot_state::apricot_io(address_map &map)
{
	map(0x00, 0x03).rw(m_pic, FUNC(pic8259_device::read), FUNC(pic8259_device::write)).umask16(0x00ff);
	map(0x40, 0x47).rw(m_fdc, FUNC(wd2797_device::read), FUNC(wd2797_device::write)).umask16(0x00ff);
	map(0x48, 0x4f).rw(m_ppi, FUNC(i8255_device::read), FUNC(i8255_device::write)).umask16(0x00ff);
	map(0x50, 0x50).mirror(0x06).w("ic7", FUNC(sn76489_device::command_w));
	map(0x58, 0x5f).rw(m_pit, FUNC(pit8253_device::read), FUNC(pit8253_device::write)).umask16(0x00ff);
	map(0x60, 0x60).r(FUNC(apricot_state::sio_da_r)).w(m_sio, FUNC(z80sio_device::da_w)).umask16(0x00ff);
	map(0x62, 0x62).r(FUNC(apricot_state::sio_ca_r)).w(m_sio, FUNC(z80sio_device::ca_w)).umask16(0x00ff);
	map(0x64, 0x64).r(FUNC(apricot_state::sio_db_r)).w(m_sio, FUNC(z80sio_device::db_w)).umask16(0x00ff);
	map(0x66, 0x66).r(FUNC(apricot_state::sio_cb_r)).w(m_sio, FUNC(z80sio_device::cb_w)).umask16(0x00ff);
	map(0x68, 0x68).mirror(0x04).w(m_crtc, FUNC(hd6845_device::address_w));
	map(0x6a, 0x6a).mirror(0x04).rw(m_crtc, FUNC(hd6845_device::register_r), FUNC(hd6845_device::register_w));
	map(0x70, 0x70).mirror(0x04).w(FUNC(apricot_state::i8089_ca1_w));
	map(0x72, 0x72).mirror(0x04).w(FUNC(apricot_state::i8089_ca2_w));
	map(0x78, 0x7f).noprw(); // unavailable
}


//**************************************************************************
//  MACHINE DRIVERS
//**************************************************************************

MACHINE_CONFIG_START(apricot_state::apricot)
	// main cpu
	MCFG_DEVICE_ADD("ic91", I8086, 15_MHz_XTAL / 3)
	MCFG_DEVICE_PROGRAM_MAP(apricot_mem)
	MCFG_DEVICE_IO_MAP(apricot_io)
	MCFG_DEVICE_IRQ_ACKNOWLEDGE_DEVICE("ic31", pic8259_device, inta_cb)
	MCFG_I8086_LOCK_HANDLER(WRITELINE(*this, apricot_state, i8086_lock_w))

	// i/o cpu
	MCFG_DEVICE_ADD("ic71", I8089, 15_MHz_XTAL / 3)
	MCFG_DEVICE_PROGRAM_MAP(apricot_mem)
	MCFG_DEVICE_IO_MAP(apricot_io)
	MCFG_I8089_DATA_WIDTH(16)
	MCFG_I8089_SINTR1(WRITELINE(m_pic, pic8259_device, ir0_w))
	MCFG_I8089_SINTR2(WRITELINE(m_pic, pic8259_device, ir1_w))

	// ram
	RAM(config, RAM_TAG).set_default_size("256K");

	// video hardware
	MCFG_SCREEN_ADD_MONOCHROME("screen", RASTER, rgb_t::green())
	MCFG_SCREEN_SIZE(800, 400)
	MCFG_SCREEN_VISIBLE_AREA(0, 800-1, 0, 400-1)
	MCFG_SCREEN_REFRESH_RATE(72)
	MCFG_SCREEN_UPDATE_DRIVER(apricot_state, screen_update_apricot)

	MCFG_PALETTE_ADD_MONOCHROME_HIGHLIGHT("palette")

	HD6845(config, m_crtc, 15_MHz_XTAL / 10);
	m_crtc->set_screen("screen");
	m_crtc->set_show_border_area(false);
	m_crtc->set_char_width(10);
	m_crtc->set_update_row_callback(FUNC(apricot_state::crtc_update_row), this);
	m_crtc->out_de_callback().set(FUNC(apricot_state::apricot_hd6845_de));

	// sound hardware
	SPEAKER(config, "mono").front_center();
	MCFG_DEVICE_ADD("ic7", SN76489, 4_MHz_XTAL / 2)
	MCFG_SOUND_ROUTE(ALL_OUTPUTS, "mono", 1.0)

	// devices
	I8255A(config, m_ppi, 0);
	m_ppi->in_pa_callback().set("cent_data_in", FUNC(input_buffer_device::bus_r));
	m_ppi->out_pa_callback().set("cent_data_out", FUNC(output_latch_device::bus_w));
	m_ppi->out_pb_callback().set(FUNC(apricot_state::i8255_portb_w));
	m_ppi->in_pc_callback().set(FUNC(apricot_state::i8255_portc_r));
	m_ppi->out_pc_callback().set(FUNC(apricot_state::i8255_portc_w));

	PIC8259(config, m_pic, 0);
	m_pic->out_int_callback().set_inputline(m_cpu, 0);

	PIT8253(config, m_pit, 0);
	m_pit->set_clk<0>(4_MHz_XTAL / 16);
	m_pit->out_handler<0>().set(m_pic, FUNC(pic8259_device::ir6_w));
	m_pit->set_clk<1>(4_MHz_XTAL / 2);
	m_pit->out_handler<1>().set("ic14", FUNC(ttl153_device::i0a_w));
	m_pit->set_clk<2>(4_MHz_XTAL / 2);
	m_pit->out_handler<2>().set("ic14", FUNC(ttl153_device::i0b_w));
	m_pit->out_handler<2>().append("ic14", FUNC(ttl153_device::i2a_w));
	m_pit->out_handler<2>().append("ic14", FUNC(ttl153_device::i2b_w));

	ttl153_device &ttl74153(TTL153(config, "ic14"));
	ttl74153.za_cb().set("ic15", FUNC(z80sio_device::rxca_w));
	ttl74153.zb_cb().set("ic15", FUNC(z80sio_device::txca_w));

	CLOCK(config, "ic15_rxtxcb", 4_MHz_XTAL / 16).signal_handler().set(m_sio, FUNC(z80sio_device::rxtxcb_w));

	Z80SIO(config, m_sio, 15_MHz_XTAL / 6);
	m_sio->set_cputag(m_cpu);
	m_sio->out_txda_callback().set(m_rs232, FUNC(rs232_port_device::write_txd));
	m_sio->out_dtra_callback().set(m_rs232, FUNC(rs232_port_device::write_dtr));
	m_sio->out_rtsa_callback().set(m_rs232, FUNC(rs232_port_device::write_rts));
	m_sio->out_wrdya_callback().set(m_iop, FUNC(i8089_device::drq2_w));
	m_sio->out_txdb_callback().set("kbd", FUNC(apricot_keyboard_bus_device::out_w));
	m_sio->out_dtrb_callback().set("ic14", FUNC(ttl153_device::s0_w));
	m_sio->out_rtsb_callback().set("ic14", FUNC(ttl153_device::s1_w));
	m_sio->out_int_callback().set(m_pic, FUNC(pic8259_device::ir5_w));

	// rs232 port
	RS232_PORT(config, m_rs232, default_rs232_devices, nullptr);
	// note: missing a receive clock callback to support external clock mode (i1 to 153)
	m_rs232->rxd_handler().set(m_sio, FUNC(z80sio_device::rxa_w));
	m_rs232->dcd_handler().set(m_sio, FUNC(z80sio_device::dcda_w));
	m_rs232->dsr_handler().set(m_sio, FUNC(z80sio_device::synca_w));
	m_rs232->cts_handler().set(m_sio, FUNC(z80sio_device::ctsa_w)).invert();

	// keyboard
	APRICOT_KEYBOARD_INTERFACE(config, "kbd", apricot_keyboard_devices, "hle").in_handler().set(m_sio, FUNC(z80sio_device::rxb_w));

	// centronics printer
	CENTRONICS(config, m_centronics, centronics_devices, "printer");
	m_centronics->set_data_input_buffer("cent_data_in");
	m_centronics->ack_handler().set(m_sio, FUNC(z80sio_device::ctsb_w));
	m_centronics->busy_handler().set(m_sio, FUNC(z80sio_device::dcdb_w));
	m_centronics->fault_handler().set(FUNC(apricot_state::write_centronics_fault));
	m_centronics->perror_handler().set(FUNC(apricot_state::write_centronics_perror));
	//m_centronics->select_handler().set(); // schematic page 294 says this is connected to pc4, but that is an output to the printer

	INPUT_BUFFER(config, "cent_data_in");
	MCFG_CENTRONICS_OUTPUT_LATCH_ADD("cent_data_out", "centronics")

	// floppy
	WD2797(config, m_fdc, 4_MHz_XTAL / 2);
	m_fdc->intrq_wr_callback().set(FUNC(apricot_state::fdc_intrq_w));
	m_fdc->drq_wr_callback().set(m_iop, FUNC(i8089_device::drq1_w));
	MCFG_FLOPPY_DRIVE_ADD("ic68:0", apricot_floppies, "d32w", apricot_state::floppy_formats)
	MCFG_FLOPPY_DRIVE_ADD("ic68:1", apricot_floppies, "d32w", apricot_state::floppy_formats)

	MCFG_SOFTWARE_LIST_ADD("flop_list", "apricot_flop")

	// expansion bus
	MCFG_EXPANSION_ADD("exp", "ic91")
	MCFG_EXPANSION_IOP_ADD("ic71")
	MCFG_EXPANSION_SLOT_ADD("exp:1", apricot_expansion_cards, nullptr)
	MCFG_EXPANSION_SLOT_ADD("exp:2", apricot_expansion_cards, nullptr)
MACHINE_CONFIG_END

void apricot_state::apricotxi(machine_config &config)
{
	apricot(config);
}


//**************************************************************************
//  ROM DEFINITIONS
//**************************************************************************

ROM_START( apricot )
	ROM_REGION(0x4000, "bootstrap", 0)
	ROM_LOAD16_BYTE("pc_bios_lo_001.bin", 0x0000, 0x2000, CRC(0c217cc2) SHA1(0d7a2b61e17966462b555115f962a175fadcf72a))
	ROM_LOAD16_BYTE("pc_bios_hi_001.bin", 0x0001, 0x2000, CRC(7c27f36c) SHA1(c801bbf904815f76ec6463e948f57e0118a26292))
ROM_END

ROM_START( apricotxi )
	ROM_REGION(0x4000, "bootstrap", 0)
	ROM_LOAD16_BYTE("lo_ve007.u11", 0x0000, 0x2000, CRC(e74e14d1) SHA1(569133b0266ce3563b21ae36fa5727308797deee)) // LO Ve007 03.04.84
	ROM_LOAD16_BYTE("hi_ve007.u9",  0x0001, 0x2000, CRC(b04fb83e) SHA1(cc2b2392f1b4c04bb6ec8ee26f8122242c02e572)) // HI Ve007 03.04.84
ROM_END


//**************************************************************************
//  GAME DRIVERS
//**************************************************************************

//    YEAR  NAME       PARENT   COMPAT  MACHINE    INPUT  CLASS          INIT        COMPANY  FULLNAME      FLAGS
COMP( 1983, apricot,   0,       0,      apricot,   0,     apricot_state, empty_init, "ACT",   "Apricot PC", 0 )
COMP( 1984, apricotxi, apricot, 0,      apricotxi, 0,     apricot_state, empty_init, "ACT",   "Apricot Xi", 0 )
