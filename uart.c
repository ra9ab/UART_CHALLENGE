/*
 * uart.c
 *
 *  Created on: 29 Jun 2019
 *      Author: RGB
 */
#include "DIO.h"
#include "stdtypes.h"
#include "macros.h"
#include "Registers.h"
#include "uart.h"

void init_uart(void)
{
	clr_bit(REG_UCSRA,PIN1);
	set_bit(REG_UCSRB,PIN3);
	set_bit(REG_UCSRB,PIN4);
	clr_bit(REG_UCSRB,PIN2);
	REG_UCSRC=0b10000110; // no parity ,, 8 bit data , 1 bit for stop
	set_bit(REG_UCSRB,PIN7);
	REG_UBRRL=51; //9600 baudrate
	REG_UBRRH=0;
}

void uart_transtmit_data(uint8 data)
{ while (get_bit(REG_UCSRA,PIN5)==0);
REG_UDR= data ;
}

uint8  uart_receive_data (void)
{
	while (get_bit(REG_UCSRA,PIN7)==0);
	return REG_UDR ;


}
