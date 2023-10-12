/*
 * Timer0_cfg.h
 *
 *  Created on: Mar 25, 2020
 *      Author: Admin
 */

#ifndef TIMER0_CFG_H_
#define TIMER0_CFG_H_

#define TIMER0_PRE_1      1
#define TIMER0_PRE_8      2
#define TIMER0_PRE_64     3
#define TIMER0_PRE_256    4
#define TIMER0_PRE_1024   5
#define TIMER0_PRE_Ex_CL_T0_PIN_FALLING_EDGE 6
#define TIMER0_PRE_Ex_CL_T0_PIN_RISING_EDGE  7
#define TIMER0_PRE_NO_CLOCK_SOURCE           8


#define TIMER0_MODE_NORMAL            1
#define TIMER0_MODE_PWM_PHASE_CORRECT 2
#define TIMER0_MODE_CTC               3
#define TIMER0_MODE_FAST_PWM          4

//FOR NON PWM
#define TIMER0_COMPARE_OUTPUT_MODE_NORMAL                1
#define TIMER0_COMPARE_OUTPUT_MODE_TOGGLE_OC0            2
#define TIMER0_COMPARE_OUTPUT_MODE_CLR_OC0               3
#define TIMER0_COMPARE_OUTPUT_MODE_SET_OC0               4
//FOR PWM
#define TIMER0_COMP_PWM_NORMAL_PORT_OC0_DISCONNECTED     5
#define TIMER0_COMP_PWM_RESERVED                         6
#define TIMER0_COMP_CLR_OC0_ON_COMP_SET_OC0_TOP          7
#define TIMER0_COMP_SET_OC0_ON_COMP_CLR_OC0_TOP          8

//FOR PHASE CORRECT
#define TIMER0_COMP_PHASE_CORRECT_PWM_NORMAL_PORT_OC0_DISCONNECTED   9
#define TIMER0_COMP_PHASE_CORRECT_RESERVED               10
#define TIMER0_COMP_CLR_OC0_ON_COMP_SET_OC0_DOWN         11
#define TIMER0_COMP_SET_OC0_ON_COMP_CLR_OC0_DOWN         12








#define TIMER0_PRESCALER               TIMER0_PRE_1
#define TIMER_0_MODE                   TIMER0_MODE_NORMAL
#define TIMER0_COMPARE_OUTPUT_MODE     TIMER0_COMPARE_OUTPUT_MODE_NORMAL



#endif /* TIMER0_CFG_H_ */
