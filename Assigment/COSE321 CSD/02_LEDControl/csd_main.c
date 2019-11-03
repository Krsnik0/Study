#include <stdio.h>
#include <unistd.h>
#include <time.h>
int csd_main(int sw){
	if(sw >= 0b10000000)
		usleep(100*1000);
	else if(sw >= 0b1000000)
		usleep(200*1000);
	else if(sw >= 0b100000)
		usleep(300*1000);
	else if(sw >= 0b10000)
		usleep(400*1000);
	else if(sw >= 0b1000)
		usleep(500*1000);
	else if(sw >= 0b100)
		usleep(600*1000);
	else if(sw >= 0b10)
		usleep(700*1000);
	else if(sw >= 0b1)
		usleep(800*1000);
	else
		usleep(1000*1000);
	return 0;
}
