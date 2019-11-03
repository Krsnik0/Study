
#define csd_LED_ADDR	0x41200000

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
	ldr r0, =Input_data		//set Input_data
	ldr r1, =Output_data	//set Output_data
	mov r2, #32				//set counter

loop:
	ldr r3, [r0], #4    	//load a word into r3 and upate r0 (= r0 + 4)
	str r3, [r1], #4		//store the word to memory and upate r1 (= r1 + 4)
	subs r2, r2, #1			//count r2
	bne  loop				//put data in Output_data

	ldr r0, =Output_data	//set r0 to Output_data(I'll control Output_data directly)

sort2:					//start of outter loop
	mov r6, #31			//counter of outter loop
	mov r5, r6			//counter of inner loop

	mov r1, #0			//declare & reset first index
	mov r2, #4			//declare & reset second index
sort1:					//start of inner loop
	ldr r3, [r0, r1]	//first source
	ldr r4, [r0, r2]	//second source

	cmp r3, r4			//compare r3 & r4
	bgt func1			//goto func1 if r3>r4
	b next				//else, goto next
func1:
	str r3, [r0, r2]	//save r3's data to r4
	str r4, [r0, r1]	//save r4's data to r3
next:
	add r1, r1, #4		//increase first index
	add r2, r2, #4		//increase second index
	subs r5, r5, #1		//update loop counter
	bne sort1			//goto sort1(end of inner loop)

	subs r6, r6, #1		//update loop counter
	bne sort2			//goto sort2(end of outter loop)

	//end sorting


 	ldr r0, =csd_LED_ADDR
	mov r1, #0x5
	str r1, [r0]

	bl csd_main

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

Input_data:
	.word 2, 0, -7, -1, 3, 8, -4, 10
 	.word -9, -16, 15, 13, 1, 4, -3, 14
 	.word -8, -10, -15, 6, -13, -5, 9, 12
 	.word -11, -14, -6, 11, 5, 7, -2, -12

Output_data:
	.word 0, 0, 0, 0, 0, 0, 0, 0
 	.word 0, 0, 0, 0, 0, 0, 0, 0
 	.word 0, 0, 0, 0, 0, 0, 0, 0
 	.word 0, 0, 0, 0, 0, 0, 0, 0


// Normal Interrupt Service Routine
csd_irq:
	b .
