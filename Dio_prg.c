/*
 * Dio_prg.c
 *
 *  Created on: Feb 19, 2020
 *      Author: khaled
 */
#include "../Lib/Std_types.h"
#include "Dio_int.h"
#include "Dio_priv.h"

void Dio_vidSetPinDir(u8 Pin , u8 Dir)
{
	u8 PortId;
	u8 PinLoc;

	PortId = Pin/8;
	PinLoc = Pin%8;

	switch(PortId)
	{
		case 0:
			if(Dir ==1)
				{
					switch(PinLoc)
					{
						case 0:
							DDRA.Bits.pin0 =1;
						break;

						case 1:
							DDRA.Bits.pin1 =1;
						break;

						case 2:
							DDRA.Bits.pin2 =1;
						break;

						case 3:
							DDRA.Bits.pin3 =1;
						break;

						case 4:
							DDRA.Bits.pin4 =1;
						break;

						case 5:
							DDRA.Bits.pin5 =1;
						break;

						case 6:
							DDRA.Bits.pin6 =1;
						break;

						case 7:
							DDRA.Bits.pin7 =1;
						break;
					}
				}
			else
			{
				switch(PinLoc)
				{
					case 0:
						DDRA.Bits.pin0 =0;
					break;

					case 1:
						DDRA.Bits.pin1 =0;
					break;

					case 2:
						DDRA.Bits.pin2 =0;
					break;

					case 3:
						DDRA.Bits.pin3 =0;
					break;

					case 4:
						DDRA.Bits.pin4 =0;
					break;

					case 5:
						DDRA.Bits.pin5 =0;
					break;

					case 6:
						DDRA.Bits.pin6 =0;
					break;

					case 7:
						DDRA.Bits.pin7 =0;
					break;
				}
			}
		break;

		case 1:
			if(Dir ==1)
				{
					switch(PinLoc)
					{
						case 0:
							DDRB.Bits.pin0 =1;
						break;

						case 1:
							DDRB.Bits.pin1 =1;
						break;

						case 2:
							DDRB.Bits.pin2 =1;
						break;

						case 3:
							DDRB.Bits.pin3 =1;
						break;

						case 4:
							DDRB.Bits.pin4 =1;
						break;

						case 5:
							DDRB.Bits.pin5 =1;
						break;

						case 6:
							DDRB.Bits.pin6 =1;
						break;

						case 7:
							DDRB.Bits.pin7 =1;
						break;
					}
				}
			else
			{
				switch(PinLoc)
				{
					case 0:
						DDRB.Bits.pin0 =0;
					break;

					case 1:
						DDRB.Bits.pin1 =0;
					break;

					case 2:
						DDRB.Bits.pin2 =0;
					break;

					case 3:
						DDRB.Bits.pin3 =0;
					break;

					case 4:
						DDRB.Bits.pin4 =0;
					break;

					case 5:
						DDRB.Bits.pin5 =0;
					break;

					case 6:
						DDRB.Bits.pin6 =0;
					break;

					case 7:
						DDRB.Bits.pin7 =0;
					break;
				}
			}
			break;

		case 2:
			if(Dir ==1)
				{
					switch(PinLoc)
					{
						case 0:
							DDRC.Bits.pin0 =1;
						break;

						case 1:
							DDRC.Bits.pin1 =1;
						break;

						case 2:
							DDRC.Bits.pin2 =1;
						break;

						case 3:
							DDRC.Bits.pin3 =1;
						break;

						case 4:
							DDRC.Bits.pin4 =1;
						break;

						case 5:
							DDRC.Bits.pin5 =1;
						break;

						case 6:
							DDRC.Bits.pin6 =1;
						break;

						case 7:
							DDRC.Bits.pin7 =1;
						break;
					}
				}
			else
			{
				switch(PinLoc)
				{
					case 0:
						DDRC.Bits.pin0 =0;
					break;

					case 1:
						DDRC.Bits.pin1 =0;
					break;

					case 2:
						DDRC.Bits.pin2 =0;
					break;

					case 3:
						DDRC.Bits.pin3 =0;
					break;

					case 4:
						DDRC.Bits.pin4 =0;
					break;

					case 5:
						DDRC.Bits.pin5 =0;
					break;

					case 6:
						DDRC.Bits.pin6 =0;
					break;

					case 7:
						DDRC.Bits.pin7 =0;
					break;
				}
			}
		break;


		case 3:
			if(Dir ==1)
				{
					switch(PinLoc)
					{
						case 0:
							DDRD.Bits.pin0 =1;
						break;

						case 1:
							DDRD.Bits.pin1 =1;
						break;

						case 2:
							DDRD.Bits.pin2 =1;
						break;

						case 3:
							DDRD.Bits.pin3 =1;
						break;

						case 4:
							DDRD.Bits.pin4 =1;
						break;

						case 5:
							DDRD.Bits.pin5 =1;
						break;

						case 6:
							DDRD.Bits.pin6 =1;
						break;

						case 7:
							DDRD.Bits.pin7 =1;
						break;
					}
				}
			else
			{
				switch(PinLoc)
				{
					case 0:
						DDRD.Bits.pin0 =0;
					break;

					case 1:
						DDRD.Bits.pin1 =0;
					break;

					case 2:
						DDRD.Bits.pin2 =0;
					break;

					case 3:
						DDRD.Bits.pin3 =0;
					break;

					case 4:
						DDRD.Bits.pin4 =0;
					break;

					case 5:
						DDRD.Bits.pin5 =0;
					break;

					case 6:
						DDRD.Bits.pin6 =0;
					break;

					case 7:
						DDRD.Bits.pin7 =0;
					break;
				}
			}
		break;
	}
}

void Dio_vidSetPinVal(u8 Pin , u8 Val)
{
	u8 PortId;
	u8 PinLoc;

	PortId = Pin/8;
	PinLoc = Pin%8;

	switch(PortId){
		case 0:
			if(Val ==1)
				{
					switch(PinLoc)
					{
						case 0:
							PORTA.Bits.pin0 =1;
						break;

						case 1:
							PORTA.Bits.pin1 =1;
						break;

						case 2:
							PORTA.Bits.pin2 =1;
						break;

						case 3:
							PORTA.Bits.pin3 =1;
						break;

						case 4:
							PORTA.Bits.pin4 =1;
						break;

						case 5:
							PORTA.Bits.pin5 =1;
						break;

						case 6:
							PORTA.Bits.pin6 =1;
						break;

						case 7:
							PORTA.Bits.pin7 =1;
						break;
					}
				}
			else
			{
				switch(PinLoc)
				{
					case 0:
						PORTA.Bits.pin0 =0;
					break;

					case 1:
						PORTA.Bits.pin1 =0;
					break;

					case 2:
						PORTA.Bits.pin2 =0;
					break;

					case 3:
						PORTA.Bits.pin3 =0;
					break;

					case 4:
						PORTA.Bits.pin4 =0;
					break;

					case 5:
						PORTA.Bits.pin5 =0;
					break;

					case 6:
						PORTA.Bits.pin6 =0;
					break;

					case 7:
						PORTA.Bits.pin7 =0;
					break;
				}
			}
		break;

		case 1:
			if(Val ==1)
				{
					switch(PinLoc)
					{
						case 0:
							PORTB.Bits.pin0 =1;
						break;

						case 1:
							PORTB.Bits.pin1 =1;
						break;

						case 2:
							PORTB.Bits.pin2 =1;
						break;

						case 3:
							PORTB.Bits.pin3 =1;
						break;

						case 4:
							PORTB.Bits.pin4 =1;
						break;

						case 5:
							PORTB.Bits.pin5 =1;
						break;

						case 6:
							PORTB.Bits.pin6 =1;
						break;

						case 7:
							PORTB.Bits.pin7 =1;
						break;
					}
				}
			else
			{
				switch(PinLoc)
				{
					case 0:
						PORTB.Bits.pin0 =0;
					break;

					case 1:
						PORTB.Bits.pin1 =0;
					break;

					case 2:
						PORTB.Bits.pin2 =0;
					break;

					case 3:
						PORTB.Bits.pin3 =0;
					break;

					case 4:
						PORTB.Bits.pin4 =0;
					break;

					case 5:
						PORTB.Bits.pin5 =0;
					break;

					case 6:
						PORTB.Bits.pin6 =0;
					break;

					case 7:
						PORTB.Bits.pin7 =0;
					break;
				}
			}
			break;

		case 2:
			if(Val ==1)
				{
					switch(PinLoc)
					{
						case 0:
							PORTC.Bits.pin0 =1;
						break;

						case 1:
							PORTC.Bits.pin1 =1;
						break;

						case 2:
							PORTC.Bits.pin2 =1;
						break;

						case 3:
							PORTC.Bits.pin3 =1;
						break;

						case 4:
							PORTC.Bits.pin4 =1;
						break;

						case 5:
							PORTC.Bits.pin5 =1;
						break;

						case 6:
							PORTC.Bits.pin6 =1;
						break;

						case 7:
							PORTC.Bits.pin7 =1;
						break;
					}
				}
			else
			{
				switch(PinLoc)
				{
					case 0:
						PORTC.Bits.pin0 =0;
					break;

					case 1:
						PORTC.Bits.pin1 =0;
					break;

					case 2:
						PORTC.Bits.pin2 =0;
					break;

					case 3:
						PORTC.Bits.pin3 =0;
					break;

					case 4:
						PORTC.Bits.pin4 =0;
					break;

					case 5:
						PORTC.Bits.pin5 =0;
					break;

					case 6:
						PORTC.Bits.pin6 =0;
					break;

					case 7:
						PORTC.Bits.pin7 =0;
					break;
				}
			}
		break;


		case 3:
			if(Val ==1)
				{
					switch(PinLoc)
					{
						case 0:
							PORTD.Bits.pin0 =1;
						break;

						case 1:
							PORTD.Bits.pin1 =1;
						break;

						case 2:
							PORTD.Bits.pin2 =1;
						break;

						case 3:
							PORTD.Bits.pin3 =1;
						break;

						case 4:
							PORTD.Bits.pin4 =1;
						break;

						case 5:
							PORTD.Bits.pin5 =1;
						break;

						case 6:
							PORTD.Bits.pin6 =1;
						break;

						case 7:
							PORTD.Bits.pin7 =1;
						break;
					}
				}
			else
			{
				switch(PinLoc)
				{
					case 0:
						PORTD.Bits.pin0 =0;
					break;

					case 1:
						PORTD.Bits.pin1 =0;
					break;

					case 2:
						PORTD.Bits.pin2 =0;
					break;

					case 3:
						PORTD.Bits.pin3 =0;
					break;

					case 4:
						PORTD.Bits.pin4 =0;
					break;

					case 5:
						PORTD.Bits.pin5 =0;
					break;

					case 6:
						PORTD.Bits.pin6 =0;
					break;

					case 7:
						PORTD.Bits.pin7 =0;
					break;
				}
			}
		break;
	}
}

u8 Dio_u8GetPinVal(u8 pin)
{
	u8 PortId;
	u8 PinLoc;
	u8 PinVal;


	PortId = pin/8;
	PinLoc = pin%8;

	switch(PortId)
	{
		case 0:
			switch(PinLoc)
			{
				case 0:
					PinVal = PINA.Bits.pin0;
				break;

				case 1:
					PinVal = PINA.Bits.pin1;
				break;

				case 2:
					PinVal = PINA.Bits.pin2;
				break;

				case 3:
					PinVal = PINA.Bits.pin3 ;
				break;

				case 4:
					PinVal = PINA.Bits.pin4;
				break;

				case 5:
					PinVal = PINA.Bits.pin5;
				break;

				case 6:
					PinVal = PINA.Bits.pin6;
				break;

				case 7:
					PinVal = PINA.Bits.pin7;
				break;
			}
		break;

		case 1:
			switch(PinLoc)
			{
				case 0:
					PinVal = PINB.Bits.pin0;
				break;

				case 1:
					PinVal = PINB.Bits.pin1;
				break;

				case 2:
					PinVal = PINB.Bits.pin2;
				break;

				case 3:
					PinVal = PINB.Bits.pin3;
				break;

				case 4:
					PinVal = PINB.Bits.pin4;
				break;

				case 5:
					PinVal = PINB.Bits.pin5;
				break;

				case 6:
					PinVal = PINB.Bits.pin6;
				break;

				case 7:
					PinVal = PINB.Bits.pin7;
				break;
			}

		break;

		case 2:
			switch(PinLoc)
			{
				case 0:
					PinVal = PINC.Bits.pin0;
				break;

				case 1:
					PinVal = PINC.Bits.pin1;
				break;

				case 2:
					PinVal = PINC.Bits.pin2;
				break;

				case 3:
					PinVal = PINC.Bits.pin3;
				break;

				case 4:
					PinVal = PINC.Bits.pin4;
				break;

				case 5:
					PinVal = PINC.Bits.pin5;
				break;

				case 6:
					PinVal = PINC.Bits.pin6;
				break;

				case 7:
					PinVal = PINC.Bits.pin7;
				break;
			}

		break;

		case 3:
			switch(PinLoc)
			{
				case 0:
					PinVal = PIND.Bits.pin0;
				break;

				case 1:
					PinVal = PIND.Bits.pin1;
				break;

				case 2:
					PinVal = PIND.Bits.pin2;
				break;

				case 3:
					PinVal = PIND.Bits.pin3;
				break;

				case 4:
					PinVal = PIND.Bits.pin4;
				break;

				case 5:
					PinVal = PIND.Bits.pin5;
				break;

				case 6:
					PinVal = PIND.Bits.pin6;
				break;

				case 7:
					PinVal = PIND.Bits.pin7;
				break;
			}
		break;
	}
	return PinVal;
}
