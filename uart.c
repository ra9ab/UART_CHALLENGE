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
void UART_sendString(const uint8 *Str)
{
	uint8 i = 0;
	while(Str[i] != '\0')
	{
		uart_transtmit_data(Str[i]);
		i++;
	}
}

void UART_receiveString(uint8 *Str)
{
	uint8 i = 0;
	Str[i] = uart_receive_data();
	while(Str[i] != '#')
	{
		i++;
		Str[i] = uart_receive_data();
	}
	Str[i] = '\0';
}

