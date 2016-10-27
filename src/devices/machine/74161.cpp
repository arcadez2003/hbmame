// license:BSD-3-Clause
// copyright-holders:Ryan Holtz
/*****************************************************************************

	54/74161 4-bit binary counter

*****************************************************************************/

#include "emu.h"
#include "74161.h"

const device_type TTL74160 = &device_creator<ttl74160_device>;
const device_type TTL74161 = &device_creator<ttl74161_device>;
const device_type TTL74162 = &device_creator<ttl74162_device>;
const device_type TTL74163 = &device_creator<ttl74163_device>;

ttl7416x_device::ttl7416x_device(const machine_config &mconfig, device_type type, const char *name, const char *tag, device_t *owner, uint32_t clock, const char *shortname, bool synchronous_reset, uint8_t limit)
	: device_t(mconfig, type, name, tag, owner, clock, shortname, __FILE__)
	, m_output_func(*this)
	, m_tc_func(*this)
	, m_clear(0)
	, m_pe(0)
	, m_cet(0)
	, m_cep(0)
	, m_clock(0)
	, m_p(0)
	, m_out(0)
	, m_tc(0)
	, m_last_clock(0)
	, m_last_out(0)
	, m_last_tc(0)
	, m_synchronous_reset(synchronous_reset)
	, m_limit(limit)
{
}

ttl74160_device::ttl74160_device(const machine_config &mconfig, const char *tag, device_t *owner, uint32_t clock)
	: ttl7416x_device(mconfig, TTL74160, "54/74160 Decade Counter", tag, owner, clock, "ttl74160", false, 10)
{
}

ttl74161_device::ttl74161_device(const machine_config &mconfig, const char *tag, device_t *owner, uint32_t clock)
	: ttl7416x_device(mconfig, TTL74160, "54/74160 Decade Counter", tag, owner, clock, "ttl74160", false, 16)
{
}

ttl74162_device::ttl74162_device(const machine_config &mconfig, const char *tag, device_t *owner, uint32_t clock)
	: ttl7416x_device(mconfig, TTL74160, "54/74160 Decade Counter", tag, owner, clock, "ttl74160", true, 10)
{
}

ttl74163_device::ttl74163_device(const machine_config &mconfig, const char *tag, device_t *owner, uint32_t clock)
	: ttl7416x_device(mconfig, TTL74160, "54/74160 Decade Counter", tag, owner, clock, "ttl74160", true, 16)
{
}

void ttl7416x_device::device_start()
{
	save_item(NAME(m_clear));
	save_item(NAME(m_pe));
	save_item(NAME(m_cet));
	save_item(NAME(m_cep));
	save_item(NAME(m_clock));
	save_item(NAME(m_p));
	save_item(NAME(m_out));
	save_item(NAME(m_tc));
	save_item(NAME(m_last_clock));
	save_item(NAME(m_last_out));
	save_item(NAME(m_last_tc));

	m_output_func.resolve_safe();
	m_tc_func.resolve_safe();
}

void ttl7416x_device::device_reset()
{
	init();
}

void ttl7416x_device::tick()
{
	if (m_synchronous_reset && m_clear)
	{
		init();
		return;
	}

	m_last_out = m_out;
	m_last_tc = m_tc;

	if (m_pe)
	{
		m_out = m_p & 0xf;
	}
	else
	{
		if (bool(m_cet) && bool(m_cep))
		{
			increment();
		}
	}

	if (m_out != m_last_out)
	{
		m_last_out = m_out;
		m_output_func(m_out);
	}

	if (m_tc != m_last_tc)
	{
		m_last_tc = m_tc;
		m_tc_func(m_tc);
	}
}

void ttl7416x_device::increment()
{
	m_out = (m_out + 1) % (m_limit + 1);

	if (m_out == m_limit)
		m_tc = 1;
	else
		m_tc = 0;
}

WRITE_LINE_MEMBER( ttl7416x_device::clear_w )
{
	m_clear = state;
	if (!m_synchronous_reset)
		init();
}


WRITE_LINE_MEMBER( ttl7416x_device::pe_w )
{
	m_pe = state;
}

WRITE_LINE_MEMBER( ttl7416x_device::cet_w )
{
	m_cet = state;
}

WRITE_LINE_MEMBER( ttl7416x_device::cep_w )
{
	m_cep = state;
}

WRITE_LINE_MEMBER( ttl7416x_device::clock_w )
{
	m_last_clock = m_clock;
	m_clock = state;
	if (m_clock != m_last_clock && m_clock != 0)
	{
		tick();
	}
}

READ_LINE_MEMBER( ttl7416x_device::output_r )
{
	return m_out;
}

READ_LINE_MEMBER( ttl7416x_device::tc_r )
{
	return m_tc;
}

void ttl7416x_device::init()
{
	m_clear = 0;
	m_pe = 1;
	m_cet = 0;
	m_cep = 0;
	m_clock = 0;
	m_p = 0;

	m_out = 0;
	m_tc = 0;

	m_last_out = 0;
	m_tc = 0;
}
