.extern bubble_thumb
.extern bubble_arm

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
	blx bubble_thumb
	nop
	blx bubble_arm



forever:
	nop
	b forever


.data
.align 4



// Normal Interrupt Service Routine
csd_irq:
	b .
