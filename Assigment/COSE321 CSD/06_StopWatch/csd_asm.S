#include "csd_zynq_peripherals.h"
#include "uart_print.s"
#include "uart_regs.h"
#include "uart_init.s"


#define csd_LED_ADDR	0x41200000
#define TIMER_INITIAL	333333332
#define LED_CONST		0x01010101


.global main
main:
 
	// --------------------------------------
	//  To distribute the learning burden. 
	// -- stack is NOT used in private timer code
	// -- stack will be used in the interrupt code
	// --------------------------------------

	// -----------------
   // Stack setup begin
	// -----------------

	mrs	r0, cpsr			/* get the current PSR */
	mvn	r1, #0x1f		/* To mask out the MODE bits (M[4:0]) in CPSR */
	and	r2, r1, r0
	orr	r2, r2, #0x12	/* IRQ mode */
	msr	cpsr, r2
	ldr	r13,=irq_stack_top	/* IRQ stack pointer */

	mrs	r0, cpsr			/* get the current PSR */
	mvn	r1, #0x1f		/* To mask out the MODE bits (M[4:0]) in CPSR */
	and	r2, r1, r0
	orr	r2, r2, #0x13	/* Supervisor mode */
	msr	cpsr, r2
	ldr	r13,=svc_stack_top	/* Supervisor stack pointer */

	mrs	r0, cpsr			/* get the current PSR */
	mvn	r1, #0x1f		/* To mask out the MODE bits (M[4:0]) in CPSR */
	and	r2, r1, r0
	orr	r2, r2, #0x11	/* FIQ mode */
	msr	cpsr, r2
	ldr	r13,=fiq_stack_top	/* FIQ stack pointer */

	mrs	r0, cpsr			/* get the current PSR */
	mvn	r1, #0x1f		/* To mask out the MODE bits (M[4:0]) in CPSR */		
	and	r2, r1, r0
	orr	r2, r2, #0x1F	/* SYS mode */
	msr	cpsr, r2

	// ---------------
   // Stack setup end
	// ---------------

 	// Private Timer Load Register
	ldr r0, =PRIVATE_LOAD
 	ldr r1, =TIMER_INITIAL
 	str r1, [r0]

 	// Private Timer Control Register
  	ldr r0, =PRIVATE_CONTROL
 	mov r1, #0 << 8   // Prescalar
 	orr r1, r1, #7     // IRQ Enable, Auto-Reload, Timer Enable
 	str r1, [r0]

	uart_init	//initialize UART

  	ldr r0, =PRIVATE_COUNTER
  	ldr r1, =PRIVATE_STATUS

	// Turn on LEDs just for testing
 	ldr  r10, =csd_LED_ADDR
	ldr  r11, =LED_CONST
	strb r11, [r10]

	mov		r5, #0	//second(start from 0)
	mov		r9, #0
forever:

  	ldr		r2, [r1]

	// Toggle LEDs if count is equal to 0 (r2)
	cmp		r2, #1
	mrs		r9, CPSR_all
	stmdb	r13!, {r9}
	bleq	uart_trans
	ldmia	r13!, {r9}
	msr		CPSR_all, r9
	addeq	r5, #1
	roreq	r11, #31
	streqb r11, [r10]

	//eoreq  r11, r11, #0xFF
	//streqb r11, [r10]
	moveq  r12, #1
	streq  r12, [r1] // to clear sticky bit in the status register

  	b forever


.data
.align 4

irq_stack:     .space 1024
irq_stack_top:
fiq_stack:     .space 1024
fiq_stack_top:
svc_stack:     .space 1024
svc_stack_top:
