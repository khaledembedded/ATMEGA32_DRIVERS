/*
 * Uart_prg.c
 *
 *  Created on: Jun 21, 2020
 *      Author: Admin
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Uart_int.h"
#include "Uart_priv.h"
#include "Uart_cfg.h"

void Uart_vidInit(void)
{
	/* Temporary variable to write UCSRC register */
	u8 Temp_u8UcsrcData;

	/* Clear any rubbish values in the variable */
	Temp_u8UcsrcData = 0;

	/* Enable Rx and Tx */
	SET_BIT(UCSRB,4); //Rx
	SET_BIT(UCSRB,3); //Tx

	/* Asynchronous Mode */
	CLR_BIT(Temp_u8UcsrcData,6);

	/* Disable Parity checking */
	CLR_BIT(Temp_u8UcsrcData,5);
	CLR_BIT(Temp_u8UcsrcData,4);

	/* Select 1-Bit Stop */
	CLR_BIT(Temp_u8UcsrcData,3);

	/* Select 8-Bit Character Size */
	CLR_BIT(UCSRB,2);
	SET_BIT(Temp_u8UcsrcData,2);
	SET_BIT(Temp_u8UcsrcData,1);

	/* Update UCSRC register with Temp Data */
	UCSRC = Temp_u8UcsrcData;

	/* Configure "9600" Baudrate */
	CLR_BIT(UCSRA,1);
	UBRRH = 0;
	UBRRL = 51;
	//using MACROS
	//UBRRL=(u8)UBRR;
	//UBRRH=(u8)(UBRR>>8);
}

void Uart_vidSendByte(u8 Byte)
{
	/* Waiting till UDR register is Empty */
	while(GET_BIT(UCSRA,5) == 0);

	/* Update UDR register with the data needs to be sent */
	UDR = Byte;
}

u8   Uart_u8ReceiveByte(void)
{
	/* Waiting till RxC flag raise */
	while(GET_BIT(UCSRA,7) == 0);

	/* Return the received Byte */
	return UDR;
}

void Uart_vidSendString(u8 *str){
	u8 i;
	while(str[i]!='\0')
	{
		Uart_vidSendByte(str[i]);
		i++;
	}
}
