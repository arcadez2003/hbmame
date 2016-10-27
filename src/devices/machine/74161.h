// license:BSD-3-Clause
// copyright-holders:Ryan Holtz
/*****************************************************************************

	5/74160..3 BCD decade counter / 4-bit binary counter

***********************************************************************

	Connection Diagram:
              ___ ___
       *R  1 |*  u   | 16  Vcc
       CP  2 |       | 15  TC
       P0  3 |       | 14  Q0
       P1  4 |       | 13  Q1
       P2  5 |       | 12  Q2
       P3  6 |       | 11  Q3
      CEP  7 |       | 10  CET
      GND  8 |_______| 9   /PE

		*MR for 160 and 161
		*SR for 162 and 163

	Logic Symbol:

	           9   3   4   5   6
	           |   |   |   |   |
	       ____|___|___|___|___|____
	      |                         |
	      |    PE  P0  P1  P2  P3   |
	 7 ---| CEP                     |
	      |                         |
	10 ---| CET                  TC |--- 15
	      |                         |
	 2 ---| CP                      |
	      |    MR  Q0  Q1  Q2  Q3   |
	      |_________________________|
	           |   |   |   |   |
	           |   |   |   |   |
               1  14  13  12  11


***********************************************************************

	Mode Select Table:

	MR	PE	CET	CEP		Action on clock edge
	L	X	X	X		Reset (clear)
	H	L	X	X		Load Pn..Qn
	H	H	H	H		Count (increment)
	H	H	L	X		No change (hold)
	H	H	X	L		No change (hold)

**********************************************************************/

#pragma once

#ifndef TTL74161_H
#define TTL74161_H

#include "emu.h"

#define MCFG_74161_OUTPUT_CB(_devcb) \
	devcb = &ttl74161_device::set_output_cb(*device, DEVCB_##_devcb);

#define MCFG_74161_TC_CB(_devcb) \
	devcb = &ttl74161_device::set_comp_output_cb(*device, DEVCB_##_devcb);

#define MCFG_74160_ADD(_tag) \
	MCFG_DEVICE_ADD(_tag, TTL74160, 0)

#define MCFG_74161_ADD(_tag) \
	MCFG_DEVICE_ADD(_tag, TTL74161, 0)

#define MCFG_74162_ADD(_tag) \
	MCFG_DEVICE_ADD(_tag, TTL74162, 0)

#define MCFG_74163_ADD(_tag) \
	MCFG_DEVICE_ADD(_tag, TTL74163, 0)

class ttl7416x_device : public device_t
{
public:
	// construction/destruction
	ttl7416x_device(const machine_config &mconfig, device_type type, const char *name, const char *tag, device_t *owner, uint32_t clock, const char *shortname, bool synchronous_reset, uint8_t limit);

	// static configuration helpers
	template<class _Object> static devcb_base &set_output_cb(device_t &device, _Object object) { return downcast<ttl7416x_device &>(device).m_output_func.set_callback(object); }
	template<class _Object> static devcb_base &set_tc_cb(device_t &device, _Object object) { return downcast<ttl7416x_device &>(device).m_tc_func.set_callback(object); }

	// public interfaces
	DECLARE_WRITE_LINE_MEMBER( clear_w );
	DECLARE_WRITE_LINE_MEMBER( pe_w );
	DECLARE_WRITE_LINE_MEMBER( cet_w );
	DECLARE_WRITE_LINE_MEMBER( cep_w );
	DECLARE_WRITE_LINE_MEMBER( clock_w );

	DECLARE_READ_LINE_MEMBER( output_r );
	DECLARE_READ_LINE_MEMBER( tc_r );

protected:
	// device-level overrides
	virtual void device_start() override;
	virtual void device_reset() override;

private:
	void init();
	void tick();
	void increment();

	// callbacks
	devcb_write8 m_output_func;
	devcb_write_line m_tc_func;

	// inputs
	uint8_t m_clear;	// pin 1
	uint8_t m_pe;		// pin 9
	uint8_t m_cet;		// pin 10
	uint8_t m_cep;		// pin 7
	uint8_t m_clock;	// pin 2
	uint8_t m_p;		// pins 3-6 from LSB to MSB

	// outputs
	uint8_t m_out;		// pins 14-11 from LSB to MSB
	uint8_t m_tc;		// pin 15

	// old state
	uint8_t m_last_clock;
	uint8_t m_last_out;
	uint8_t m_last_tc;

	const bool		m_synchronous_reset;
	const uint8_t	m_limit;
};

class ttl74160_device : public ttl7416x_device
{
public:
	ttl74160_device(const machine_config &mconfig, const char *tag, device_t *owner, uint32_t clock);
};

class ttl74161_device : public ttl7416x_device
{
public:
	ttl74161_device(const machine_config &mconfig, const char *tag, device_t *owner, uint32_t clock);
};

class ttl74162_device : public ttl7416x_device
{
public:
	ttl74162_device(const machine_config &mconfig, const char *tag, device_t *owner, uint32_t clock);
};

class ttl74163_device : public ttl7416x_device
{
public:
	ttl74163_device(const machine_config &mconfig, const char *tag, device_t *owner, uint32_t clock);
};

// device type definition
extern const device_type TTL74160;
extern const device_type TTL74161;
extern const device_type TTL74162;
extern const device_type TTL74163;


#endif /* TTL74161_H */
