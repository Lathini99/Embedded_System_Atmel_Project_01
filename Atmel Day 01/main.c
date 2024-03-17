/*
 * Atmel Day 01.c
 *
 * Created: 3/17/2024 8:57:22 PM
 * Author : Dell
 */ 


#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>

// int main(void)
// {
//     DDRB |= 0xF0; // without directly setting the port into binary number, it is a good practice to or the value with the DDRB register
// 	DDRB &= 0B11111110;

//     /* Replace with your application code */
//     while (1)
//     {
// 		if(PINB & 0x01){
// 			PORTB |= 0xF0;
// 		}else{
// 			PORTB &= 0B11101111;
// 		}
//     }
// }

volatile int toggle = 0;

int main(void)
{
    EICRA |= 0B00001100; // setting the interrupt to trigger on the rising edge in the INT1
    EIMSK |= 0B00000010; // enabling the interrupt for INT1
    sei();               // enabling the global interrupt

    DDRB |= 0B11111110; // setting the DDRB to output for the LED

    while (1)
    {
    }
}

// ISR for the INT1
ISR(INT1_vect)
{
    if (toggle)
    {
        PORTB |= 0B00100000;
    }
    else
    {
        PORTB &= 0B11011111;
        
    }
	toggle = 1 - toggle;
}
