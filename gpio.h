//
//  gpio.h
//  
//
//  Created by Sean Slamka on 9/17/14.
//
//  Lab Partners: Sean Slamka, Aydin Balci

#ifndef ____gpio__
#define ____gpio__

//#include <iostream>
//#include "Token.h"

//Header file for gpio function
class gpio
{
typedef enum {
 gpio_data_dir_in = 0, // Configure pin in a DDR reg to be an Input pin
 gpio_data_dir_out = 1, // Configure pin in a DDR reg to be an Output pin
 gpio_data_dir_x = 2 // Don't care. Used when the pin is not being configured for the GPIO function
} gpio_data_dir_t;

typedef enum {
 gpio_funct_gpio = 0x00, // Configure a pin's function in the PAR register for the GPIO function
 gpio_funct_primary = 0x01, // Configure a pin's function in the PAR register for the Primary function
 gpio_funct_secondary = 0x02, // Configure a pin's function in the PAR register for the Secondary function
 gpio_funct_tertiary = 0x03 // Configure a pin's function in the PAR register for the Tertiary function
} gpio_funct_t;

typedef enum {
 gpio_pin_0 = 0, // Pin 0 of a GPIO port
 gpio_pin_1 = 1, // Pin 1 of a GPIO port
 gpio_pin_2 = 2, // Pin 2 of a GPIO port
 gpio_pin_3 = 3, // Pin 3 of a GPIO port
 gpio_pin_4 = 4, // Pin 4 of a GPIO port
 gpio_pin_5 = 5, // Pin 5 of a GPIO port
 gpio_pin_6 = 6, // Pin 6 of a GPIO port
 gpio_pin_7 = 7 // Pin 7 of a GPIO port
} gpio_pin_t;

typedef enum {
 gpio_pin_state_high = 1, // Configures pin's output state in a SET register to be High
 gpio_pin_state_low = 0, // Configures pin's output state in a SET register to be Low
 gpio_pin_state_x = 2 // Don't care. Used when the pin is not being configured for the GPIO function
} gpio_pin_state_t;

typedef enum {
 gpio_port_dd = 0x14, // Offset to the DD register from the beginning of a GPIO reg's address space
 gpio_port_tc = 0x0F, // Offset to the TC register from the beginning of a GPIO reg's address space
} gpio_port_t;


};

#endif /* defined(__gpio__) */
