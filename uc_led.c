//
//  uc_led.c
//
//
//  Created by Sean Slamka on 9/17/14.
//
//  Lab Partners: Sean Slamka, Aydin Balci

#include "uc_led.h"

void uc_led_all_off()
{
	 uc_led_off(uc_led_1);
	 uc_led_off(uc_led_2);
	 uc_led_off(uc_led_3);
	 uc_led_off(uc_led_4);
}

void uc_led_all_on()
{
	uc_led_on(uc_led_1);
	uc_led_on(uc_led_2);
	uc_led_on(uc_led_3);
	uc_led_on(uc_led_4);
}

void uc_led_init()
{
	 gpio_port_init(gpio_port_tc , gpio_pin_0, gpio_funct_gpio, gpio_data_dir_out, gpio_pin_state_low);
	 gpio_port_init(gpio_port_tc , gpio_pin_1, gpio_funct_gpio, gpio_data_dir_out, gpio_pin_state_low);
	 gpio_port_init(gpio_port_tc , gpio_pin_2, gpio_funct_gpio, gpio_data_dir_out, gpio_pin_state_low);
	 gpio_port_init(gpio_port_tc , gpio_pin_3, gpio_funct_gpio, gpio_data_dir_out, gpio_pin_state_low);
}

void uc_led_off(int p_led)
{
	gpio_port_set_pin_state(gpio_port_tc, p_led, gpio_pin_state_low);
}

void uc_led_on(int p_led)
{
	gpio_port_set_pin_state(gpio_port_tc, p_led, gpio_pin_state_high);

}

void uc_led_toggle(int p_led)
{
	 gpio_port_get_pin_state(gpio_port_tc, p_led);
}
