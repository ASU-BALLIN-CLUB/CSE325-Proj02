//
//  gpio.c
//
//
//  Created by Sean Slamka on 9/17/14.
//
//  Lab Partners: Sean Slamka, Aydin Balci

#include "gpio.h"

static const uint32 GPIO_BASE = 0x40100000; // Base address of the GPIO module in the IPS
static const uint32 GPIO_DDR_BASE = GPIO_BASE + 0x18; // Base address of the DDR registers in the GPIO space
static const uint32 GPIO_SET_BASE = GPIO_BASE + 0x30; // Base address of the SET registers in the GPIO space
static const uint32 GPIO_CLR_BASE = GPIO_BASE + 0x48; // Base address of the CLR registers in the GPIO space
static const uint32 GPIO_PAR_BASE = GPIO_BASE + 0x60; // Base address of the PAR registers in the GPIO space
#define GPIO_SET(n) (*(vuint8 *)(GPIO_SET_BASE + (n))) // SET reg, n is GPIO_PORT_TC or GPIO_PORT_DD
#define GPIO_DDR(n) (*(vuint8 *)(GPIO_DDR_BASE + (n))) // DDR reg
#define GPIO_CLR(n) (*(vuint8 *)(GPIO_CLR_BASE + (n))) // CLR reg
#define GPIO_PAR(n) (*(vuint8 *)(GPIO_PAR_BASE + (n))) // PAR reg


void gpio_port_init(gpio_port_t p_port, gpio_pin_t p_pin, gpio_funct_t p_funct, gpio_data_dir_t p_data_dir,
 gpio_pin_state_t p_state)
 {

	 switch (p_port)
	 {
	 	case gpio_port_dd:
	 		GPIO_PAR(p-port) |= 0x0;
	 		GPIO_PAR(p_port)
	 		break;
	 	case gpio_port_tc:
	 		GPIO_PAR)p_port) |= 0x0;
	 		APIO_PAR(p_port)
	 		break;
	 	default:

	}