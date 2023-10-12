/*
 * Timer0_prg.c
 *
 *  Created on: Mar 25, 2020
 *      Author: Admin
 */
#include"../Lib/Std_types.h"
#include"../Lib/Bit_math.h"
#include"Timer0_priv.h"
#include"Timer0_cfg.h"
#include"Timer0_int.h"
#include"Dio_int.h"

u32 ovf_count;
u32 ms_count;
u32 t_desired;
u8 end;
u8 percentage_intensity;
void Timer0_vidInit(void){

#if TIMER_0_MODE == TIMER0_MODE_NORMAL
	CLR_BIT(TCCR0.Byte,6);
	CLR_BIT(TCCR0.Byte,3);

#elif TIMER_0_MODE == TIMER0_MODE_PWM_PHASE_CORRECT
	SET_BIT(TCCR0.Byte,6);
	CLR_BIT(TCCR0.Byte,3);

#elif TIMER_0_MODE == TIMER0_MODE_CTC
	CLR_BIT(TCCR0.Byte,6);
	SET_BIT(TCCR0.Byte,3);

#elif TIMER_0_MODE == TIMER0_MODE_FAST_PWM

	SET_BIT(TCCR0.Byte,6);
	SET_BIT(TCCR0.Byte,3);
#endif

#if TIMER0_PRESCALER==TIMER0_PRE_1
	CLR_BIT(TCCR0.Byte,2);
	CLR_BIT(TCCR0.Byte,1);
	SET_BIT(TCCR0.Byte,0);

#elif TIMER0_PRESCALER==TIMER0_PRE_8
	TCCR0.Bits.CS02=0
			TCCR0.Bits.CS01=1
			TCCR0.Bits.CS00=0

#elif TIMER0_PRESCALER==TIMER0_PRE_64
			CLR_BIT(TCCR0.Byte.Byte,2);
	SET_BIT(TCCR0.Byte,1);
	SET_BIT(TCCR0.Byte,0);
#elif TIMER0_PRESCALER==TIMER0_PRE_256
	SET_BIT(TCCR0.Byte,2);
	CLR_BIT(TCCR0.Byte,1);
	CLR_BIT(TCCR0.Byte,0);
#elif TIMER0_PRESCALER==TIMER0_PRE_1024
	SET_BIT(TCCR0.Byte,2);
	CLR_BIT(TCCR0.Byte,1);
	SET_BIT(TCCR0.Byte,0);
#elif TIMER0_PRESCALER==TIMER0_PRE_Ex_CL_T0_PIN_FALLING_EDGE
	SET_BIT(TCCR0.Byte,2);
	SET_BIT(TCCR0.Byte,1);
	CLR_BIT(TCCR0.Byte,0);
#elif TIMER0_PRESCALER==TIMER0_PRE_Ex_CL_T0_PIN_RISING_EDGE
	SET_BIT(TCCR0.Byte,2);
	SET_BIT(TCCR0.Byte,1);
	SET_BIT(TCCR0.Byte,0);
#elif TIMER0_PRESCALER==TIMER0_PRE_NO_CLOCK_SOURCE
	CLR_BIT(TCCR0.Byte,2);
	CLR_BIT(TCCR0.Byte,1);
	CLR_BIT(TCCR0.Byte,0);
#endif

#if TIMER0_COMPARE_OUTPUT_MODE== TIMER0_COMPARE_OUTPUT_MODE_NORMAL
	CLR_BIT(TCCR0.Byte,5);
	CLR_BIT(TCCR0.Byte,4);

#elif TIMER0_COMPARE_OUTPUT_MODE ==TIMER0_COMPARE_OUTPUT_MODE_TOGGLE_OC0
	CLR_BIT(TCCR0.Byte,5);
	SET_BIT(TCCR0.Byte.Byte,4);

#elif TIMER0_COMPARE_OUTPUT_MODE ==TIMER0_COMPARE_OUTPUT_MODE_CLR_OC0
	SET_BIT(TCCR0.Byte,5);
	CLR_BIT(TCCR0.Byte,4);

#elif TIMER0_COMPARE_OUTPUT_MODE== TIMER0_COMPARE_OUTPUT_MODE_SET_OC0
	SET_BIT(TCCR0.Byte,5);
	SET_BIT(TCCR0.Byte,4);

#elif TIMER0_COMPARE_OUTPUT_MODE==TIMER0_COMP_PWM_NORMAL_PORT_OC0_DISCONNECTED
	CLR_BIT(TCCR0.Byte,5);
	CLR_BIT(TCCR0.Byte,4);

#elif TIMER0_COMPARE_OUTPUT_MODE==TIMER0_COMP_PWM_RESERVED
	CLR_BIT(TCCR0.Byte,5);
	SET_BIT(TCCR0.Byte,4);


#elif TIMER0_COMPARE_OUTPUT_MODE==TIMER0_COMP_CLR_OC0_ON_COMP_SET_OC0_TOP
	SET_BIT(TCCR0.Byte,5);
	CLR_BIT(TCCR0.Byte,4);

#elif TIMER0_COMPARE_OUTPUT_MODE==TIMER0_COMP_SET_OC0_ON_COMP_CLR_OC0_TOP
	SET_BIT(TCCR0.Byte,5);
	SET_BIT(TCCR0.Byte,4);

#elif TIMER0_COMPARE_OUTPUT_MODE==TIMER0_COMP_PHASE_CORRECT_PWM_NORMAL_PORT_OC0_DISCONNECTED
	CLR_BIT(TCCR0.Byte,5);
	CLR_BIT(TCCR0.Byte,4);

#elif TIMER0_COMPARE_OUTPUT_MODE==TIMER0_COMP_PHASE_CORRECT_RESERVED
	CLR_BIT(TCCR0.Byte,5);
	SET_BIT(TCCR0.Byte,4);

#elif TIMER0_COMPARE_OUTPUT_MODE==TIMER0_COMP_CLR_OC0_ON_COMP_SET_OC0_DOWN
	SET_BIT(TCCR0.Byte,5);
	CLR_BIT(TCCR0.Byte,4);

#elif TIMER0_COMPARE_OUTPUT_MODE==TIMER0_COMP_SET_OC0_ON_COMP_CLR_OC0_DOWN
	SET_BIT(TCCR0.Byte,5);
	SET_BIT(TCCR0.Byte,4);


#endif

}
void MyDelay_ms(u32 time)
{

	TCNT0.Byte=192;
	/*Enable Timer/Counter0 Overflow Interrupt Enable*/
	TIMSK.Bits.TOIE0=1;
	//enable general interrupt
	SREG.Bits.I=1;

	ovf_count=0;
	ms_count=0;
	t_desired=time;
	end=0;
	/*momken a3maal gowahaa ay 7agaaa 3o2baal ma el delaay ye5laaas "ya3ny kdaa ba3maal maximization lel cpu utilization"*/
	while(end==0);
	/* No Prescaller Clock Source ,to stop the prescaler "Timer Stopped"*/
	TCCR0.Bits.CS00=0;
	TCCR0.Bits.CS01=0;
	TCCR0.Bits.CS02=0;



}


void __vector_11(void)
{
	ovf_count++;
	/*kdaa ma3naah eny 3adeet 1 msec , "32" de ya3nyy number of overflow=(Tmin_unit/Tovf)*/
	if(ovf_count==32)
	{
		TCNT0.Byte=192;
		ovf_count=0;
		ms_count++;
		if(ms_count==t_desired)
		{
			end=1;
		}
	}
}




void Timer0_vidPWM_intensity(u8 precentage_intensity){

Dio_vidSetPinDir(Timer0_u8PIN_OC0,DIO_u8OUTPUT);
OCR0.Byte=(percentage_intensity*255)/100;

}
