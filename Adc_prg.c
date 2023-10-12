/*
 * Adc_prg.c
 *
 *  Created on: Mar 10, 2020
 *      Author: khaled
 */
#include "../Lib/Std_types.h"
#include "Adc_cfg.h"
#include "Adc_priv.h"
#include "Adc_int.h"

void Adc_vidInit(void)
{
	//Voltage Reference Selection
	#if ADC_VREF_VALUE == ADC_VREF_VCC_5V
		ADMUX.Bits.bit7 = 0;
		ADMUX.Bits.bit6 = 1;

	#elif ADC_VREF_VALUE == ADC_VREF_INT_2.56V
		ADMUX.Bits.bit7 = 1;
		ADMUX.Bits.bit6 = 1;

	#elif ADC_VREF_VALUE == ADC_VREF_AREF
		ADMUX.Bits.bit7 = 0;
		ADMUX.Bits.bit6 = 0;

	#endif

	//Presentation of ADC conversion
	#if ADC_ADJUST_VALUE == ADC_RIGHT_ADJUST
		ADMUX.Bits.bit5 = 0;

	#elif ADC_ADJUST_VALUE == ADC_LEFT_ADJUST
		ADMUX.Bits.Bit5 = 1;
	#endif

	//initialize with ADC0
	ADMUX.Bits.bit4 = 0;
	ADMUX.Bits.bit3 = 0;
	ADMUX.Bits.bit2 = 0;
	ADMUX.Bits.bit1 = 0;
	ADMUX.Bits.bit0 = 0;

	 //EN ADC
	ADCSRA.Bits.bit7 = 1;

	//SC (no conversion)
	ADCSRA.Bits.bit6 = 0;

	//Auto Trigger (no interrupt)
	ADCSRA.Bits.bit5 = 0;

	 //ADC interrupt flag(clear flag)
	ADCSRA.Bits.bit4 = 1;

	//ADC interrupt Enable
	ADCSRA.Bits.bit3 = 0;

	//Select Pre_scaler
	#if ADC_PRE_VALUE == ADC_PRE_2
		ADCSRA.Bits.bit2 = 0;
		ADCSRA.Bits.bit1 = 0;
		ADCSRA.Bits.bit0 = 1;

	#elif ADC_PRE_VALUE == ADC_PRE_4
		ADCSRA.Bits.bit2 = 0;
		ADCSRA.Bits.bit1 = 1;
		ADCSRA.Bits.bit0 = 0;

	#elif ADC_PRE_VALUE == ADC_PRE_8
		ADCSRA.Bits.bit2 = 0;
		ADCSRA.Bits.bit1 = 1;
		ADCSRA.Bits.bit0 = 1;

	#elif ADC_PRE_VALUE == ADC_PRE_16
		ADCSRA.Bits.bit2 = 1;
		ADCSRA.Bits.bit1 = 0;
		ADCSRA.Bits.bit0 = 0;

	#elif ADC_PRE_VALUE == ADC_PRE_32
		ADCSRA.Bits.bit2 = 1;
		ADCSRA.Bits.bit1 = 0;
		ADCSRA.Bits.bit0 = 1;

	#elif ADC_PRE_VALUE == ADC_PRE_64
		ADCSRA.Bits.bit2 = 1;
		ADCSRA.Bits.bit1 = 1;
		ADCSRA.Bits.bit0 = 0;

	#elif ADC_PRE_VALUE == ADC_PRE_128
		ADCSRA.Bits.bit2 = 1;
		ADCSRA.Bits.bit1 = 1;
		ADCSRA.Bits.bit0 = 1;
	#endif
}


u16 Adc_u16GetResult(u8 chnl_Id)
{
	u16 Result;
	u8 flag_val;
	//select channel
	ADMUX.Byte &= 0b11100000;
	ADMUX.Byte |= (chnl_Id & 0b00011111);

	//start conversion
	ADCSRA.Bits.bit6 = 1;

	//check ADIF
	while( (flag_val = ADCSRA.Bits.bit4) == 0 );

	//clear ADIF
	ADCSRA.Bits.bit4 = 1;

	//get result from ADCL & ADCH
	Result  = 0;
	Result  = ADCL.Byte;
	Result |= (ADCH.Byte<<8);
	return Result;

}


