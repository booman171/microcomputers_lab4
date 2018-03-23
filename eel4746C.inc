
.ifndef _EEL4746C_INC_
#define _EEL4746C_INC_

; Address Pointers
#define XH r27
#define XL r26
#define YH r29
#define YL r28
#define ZH r31
#define ZL r30

; Stack Pointer (I/O Internal Registers)
.set SPL, 0x3d
.set SPH, 0x3e

; Memory
.set RAMEND, 0x08ff

; I/O Ports
    ; Portt B
    .set PINB, 0x03
    .set DDRB, 0x04
    .set PORTB, 0x05

    ; Portt C
    .set PINC, 0x06
    .set DDRC, 0x07
    .set PORTC, 0x08

    ; Portt D
    .set PIND, 0x09
    .set DDRD, 0x0a
    .set PORTD, 0x0b


.endif
