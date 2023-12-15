.extern main
.section .vectors
.global _start
_start:
	// Vectors
	b _reset
	b halt // _undefined_handler
	b halt // _supervisor_call
	b halt // _prefetch_abort_handler
	b halt // _data_abort_handler
	nop
	b halt // _irq_handler

.section .text.boot
_reset:
	// Shutoff extra cores
	mrc p15, 0, r5, c0, c0, 5
	ands r5, r5, #3
	bne halt

	// Setup stack
	mov sp, #0x30000000

	// BSS clear
	ldr r0, =_sbss
	ldr r1, =_ebss
	bl memzero

	// Call kernel
	b main

halt:
	b halt
