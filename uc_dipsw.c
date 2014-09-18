//
//  uc_dipsw.c
//
//
//  Created by Sean Slamka on 9/17/14.
//
//  Lab Partners: Sean Slamka, Aydin Balci

#include "uc_dipsw.h"

uc_dipsw_state_t uc_dipsw_get_state(uc_dipsw_t p_switch)
{
	 uc_dipsw_state_t state = gpio_port_get_pin_state(gpio_port_dd, p_switch);
	 return state;
}

void uc_dipsw_init()
{

	gpio_port_init(gpio_port_dd , gpio_pin_4, gpio_funct_gpio, gpio_data_dir_in, uc_dipsw_state_on);
	gpio_port_init(gpio_port_dd , gpio_pin_5, gpio_funct_gpio, gpio_data_dir_in, uc_dipsw_state_on);
	gpio_port_init(gpio_port_dd , gpio_pin_6, gpio_funct_gpio, gpio_data_dir_in, uc_dipsw_state_on);
	gpio_port_init(gpio_port_dd , gpio_pin_7, gpio_funct_gpio, gpio_data_dir_in, uc_dipsw_state_on);
}
