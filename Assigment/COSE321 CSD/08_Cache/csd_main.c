/*
 * csd_main.c
 *
 *  Created on: 2018. 4. 30.
 *      Author: Taeweon Suh
 */

unsigned volatile char * gpio_led = (unsigned char *) 0x41200000;
unsigned volatile char * gpio_switch = (unsigned char *) 0x41210000;

int csd_main()
{

 int count;

	for (count=0; count < 0x400000; count++) ;

	*gpio_led = 0xC3;

	for (count=0; count < 0x400000; count++) ;

	*gpio_led = 0x3C;

	return 0;
}

int csd_switch(){
	int switch_status = *gpio_switch;
	if(switch_status%2 == 1){		// 0th switch on
		return 1;			//cache enable
	}else{					// 0th switch off
		return 0;			// cache disable
	}

}
