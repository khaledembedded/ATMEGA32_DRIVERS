/*
 * Interr_int.h
 *
 *  Created on: Mar 19, 2020
 *      Author: khaled
 */

#ifndef INTERR_INT_H_
#define INTERR_INT_H_

#define INT0 0
#define INT1 1

void INT_vidInit(u8 INT_id);
void INT0_vidSetCB(void(*pf)(void));
void INT1_vidSetCB(void(*pf)(void));
void __vector_1 (void) __attribute__ ((signal,used, externally_visible)); //INT0
void __vector_2 (void) __attribute__ ((signal,used, externally_visible)); //INT1

#endif /* INTERR_INT_H_ */
