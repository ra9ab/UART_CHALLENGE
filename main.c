#include "DIO.h"
#include "macros.h"
#include "LCD.h"
#include "registers.h"
#include "uart.h"
#include "avr/interrupt.h"
#define M2_READY 1
void main (void)
{LCD_init();
DIO_init ();
	init_uart();
uint8 x=1;

uint8 key_num=x;


LCD_displayCharacter(x);
    while(1)
    {LCD_intgerToString(x);
    	uart_transtmit_data(x++);
    	_delay_ms(500);
LCD_clearScreen();
    	if (x==9)
    	{x=0;}
}
}
