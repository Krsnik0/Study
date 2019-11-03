#define csd_LED_ADDR	0x41200000
#define LED_CONST		0x01010101

#include "uart_init.s"
#include "uart_print.s"


.extern csd_main

.align 8

// Our interrupt vector table
csd_entry:
	b csd_reset
	b .
	b .
	b .
	b .
	b .
	b csd_irq
	b .

.global main
csd_reset:
main:
	uart_init
	uart_print

	ldr r0,	=slcr_UART_RST_CTRL
	ldr r1, =0x0	//	reset UART
	str r1, [r0]

	ldr r0, =slcr_UART_CLK_CTRL
	ldr r1, =0x1402	// divisor = 0x14 (ref clk = 50MHz), srcsel = 0, CLKACT1 = true, CLKACT0 = false
	str r1, [r0]

	ldr r0, =uart_mode_reg0
	ldr r1, =0x20
	str r1, [r0]

	ldr r0, =uart_Control_reg0
	ldr r1, =0x28	//uart off
	str r1, [r0]

	ldr r0, =uart_Baud_rate_gen_reg0
	ldr r1, =0x3e
	str r1, [r0]

	ldr r0, =uart_Baud_rate_divider_reg0
	ldr r1, =0x6
	str r1, [r0]

	ldr r0, =uart_Control_reg0
	ldr r1, =0x00000117	//uart start
	str r1, [r0]

	ldr r0, =uart_Modem_ctrl_reg0
	ldr r1, [r0]

	ldr r0, =uart_Modem_sts_reg0
	ldr r1, [r0]



	ldr r0, =uart_TX_RX_FIFO0
	ldr r1, =uart_Channel_sts_reg0

	ldr r5, =csd_LED_ADDR
	ldr r6, =LED_CONST

recvloop:
	ldr r0, =#0xff
	str r6, [r5]
	ROR r6, #31
	// control led
	bl csd_main	// call main

	b recvloop

/*
	mov r0, #10
	mov r1, #3
	add r0, r0, r1

	ldr r0, =src
	ldr r1, =dst
	mov r2, #16

loop:
	ldr r3, [r0], #4   // load a word into r3 and upate r0 (= r0 + 4)
	str r3, [r1], #4   // store the word to memory and upate r1 (= r1 + 4)
	subs r2, r2, #1
	bne  loop

 	ldr r0, =csd_LED_ADDR
	mov r1, #0x5
	str r1, [r0]

	bl csd_main


	uart_init

	bl uart_trans
*/

forever:
	nop
	b forever


.data
.align 4

src:
	.word  1,  2,  3,  4,  5,  6,  7,  8
	.word 11, 12, 13, 14, 15, 16, 17, 18

dst:
	.space 16  // allocate memory for 16 words


// Normal Interrupt Service Routine
csd_irq:
	b .
