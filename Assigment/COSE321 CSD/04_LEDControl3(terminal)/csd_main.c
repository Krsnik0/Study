#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include "uart_regs.h"
#define csd_LED_ADDR	0x41200000

//set address of status reg and TxRxFIFO
int *CSG = UART1_BASE + UART_CHANNEL_STS_REG0_OFFSET;
int *TRF = UART1_BASE + UART_TX_RX_FIFO0_OFFSET;

char* Txt[2] = {"----------------- LED On Duration ----------------\n\
			\r1. 100ms 2. 200ms 3. 300ms 4. 400 ms\n\
			\r5. 500ms 6. 600ms 7. 700ms 8. 1 sec\n\
			\r---------------------------------------------------\n\
			\rSelect: ",
			"Please select Integer between 1~8\n\r"};

int timeNow = 8;
int bIndex = -1;			// initialize index of buffer

void printScreen(int index){
	char* screen = '\0';	// reset in NULL
	screen = Txt[index];	// 0 -> menu, 1 -> error message
	int tmp = 0;
	int tEmpty = 0;
	while(screen[tmp] != '\0'){
		do{
			tEmpty = *CSG;
			tEmpty &= 0x8;	// check TEMPTY. if TEMPTY is 1, exit
		}while(tEmpty == 0);
		*TRF = screen[tmp++];
	}
}

int csd_main(int sw){
	int rEmpty = *CSG & 0x2;
	int input;
	int buffer[100];

	while(rEmpty == 0){
		input = *TRF;		// get input
		*TRF = input;		// print input
		buffer[++bIndex] = input;
		if(buffer[bIndex] == 13){
			*TRF = 10;		// if input is 5, buffer would be ['5', 13, '0',...]
			if(bIndex == 1){
				if('8' >= buffer[0] && buffer[0] >= '1'){
					timeNow = buffer[0]-'0';
					printScreen(0);
				}
				else{
					printScreen(1);
				}
			}
			else{
				printScreen(1);
			}
			bIndex = -1;	//reset index
		}
		else if(buffer[bIndex] == 0)
			bIndex = -1;	//reset index
			break;
	}

	if(timeNow == 8)		// make delay
		usleep(1000000);
	else
		usleep(timeNow * 100000);

	return 0;
}
