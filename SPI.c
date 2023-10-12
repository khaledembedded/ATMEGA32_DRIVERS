/*
 * SPI.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: lenovo 1
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#undef F_CPU
#define F_CPU 1000000
#include <util/delay.h>
#include "Std_types.h"
#include "Bit_math.h"
#include "SPI.h"
#define NULL   (void)0
ISR(SPI_STC_vect)
{
if(SPI_INTTERUPT_CB!=0)
{
SPI_INTTERUPT_CB();
}

}

SPI_CONFIG_STRUCT  SPI0={0};

void SPI_Init(void)
{


SPCR=0;
SPSR=0;
switch(SPI0.ENABLE_MODE)
{
case SPI_DISABLE:
break;
case SPI_ENABLE:

switch(SPI0.MODE)
{
case SPI_MASTER:
SPCR|=(1<<MSTR);
DDRB|=(1<<5)|(1<<7)|(1<<4);
break;
case SPI_SLAVE:
DDRB|=(1<<6);
break;
default:
break;
}

break;
default:
break;
}


switch((SPI0.DATA_ORDER))
{
case SPI_MSB:
break;
case SPI_LSB:
SPCR|=(1<<DORD);
break;
default:
break;

}

switch((SPI0.INTERRUPT_STAE))
{
case SPI_INTERRUPT_DISABLE:
break;
case SPI_INTERRUPT_ENABLE:
SPCR|=(1<<SPIE);
break;
default:
break;

}


switch((SPI0.CLOCK_MODES))
{
case SPI_MODE0:
break;
case SPI_MODE1:
SPCR|=(1<<CPHA);
break;
case SPI_MODE2:
SPCR|=(1<<CPOL);
break;
case SPI_MODE3:
SPCR|=(1<<CPOL)|(1<<CPHA);
break;
default:
break;

}


switch((SPI0.FREQ))
{
case SPI_FCPU_2:
SPSR|=(1<<SPI2X);
break;
case SPI_FCPU_4:
break;
case SPI_FCPU_8:
SPSR|=(1<<SPI2X);
SPCR|=(SPR0);
break;
case SPI_FCPU_16:
SPCR|=(SPR0);
break;
case SPI_FCPU_32:
SPSR|=(1<<SPI2X);
SPCR|=(SPR1);
break;
case SPI_FCPU_64:
SPCR|=(SPR1);
break;
case SPI_FCPU_128:
SPCR|=(SPR0)|(SPR1);
break;
default:
break;

}

}


u8 SPI_Exchange_Data(u8 Data)
{

SPDR=Data;
if (SPSR & (1<<WCOL)!=0)
{
//ERROR HANDLING
SPI0.ERROR=SPI_WRITE_COLISION;
}
while(SPSR & (1<<SPIF)==0);
return SPDR;

}
