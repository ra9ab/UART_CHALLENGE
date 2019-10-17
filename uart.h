/*
 * uart.h
 *
 *  Created on: 29 Jun 2019
 *      Author: RGB
 */

#ifndef UART_H_
#define UART_H_
#define USART_BAUDRATE 9600
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 8UL))) - 1)
void init_uart(void);
void uart_transtmit_data(uint8);
uint8  uart_receive_data (void);
void UART_receiveString(uint8 *Str);
void UART_sendString(const uint8 *Str);

#endif /* UART_H_ */
