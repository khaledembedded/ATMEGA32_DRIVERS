/*
 * Uart_int.h
 *
 *  Created on: Jun 21, 2020
 *      Author: Admin
 */

#ifndef UART_INT_H_
#define UART_INT_H_

//#include"Uart_cfg.h"

//#define UBRR FOSC/16/BAUD-1

void Uart_vidInit(void);
void Uart_vidSendByte(u8 byte);
u8   Uart_u8RecieveByte(void);
void Uart_vidSendString(u8 *str);














#endif /* UART_INT_H_ */
