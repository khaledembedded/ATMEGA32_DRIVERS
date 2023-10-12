/*
 * Timer0_int.h
 *
 *  Created on: Mar 25, 2020
 *      Author: Admin
 */

#ifndef TIMER0_INT_H_
#define TIMER0_INT_H_

#define Timer0_u8PIN_OC0 DIO_u8PIN_11


void Timer0_vidInit(void);
void MyDelay_ms(u32 time);
void Timer0_vidPWM_intensity(u8 precentage_intensity);

#endif /* TIMER0_INT_H_ */
