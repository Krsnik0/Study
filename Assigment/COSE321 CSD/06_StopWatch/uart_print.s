
.data
string:
	.ascii "Hello World!"
	.byte 0x00
.text

.macro uart_print

	bl uart_trans

.endm


#include "uart_regs.h"

uart_trans:

//////////////////////////////////////////////
//       아래에 오류 발생 시 clean project  //
//////////////////////////////////////////////

	ldr 	r3, =UART1_BASE
	//ldr 	r4, =string

	//r4: print variable
	mov		r6, r5	//r6: second
	mov		r7, #0	//r7: minute
	mov		r8, #0	//r8: hour

hour:
	cmp		r6, #3600
	subge	r6, r6, #3600
	addge	r8, r8, #1
	bge		hour
min:
	cmp		r6, #60
	subge	r6, r6, #60
	addge	r7, r7, #1
	bge		min

	//move cursor(carriage return)
	mov		r4, #0xD
	strb	r4, [r3, #UART_TX_RX_FIFO0_OFFSET]	//print uart with TxFIFO
	mov		r4, #0

printHour:
	cmp		r8, #10
	addge	r4, r4, #1
	subge	r8, r8, #10	//check 10's digit
	bge		printHour

	add		r4, r4, #0x30	//'0' = 0x30
	strb	r4, [r3, #UART_TX_RX_FIFO0_OFFSET]
	add		r8, r8, #0x30
	strb	r8, [r3, #UART_TX_RX_FIFO0_OFFSET]
	mov		r4, #0x3A		//':' = 0x3A
	strb	r4, [r3, #UART_TX_RX_FIFO0_OFFSET]
	mov		r4, #0

printMin:
	cmp		r7, #10
	addge	r4, r4, #1
	subge	r7, r7, #10	//check 10's digit
	bge		printMin

	add		r4, r4, #0x30	//'0' = 0x30
	strb	r4, [r3, #UART_TX_RX_FIFO0_OFFSET]
	add		r7, r7, #0x30
	strb	r7, [r3, #UART_TX_RX_FIFO0_OFFSET]
	mov		r4, #0x3A		//':' = 0x3A
	strb	r4, [r3, #UART_TX_RX_FIFO0_OFFSET]
	mov		r4, #0

printSec:
	cmp		r6, #10
	addge	r4, r4, #1
	subge	r6, r6, #10	//check 10's digit
	bge		printSec

	add		r4, r4, #0x30	//'0' = 0x30
	strb	r4, [r3, #UART_TX_RX_FIFO0_OFFSET]
	add		r6, r6, #0x30
	strb	r6, [r3, #UART_TX_RX_FIFO0_OFFSET]
	mov		r4, #0

	mov		pc, lr				@    return to the caller
