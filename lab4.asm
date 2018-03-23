.include "eel4746C.inc"
.global start
.global delay
.global outPortD; void outPortD(int)
.global inPortD; int inPortD(void)
.global initPortD; void initPortD(int)
.extern __main

start:
	rjmp 0x68
	.org 0x68
	ldi r16, hi8(RAMEND)
	out SPH, r16
	ldi r16, lo8(RAMEND)
	out SPL, r16
	rjmp __main

initPortD:
	out DDRD, r24
	ret

outPortD:
	out PORTD, r24
	ret

inPortD:
	in r24, PORTD
	ret

delay:
	.set delay1, 255
	ldi r18, delay1
next:
	dec r18
	nop
	brne next
	ret

