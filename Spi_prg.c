/*
 * Spi_prg.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: lenovo 1
 */


#include "Std_types.h"
#include "Bit_math.h"
#include "Dio_int.h"
#include "Spi_priv.h"
#include "Spi_int.h"


void Spi_vidMasterInit(void)
{
	/************ Dio Configuration **************
	*                  Master  |  Slave          *
	*               --------------------         *
	*PB4 12 -> SS       O/P        I/P (Pull-Up) *
	*PB5 13 -> MOSI     O/P        I/P           *
	*PB6 14 -> MISO     I/P        O/P           *
	*PB7 15 -> SCK      O/P        I/P           *
	**********************************************/
	Dio_vidSetPinDir(DIO_u8PIN_12,DIO_u8OUTPUT);
	Dio_vidSetPinDir(DIO_u8PIN_13,DIO_u8OUTPUT);
	Dio_vidSetPinDir(DIO_u8PIN_14,DIO_u8INPUT);
	Dio_vidSetPinDir(DIO_u8PIN_15,DIO_u8OUTPUT);

	/* Enable SPI */
	SET_BIT(SPCR,6);

	/* Select MSB first data order */
	CLR_BIT(SPCR,5);

	/* Select Master role */
	SET_BIT(SPCR,4);

	/* Select falling edge as leading edge "High Idle state" */
	SET_BIT(SPCR,3);  // CPOL

	/* Select Set-up first */
	SET_BIT(SPCR,2); // CPHA

	/* Select Fosc/64 for SCK */
	SET_BIT(SPCR,1);
	CLR_BIT(SPCR,0);
	CLR_BIT(SPSR,0); // SPI2X

}

void Spi_vidSlaveInit(void)
{
	/************ Dio Configuration **************
	*                  Master  |  Slave          *
	*               --------------------         *
	*PB4 12 -> SS       O/P        I/P (Pull-Up) *
	*PB5 13 -> MOSI     O/P        I/P           *
	*PB6 14 -> MISO     I/P        O/P           *
	*PB7 15 -> SCK      O/P        I/P           *
	**********************************************/
	Dio_vidSetPinDir(DIO_u8PIN_12,DIO_u8INPUT);
	Dio_vidSetPinVal(DIO_u8PIN_12,DIO_u8HIGH);

	Dio_vidSetPinDir(DIO_u8PIN_13,DIO_u8INPUT);
	Dio_vidSetPinDir(DIO_u8PIN_14,DIO_u8OUTPUT);
	Dio_vidSetPinDir(DIO_u8PIN_15,DIO_u8INPUT);

	/* Enable SPI */
	SET_BIT(SPCR,6);

	/* Select MSB first data order */
	CLR_BIT(SPCR,5);

	/* Select Slave role */
	CLR_BIT(SPCR,4);

	/* Select falling edge as leading edge "High Idle state" */
	SET_BIT(SPCR,3);  // CPOL

	/* Select Set-up first */
	SET_BIT(SPCR,2); // CPHA

}

u8   Spi_u8MasterTransfer(u8 Data)
{
	/* Select the salve */
	Dio_vidSetPinVal(DIO_u8PIN_12,DIO_u8LOW);

	/* load the register with the data to be transferred */
	SPDR = Data;

	/* wait till the transferring complete */
	while(GET_BIT(SPSR,7) == 0);

	/* Release the slave */
	Dio_vidSetPinVal(DIO_u8PIN_12,DIO_u8HIGH);

	/* return the received data */
	return SPDR;
}

u8   Spi_u8SlaveTransfer(u8 Data)
{
	/* load the register with the data to be transferred */
	SPDR = Data;

	/* wait till the transferring complete */
	while(GET_BIT(SPSR,7) == 0);

	/* return the received data */
	return SPDR;
}


