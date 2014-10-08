//
//  main.c
//
//	Proj02
//  Lab Partners: Sean Slamka, Aydin Balci
//  Email: sslamka@asu.edu, abalci@asu.edu
//  CSE325 Embedded Microprocessor Systems
//  Fall 2014
//

#include "support_common.h"
#include "gpio.h"
#include "uc_dipsw.h"
#include "uc_led.h"
#include "dtim.h"
static void count_up(uint32 p_delay);
static uint32 dipsw_delay_poll();
static void dipsw_onoff_poll();
static void hw_init();
static void leds_on(int const p_value);
__declspec(noreturn) int main();
static void run();

// Function to increment through the leds in binary, with often breaks and checks
// for the delay time as well as wether or not to pause.
static void count_up(uint32 p_delay)
{
	// Begins the count function and goes from value 1-16 by polling the dipswitches,
	// Checking for the delay, turning on leds, polling again, and repeating.
	int value;
	for(value = 0; value<16; value++)
	{
		 dipsw_onoff_poll();
		 p_delay = dipsw_delay_poll();
		 leds_on(value);
		 dipsw_onoff_poll();
		 p_delay = dipsw_delay_poll();
		 dtim_busy_delay_ms(dtim_0, p_delay);
		 dipsw_onoff_poll();
		 p_delay = dipsw_delay_poll();
		 uc_led_all_off();
		 dipsw_onoff_poll();
		 p_delay = dipsw_delay_poll();
		 dtim_busy_delay_ms(dtim_0, p_delay);
	 }
}

// This poll is used to check how long the delay needs to be depending on 
// which dipswitches are on or off.
static uint32 dipsw_delay_poll()
{
	// These states check each of the dipswitches.
	uint32 state1 = (uint32)uc_dipsw_get_state(uc_dipsw_2)*100;
	uint32 state2 = (uint32)uc_dipsw_get_state(uc_dipsw_3)*10;
	uint32 state3 = (uint32)uc_dipsw_get_state(uc_dipsw_4);
	uint32 state = state1 + state2 + state3;
	
	// Switch statement to catch all possible delay states.
	switch(state)
	{
		case 000:
			return 2000;
			break;
		case 421:
			return 1000;
			break;
		case 210:
			return 800;
			break;
		case 631:
			return 600;
			break;
		case 100:
			return 400;
			break;
		case 521:
			return 200;
			break;
		case 310:
			return 100;
			break;
		case 731:
			return 50;
			break;
		default:
			return 200;
			break;
	}
}

// The poll to tell wether or not to pause the blinking lights.
static void dipsw_onoff_poll()
{
		while(uc_dipsw_get_state(uc_dipsw_1) == 1 || uc_dipsw_get_state(uc_dipsw_1) == 3 || uc_dipsw_get_state(uc_dipsw_1) == 5 || uc_dipsw_get_state(uc_dipsw_1)==7 || uc_dipsw_get_state(uc_dipsw_1) == 9 || uc_dipsw_get_state(uc_dipsw_1) == 11 || uc_dipsw_get_state(uc_dipsw_1) == 13 || uc_dipsw_get_state(uc_dipsw_1) == 15)
		{
		}
}
// Initializes the dipswitches as well as the leds and timers.
static void hw_init()
{
	uc_dipsw_init();
	uc_led_init();
	dtim_init(dtim_0);
}
// A function to turn certain leds on.
static void leds_on(int const p_value)
{
	uc_led_on((gpio_pin_t)p_value);
}
// The main function.
__declspec(noreturn) int main()
{
	hw_init();
	run();
}
// Function to run the code.
static void run()
{
	uint32 delay = dipsw_delay_poll();
	while(1)
	{
		count_up(delay);
	}
}
