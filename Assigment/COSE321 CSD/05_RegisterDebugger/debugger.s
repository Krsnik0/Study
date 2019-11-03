.data
string:
	.ascii "-----------------------------------------------------------------------\n\r"
	.ascii "r0  = 0x\0"
	.ascii ", r1  = 0x\0"
	.ascii ", r2  = 0x\0"
	.ascii ", r3  = 0x\0"
	.ascii "\n\rr4  = 0x\0"
	.ascii ", r5  = 0x\0"
	.ascii ", r6  = 0x\0"
	.ascii ", r7  = 0x\0"
	.ascii "\n\rr8  = 0x\0"
	.ascii ", r9  = 0x\0"
	.ascii ", r10 = 0x\0"
	.ascii ", r11 = 0x\0"
	.ascii "\n\rr12 = 0x\0"
	.ascii ", r13 = 0x\0"
	.ascii ", r14 = 0x\0"
	.ascii ", r15 = 0x\0"
	.ascii "\n\rcpsr = \0, \0, \0 mode, current mode = \0 ( =0x\0"
	.ascii ")"
	.ascii "\n\r-----------------------------------------------------------------------\n\r\0"

stat_ARM:
	.ascii "ARM\0"
stat_Thumb:
	.ascii "Thumb\0"
stat_Jazelle:
	.ascii "Jazelle\0"
stat_ThumbEE:
	.ascii "ThumbEE\0"

mode_usr:
	.ascii "USR\0"
mode_fiq:
	.ascii "FIQ\0"
mode_irq:
	.ascii "IRQ\0"
mode_svc:
	.ascii "SVC\0"
mode_mon:
	.ascii "MON\0"
mode_abt:
	.ascii "ABT\0"
mode_hyp:
	.ascii "HYP\0"
mode_und:
	.ascii "UND\0"
mode_sys:
	.ascii "SYS\0"

.text


#include "uart_regs.h"


.macro debugger

	bl debugger_m

.endm

debugger_m:

	stmdb 	r13!, {r0-r15}		//push reg 0~15

	add 	r13, r13, #68		//stack image: {r0, r1, ... r15, cpsr}
	mrs r0, CPSR_all			//fix sp(+68), and save cpsr temporary in r0
	stmdb 	r13!, {r0}			//push r0
	sub 	r13, r13, #64		//make r13 point r0(r13 - 64)
								//Note) exact sp should plus 64, pc should minus 8


//	r0:		UART1_BASE
//	r1:		string(menu)
//	r2:		Channel Status Register
// 	r3:		store reg from stack_pop
//	r4:		each bit of r4. Output.
//	r5:		judge each bit of r3(F0000000~0000000F)
//	r6:		counter of chk_reg(loop of printing 'each' reg)
//	r7:		counter of ror
//	r8:
//	r10:	counter to print reg

	ldr 	r0, =UART1_BASE
	ldr 	r1, =string

	mov		r10, #16		//counter to print reg
print_reg:
	bl		print_menu		//print menu
	//use reg r3 to pop regs
	ldmia	r13!, {r3}

	cmp		r10, #3		//if r13
	bleq	printR13

	cmp		r10, #1		//if r15
	bleq	printR15


	ldr		r5, =0xF0000000		//chk position of reg
	mov		r6, #8		//counter
	mov		r7, #28		//ror const
chk_reg:

	and		r4, r3, r5		//r4 is lsb - let call it is 1st bit
	ror		r4, r7			//and i'll print r4

	cmp		r4, #9
	addle	r4, r4, #48		//if r4 is number(0~9), r7 = r7 + '0'
	addgt	r4, r4, #87		//if r4 is character(A~F),  r7 = r7 + 'a'

print_loop:
	// ---------  Check to see if the Tx FIFO is empty ------------------------------
	ldr		r2, [r0, #UART_CHANNEL_STS_REG0_OFFSET]	@ get Channel Status Register
	and		r2, r2, #0x8		@ get Transmit Buffer Empty bit(bit[3:3])
	cmp		r2, #0x8				@ check if TxFIFO is empty and ready to receive new data
	bne		print_loop		@ if TxFIFO is NOT empty, keep checking until it is empty
	//------------------------------------------------------------------------------

	strb	r4, [r0, #UART_TX_RX_FIFO0_OFFSET]	//print with TxRxFIFO

	ror 	r5, #4
	sub		r7, #4
	subs	r6, r6, #1
	bne		chk_reg

	subs	r10, r10, #1
	bne		print_reg
//Complete printing reg


//print last line(CPSR)
	bl		print_menu		//print menu('/n/rcpsr=' part)
	ldmia	r13!, {r11}		//pop CPSR

//nzcv
	and		r4, r11, #0x80000000  //31th bit, N
	cmp 	r4, #0
	moveq 	r4, #0x6E		//n = 0x6E
	movne 	r4, #0x4E		//N = 0x4E
	strb	r4, [r0, #UART_TX_RX_FIFO0_OFFSET]

	and 	r4, r11, #0x40000000  //30th bit, Z
	cmp 	r4, #0
	moveq 	r4, #0x7A		//z = 0x7A
	movne 	r4, #0x5A		//Z = 0x5A
	strb	r4, [r0, #UART_TX_RX_FIFO0_OFFSET]

	and 	r4, r11, #0x20000000  //30th bit, C
	cmp 	r4, #0
	moveq 	r4, #0x63		//c = 0x63
	movne 	r4, #0x43		//C = 0x43
	strb	r4, [r0, #UART_TX_RX_FIFO0_OFFSET]

	and 	r4, r11, #0x10000000  //30th bit, V
	cmp 	r4, #0
	moveq 	r4, #0x76		//v = 0x76
	movne 	r4, #0x56		//V = 0x56
	strb	r4, [r0, #UART_TX_RX_FIFO0_OFFSET]

	bl		print_menu		//print menu(', ')

//if
	and		r4, r11, #0x100  //8th bit, A
	cmp		r4, #0
	movne 	r4, #0x41		//A = 0x41
	strb	r4, [r0, #UART_TX_RX_FIFO0_OFFSET]

	and		r4, r11, #0x80  //7th bit, I
	cmp		r4, #0
	movne 	r4, #0x49		//I = 0x49
	strb	r4, [r0, #UART_TX_RX_FIFO0_OFFSET]

	and		r4, r11, #0x40  //6th bit, F
	cmp		r4, #0
	movne 	r4, #0x46		//A = 0x46
	strb	r4, [r0, #UART_TX_RX_FIFO0_OFFSET]

	bl		print_menu		//print menu(', ')

//mode

	and		r4, r11, #0x1000000	//24th bit, J
	cmp		r4, #0
	beq 	jOff
	bne		jOn
jOff:
	and		r4, r11, #0x20  		//5th bit, T
	cmp 	r4, #0
	ldrne 	r4, =stat_Thumb		//JT = 01: Thumb
	ldreq 	r4, =stat_ARM		//JT = 00: ARM
	bl 		chk_FIFO
	b 		jContinue
jOn:
	and		r4, r11, #0x20  		//5th bit, T
	cmp 	r4, #0
	ldrne 	r4, =stat_ThumbEE	//JT = 11: ThumbEE
	ldreq 	r11, =stat_Jazelle	//JT = 10: Jazelle
	bl 		chk_FIFO
	b		jContinue
jContinue:
	bl		print_menu		//print ('mode, current mode =')

//current mode

	and 	r4, r11, #0x1F		//last 5 bits, M[4:0]
	cmp		r4, #0x10			//10000: User
	ldreq	r4, =mode_usr
	bleq	chk_FIFO

	and 	r4, r11, #0x1F		//last 5 bits, M[4:0]
	cmp		r4, #0x11			//10001: FIQ
	ldreq	r4, =mode_fiq
	bleq	chk_FIFO

	and 	r4, r11, #0x1F		//last 5 bits, M[4:0]
	cmp		r4, #0x12			//10010: IRQ
	ldreq	r4, =mode_irq
	bleq	chk_FIFO

	and 	r4, r11, #0x1F		//last 5 bits, M[4:0]
	cmp		r4, #0x13			//10011: Supervisor
	ldreq	r4, =mode_svc
	bleq	chk_FIFO

	and 	r4, r11, #0x1F		//last 5 bits, M[4:0]
	cmp		r4, #0x16			//10110: Monitor
	ldreq	r4, =mode_mon
	bleq	chk_FIFO

	and 	r4, r11, #0x1F		//last 5 bits, M[4:0]
	cmp		r4, #0x17			//10111: Abort
	ldreq	r4, =mode_abt
	bleq	chk_FIFO

	and 	r4, r11, #0x1F		//last 5 bits, M[4:0]
	cmp		r4, #0x1A			//11010: Hyp
	ldreq	r4, =mode_hyp
	bleq	chk_FIFO

	and 	r4, r11, #0x1F		//last 5 bits, M[4:0]
	cmp		r4, #0x1B			//11011: Undefined
	ldreq	r4, =mode_und
	bleq	chk_FIFO

	and 	r4, r11, #0x1F		//last 5 bits, M[4:0]
	cmp		r4, #0x1F			//11111: System
	ldreq	r4, =mode_sys
	bleq	chk_FIFO

	bl		print_menu			//print (' ( =0x')

	ldr		r5, =0xF0000000		//chk position of reg
	mov		r6, #8		//counter
	mov		r7, #28		//ror const
chk_reg2:

	and		r4, r11, r5		//r4 is lsb - let call it is 1st bit
	ror		r4, r7			//and i'll print r4

	cmp		r4, #9
	addle	r4, r4, #48		//if r4 is number(0~9), r7 = r7 + '0'
	addgt	r4, r4, #87		//if r4 is character(A~F),  r7 = r7 + 'a'

print_loop2:
	// ---------  Check to see if the Tx FIFO is empty ------------------------------
	ldr		r2, [r0, #UART_CHANNEL_STS_REG0_OFFSET]	@ get Channel Status Register
	and		r2, r2, #0x8		@ get Transmit Buffer Empty bit(bit[3:3])
	cmp		r2, #0x8				@ check if TxFIFO is empty and ready to receive new data
	bne		print_loop2		@ if TxFIFO is NOT empty, keep checking until it is empty
	//------------------------------------------------------------------------------

	strb	r4, [r0, #UART_TX_RX_FIFO0_OFFSET]	//print with TxRxFIFO

	ror 	r5, #4
	sub		r7, #4
	subs	r6, r6, #1
	bne		chk_reg2

	bl		print_menu			//print last highlight

	sub 	r13, r13, #12
	ldmia 	r13!, {r10}			//lr
	mov		lr, r10
	add		r13, r13, #4
	ldmia 	r13!, {r10}			//cpsr
	msr		CPSR_all, r10

	sub		r13, r13, #68		//return sp to r0
	ldmia 	r13!, {r0-r12}
	add		r13, r13, #12

	mov 	pc, lr		//return to csd_main


//subroutines

printR13:
	add		r3, r3, #64		//edit reg to print EXACT value
	mov		pc, lr		//return to print_reg
//edit r13(sp)

printR15:
	sub		r3, r3, #8		//edit reg to print EXACT value
	mov		pc, lr		//return to print_reg
//edit r15(pc)

print_menu:
	// ---------  Check to see if the Tx FIFO is empty ------------------------------
	ldr		r2, [r0, #UART_CHANNEL_STS_REG0_OFFSET]	@ get Channel Status Register
	and		r2, r2, #0x8		@ get Transmit Buffer Empty bit(bit[3:3])
	cmp		r2, #0x8				@ check if TxFIFO is empty and ready to receive new data
	bne		print_menu		@ if TxFIFO is NOT empty, keep checking until it is empty
	//------------------------------------------------------------------------------

	ldrb    r3, [r1], #1
	strb	r3, [r0, #UART_TX_RX_FIFO0_OFFSET]	@ fill the TxFIFO with 0x48
	cmp		r3, #0x00
	bne		print_menu
	mov		pc, lr		//return to above

chk_FIFO:

	// ---------  Check to see if the Tx FIFO is empty ------------------------------
	ldr 	r2, [r0, #UART_CHANNEL_STS_REG0_OFFSET]	@ get Channel Status Register
	and		r2, r2, #0x8		@ get Transmit Buffer Empty bit(bit[3:3])
	cmp		r2, #0x8				@ check if TxFIFO is empty and ready to receive new data
	bne		chk_FIFO		@ if TxFIFO is NOT empty, keep checking until it is empty
	//------------------------------------------------------------------------------

	ldrb    r8, [r4], #1
	strb	r8, [r0, #UART_TX_RX_FIFO0_OFFSET]	@ fill the TxFIFO with 0x48
	cmp     r8, #0x00
	bne		chk_FIFO

	mov		pc, lr
