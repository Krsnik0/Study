
#define csd_LED_ADDR	0x41200000
#define csd_SW_ADDR		0x41210000
#define LED_CONST		0x01010101

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
 	ldr r5, =csd_LED_ADDR
	ldr r6, =LED_CONST
infinite:
	ldr r0, =csd_SW_ADDR
	ldr r0, [r0]
	str r6, [r5]
	ROR r6, #31
	bl csd_main
	b infinite

forever:
	nop
	b forever


.data
.align 4


// Normal Interrupt Service Routine
csd_irq:
	b .
