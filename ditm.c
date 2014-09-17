//
//  dtim.c
//
//
//  Created by Sean Slamka on 9/17/14.
//
//  Lab Partners: Sean Slamka, Aydin Balci


#include dtim.h
//#include "Token.h"

// The base address in the peripheral register range of the DTIM module registers.
static uint32 const DTIM_BASE = 0x40000400;
// The addresses of the DTIM registers for timers n = 0, 1, 2, and 3.
#define DTIM_DTCN(timer) *(volatile uint32 *) (DTIM_BASE + 0x0C + ((timer) << 6))
#define DTIM_DTCR(timer) *(volatile uint32 *) (DTIM_BASE + 0x08 + ((timer) << 6))
#define DTIM_DTER(timer) *(volatile uint8 *) (DTIM_BASE + 0x03 + ((timer) << 6))
#define DTIM_DTMR(timer) *(volatile uint16 *) (DTIM_BASE + 0x00 + ((timer) << 6))
#define DTIM_DTRR(timer) *(volatile uint32 *) (DTIM_BASE + 0x04 + ((timer) << 6))
#define DTIM_DTXMR(timer) *(volatile uint8 *) (DTIM_BASE + 0x02 + ((timer) << 6))

void dtim_busy_delay_ms(dtim_t const p_timer, int const p_msecs)
{
}
void dtim_busy_delay_us(dtim_t const p_timer, int const p_usecs)
{
}
void dtim_init(dtim_t const p_timer)
{
}
