
#include "csd_zynq_peripherals.h"
#include "uart_init.s"

#define TIMER_INITIAL	30000000

.extern task1_c,task2_c,task3_c

.align 8

csd_entry:
	b csd_reset
	b csd_undefined
	b csd_software_interrupt
	b csd_prefetch
	b csd_data
	b csd_not_used
	b csd_irq
	b csd_fiq

.global main
csd_reset:
main:
	//turn to SVC mode(10011)
	mrs r0, cpsr
	bic r0, #0x1F
	orr r0, #0x13
	msr cpsr, r0

	// Disable interrupt: Turn on I bit in CPSR
    cpsID i

	cps #0x12	   	       /* IRQ mode */
	ldr	r13,=irq_stack_top /* stack pointer setup for IRQ mode */

	cps #0x13		       /* supervisor mode */
	ldr	r13,=svc_stack_top /* stack pointer setup for SVC mode */

    cps #0x11		       /* FIQ mode */
	ldr	r13,=fiq_stack_top /* stack pointer setup for FIQ mode */

	cps #0x1F	           /* SYS mode */

	// Set VBAR (Vector Base Address Register) to the base of my interrupt vector table
    ldr     r0, =csd_entry
    mcr     p15, 0, r0, c12, c0, 0
    dsb
    isb

	// Enable interrupt: Turn off I bit in CPSR
    cpsIE i

// ---------------------------
// Generic Interrupt Controller (GIC) setup - Begin
//

	// CPU Interface ID Register
	ldr r0, =GICC_IIDR
	ldr r3, [r0]

	// CPU Controller Type Register
	ldr r0, =GICD_TYPER
	ldr r3, [r0]

	// CPU Binary Pointer Register
	ldr r0, =GICC_BPR
	ldr r3, [r0]

	// Distributor Control Register
	ldr r0, =GICD_CTLR
	ldr r1, [r0]
	mov r2, #1       // Enable
	orr r1, r1, r2
	str r1, [r0]
	ldr r3, [r0]

	 // Interrupt Set-Enable Register 0
	ldr r0, =GICD_ISENABLER0
	ldr r1, [r0]
	mov r2, #1 << 29   // Enable #29 (Private Timer)
	orr r1, r1, r2
	str r1, [r0]
	ldr r3, [r0]

	// Interrupt Priority Register #7
	// According to specifications, 
	// Cortex-A9 supports 5-bit version of priority format [7:3] in secure world
	// ( 0 -> 8 -> 16 -> 24...)
	ldr r0, =GICD_PRIOR7
	ldr r1, [r0]
	mov r2, #0x10 << 8    // Priority 16 for ID# 29 (Private Timer)
	orr r1, r1, r2
	str r1, [r0]
	ldr r3, [r0]

	// CPU Interface Control Register
	ldr r0, =GICC_CTLR
	ldr r1, [r0]
	mov r2, #1        // Enable
	orr r1, r1, r2
	str r1, [r0]
	ldr r3, [r0]

 	// CPU Interface Interrupt Priority Mask Register
	ldr r0, =GICC_PMR
	ldr r1, [r0]
	mov r2, #0xFF     // Lowest
	orr r1, r1, r2
	str r1, [r0]
	ldr r3, [r0]

//
// Generic Interrupt Controller (GIC) setup - End
// ---------------------------


// ---------------------------
// Private Timer setup - Begin
//

 	// Private Timer Load Register
	ldr r0, =PRIVATE_LOAD
 	ldr r1, =TIMER_INITIAL
 	str r1, [r0]

 	// Private Timer Control Register
  	ldr r0, =PRIVATE_CONTROL
 	mov r1, #10 << 8   // Prescalar
 	orr r1, r1, #7     // IRQ Enable, Auto-Reload, Timer Enable
 	str r1, [r0]

//
// Private Timer setup - End
// ----------------------------

	uart_init	//uart initializing

 	ldr r0, =context_now
	mov r1, #1
	str r1,[r0]

	ldr r0, =PCB_1_top		//data that check this process is started
	str r1, [r0, #-4]	//not start = 0, start = 1
	mov r1, #0
	ldr r0, =PCB_2_top
	str r1, [r0, #-4]
	ldr r0, =PCB_3_top
	str r1, [r0, #-4]
	
	//turn to User mode(10000)
	mrs r0, cpsr
	bic r0, #0x1F
	orr r0, #0x10
	msr cpsr, r0

	b task1_c

forever:
   nop
   b forever


// ----------------------------
// Interrupt Service Routines (ISRs) - Begin
//

csd_software_interrupt:
csd_undefined:
csd_prefetch:
csd_data:
csd_not_used:
csd_irq:
	ldr sp, =irq_stack_top
	str lr, [sp, #-4]!		//save pc(lr_irq)
	stmfd sp!, {r0-r12, lr}
	mrs r0, cpsr		//save cpsr
	str r0, [sp, #-4]!
	stmfd sp!, {sp}^	//save sp_usr

 	// Interrupt Ack
  	ldr r0, =GICC_IAR
	ldr r3, [r0]

 	// check context
	ldr r0, =context_now
	ldr r1, [r0]
	cmp r1, #2
	addle r1, #1	
	movgt r1, #1	//change process(1->2, 2->3, 3->1)
	str r1, [r0]

 	// Clear Interrupt Status bit
  	ldr r0, =PRIVATE_STATUS
  	mov r1, #1
	str r1, [r0]

 	// End-of-Interrupt
  	ldr r0, =GICC_EOIR
	str r3, [r0]

	add sp, sp, #8
	ldmfd sp!, {r0-r12, lr}	//recall registers from stack
	blt PCB_save1		//and save it to PCBs
	beq PCB_save2
	bgt PCB_save3

PCB_save1:
	ldr sp, =PCB_1_top
	sub sp, sp, #8		//down 2 addr(8B) for start & cpsr reg.
	stmfd sp!, {r0-r12, lr}		//save registers to PCBs
	ldr sp, = irq_stack_top
	ldr r0, [sp, #-4]!	//recall lr_irq(r0)
	sub sp, sp, #56
	ldr r2, [sp, #-4]!
	ldr r1, [sp, #-4]!		//recall sp_usr(r1), cpsr(r2)
	ldr sp, =PCB_1_top
	sub sp, sp, #4
	str r2, [sp, #-4]!
	sub sp, sp, #56
	str r1, [sp, #-4]!
	str r0, [r1, #-4]!		//save pc_usr to stack_1
	b switching

PCB_save2:
	ldr sp, =PCB_2_top
	sub sp, sp, #8		//down 2 addr(8B) for start & cpsr reg.
	stmfd sp!, {r0-r12, lr}		//save registers to PCBs
	ldr sp, = irq_stack_top
	ldr r0, [sp, #-4]!	//recall lr_irq(r0)
	sub sp, sp, #56
	ldr r2, [sp, #-4]!
	ldr r1, [sp, #-4]!		//recall sp_usr(r1), cpsr(r2)
	ldr sp, =PCB_2_top
	sub sp, sp, #4
	str r2, [sp, #-4]!
	sub sp, sp, #56
	str r1, [sp, #-4]!
	str r0, [r1, #-4]!
	b switching

PCB_save3:
	ldr sp, =PCB_3_top
	sub sp, sp, #8		//down 2 addr(8B) for start & cpsr reg.
	stmfd sp!, {r0-r12, lr}		//save registers to PCBs
	ldr sp, = irq_stack_top
	ldr r0, [sp, #-4]!//recall lr_irq(r0)
	sub sp, sp, #56
	ldr r2, [sp, #-4]!
	ldr r1, [sp, #-4]!		//recall sp_usr(r1), cpsr(r2)
	ldr sp, =PCB_3_top
	sub sp, sp, #4
	str r2, [sp, #-4]!
	sub sp, sp, #56
	str r1, [sp, #-4]!
	str r0, [r1, #-4]!

switching:
	blt process2
	beq process3
	bgt process1

process1:
	ldr sp, =PCB_1_top		
	sub sp, sp, #4			//down 4B for start reg.
	ldr r0, [sp, #-4]!
	bic r0, r0, #0xFF
	bic r0, r0, #1 << 8
	orr r0, r0, #0x10		//set user mode and enable a,i,f bits
	msr cpsr, r0
	ldr sp, =PCB_1_top
	sub sp, sp, #8
	ldmea sp!, {r0-r12,lr}	  //load registers
	ldr sp, [sp, #-4]!
	ldr pc, [sp, #-4]
	
process2:	
	ldr sp, =PCB_2_top
	ldr r0, [sp, #-4]!
	cmp r0, #0		//check task2 is started
	addeq r0, #1
	streq r0, [sp]
	mrseq r0, cpsr
	biceq r0, r0, #0xFF
	biceq r0, r0, #1 << 8
	orreq r0, r0, #0x10		//set user mode and enable a,i,f bits
	msreq cpsr_c, r0
	ldreq sp, =second_stack_top
	beq task2_c		//start task2
	
	ldr r0, [sp, #-4]!
	bic r0, r0, #0xFF
	bic r0, r0, #1 << 8
	orr r0, r0, #0x10		//set user mode and enable a,i,f bits
	msr cpsr, r0
	ldr sp, =PCB_2_top
	sub sp, sp, #8
	ldmea sp!, {r0-r12,lr}	  //load registers
	ldr sp, [sp, #-4]!
	ldr pc, [sp, #-4]

process3:
	ldr sp, =PCB_3_top
	ldr r0, [sp, #-4]!
	cmp r0, #0		//check task3 is started
	addeq r0, #1
	streq r0, [sp]
	mrseq r0, cpsr
	biceq r0, r0, #0xFF
	biceq r0, r0, #1 << 8
	orreq r0, r0, #0x10		//set user mode and enable a,i,f bits
	msreq cpsr, r0
	ldreq sp, =third_stack_top
	beq task3_c		//start task3

	ldr r0, [sp, #-4]!
	bic r0, r0, #0xFF
	bic r0, r0, #1 << 8
	orr r0, r0, #0x10		//set user mode and enable a,i,f bits
	msr cpsr_c, r0
	ldr sp, =PCB_3_top
	sub sp, sp, #8
	ldmea sp!, {r0-r12,lr}	  //load registers
	ldr sp, [sp, #-4]!
	ldr pc, [sp, #-4]

csd_fiq:
	b .

//
// Interrupt Service Routines (ISRs) - End
// ----------------------------

.data
.align 4

irq_stack:     .space 1024
irq_stack_top:
fiq_stack:     .space 1024
fiq_stack_top:
svc_stack:     .space 1024
svc_stack_top:

PCB_1:     .space 80	//start, r0-r12,lr,spsr, pc
PCB_1_top:
PCB_2:     .space 80
PCB_2_top:
PCB_3:     .space 80
PCB_3_top:

first_stack:     .space 1024
first_stack_top:
second_stack:     .space 1024
second_stack_top:
third_stack:     .space 1024
third_stack_top:

context_now: .space 4