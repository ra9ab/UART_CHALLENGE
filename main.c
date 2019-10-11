#include <avr/interrupt.h>
#include "DIO.h"
#include "timer.h"
#include "LCD.h"
#include "uart.h"
#include <avr/delay.h>


uint8 flag=0;
void main (void)

{uint8 val=0 ;
LCD_init();
DIO_init();
init_uart();
LCD_clearScreen();

	while(1){

		val =uart_receive_data();
		LCD_intgerToString(val);
		_delay_ms(500);
		LCD_clearScreen();


}
}
