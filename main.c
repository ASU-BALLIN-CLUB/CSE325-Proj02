//
//  main.c
//	Proj02
//
//  Created by Sean Slamka on 9/17/14.
//
//  Lab Partners: Sean Slamka, Aydin Balci

#include "support_common.h"
#include "gpio.h"
#include "uc_dipsw.h"
#include "uc_led.h"

static void count_up(int p_delay)
{
	int value;
	for(value=0, i<16, i++)
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
		 dtim_busy_delay_ms(dtim_0, p_delay)
	 }

}
static int dipsw_delay_poll()
{
	int state1 = uc_dipsw_get_state(5)*100;
	int state2 = uc_dipsw_get_state(6)*10;
	int state3 = uc_dipsw_get_state(7);
	int state = state1 + state2 + state3;
	switch(state)
	{
		case 000:
			dtim_busy_delay_ms(dtim_0, 2000);
			return 2000;
			break;
		case 001:
			dtim_busy_delay_ms(dtim_0, 1000);
			return 1000;
			break;
		case 010:
			dtim_busy_delay_ms(dtim_0, 800);
			return 800;
			break;
		case 011:
			dtim_busy_delay_ms(dtim_0, 600);
			return 600;
			break;
		case 100:
			dtim_busy_delay_ms(dtim_0, 400);
			return 400;
			break;
		case 101:
			dtim_busy_delay_ms(dtim_0, 200);
			return 200;
			break;
		case 110:
			dtim_busy_delay_ms(dtim_0, 100);
			return 100;
			break;
		case 111:
			dtim_busy_delay_ms(dtim_0, 50);
			return 50;
			break;
		default:

			break;
	}

}
static void dipsw_onoff_poll()
{
		while(uc_dipsw_get_state(4) == gpio_pin_state_high)
		{
		}
}
static void hw_init()
{
	uc_dipsw_init();
	uc_led_init();
	dtim_init(dtim_0);
}
static void leds_on(int const p_value)
{

	uc_led_on(p_value);
	switch(p_value)
	{
			case 0:
				break;
			case 1:
				uc_led_on(uc_led_1);
				break;
			case 2:
				uc_led_on(uc_led_2);
				break;
			case 3:
				uc_led_on(uc_led_1);
				uc_led_on(uc_led_2);
				break;
			case 4:
				uc_led_on(uc_led_3);
				break;
			case 5:
				uc_led_on(uc_led_1);
				uc_led_on(uc_led_3);
				break;
			case 6:
				uc_led_on(uc_led_2);
				uc_led_on(uc_led_3);
				break
			case 7:
				uc_led_on(uc_led_1);
				uc_led_on(uc_led_2);
				uc_led_on(uc_led_3);
				break;
			case 8:
				uc_led_on(uc_led_4);
				break;
			case 9:
				uc_led_on(uc_led_1);
				uc_led_on(uc_led_4);
				break;
			case 10:
				uc_led_on(uc_led_2);
				uc_led_on(uc_led_4);
				break;
			case 11:
				uc_led_on(uc_led_1);
				uc_led_on(uc_led_2);
				uc_led_on(uc_led_4);
				break;
			case 12:
				uc_led_on(uc_led_3);
				uc_led_on(uc_led_4);
				break;
			case 13:
				uc_led_on(uc_led_1);
				uc_led_on(uc_led_3);
				uc_led_on(uc_led_4);
				break;
			case 14:
				uc_led_on(uc_led_2);
				uc_led_on(uc_led_3);
				uc_led_on(uc_led_4);
				break;
			case 15:
			    uc_led_on(uc_led_1);
				uc_led_on(uc_led_2);
				uc_led_on(uc_led_3);
				uc_led_on(uc_led_4);
				break;
			default:
				break;
}
__declspec(noreturn) int main()
{
	hw_init();
	run();
}
static void run()
{
	int delay = dipsw_delay_poll();
	while(1)
	{
		count_up(delay);
	}
}


