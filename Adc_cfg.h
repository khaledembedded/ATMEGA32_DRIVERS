/*
 * Adc_cfg.h
 *
 *  Created on: Mar 10, 2020
 *      Author: khaled
 */

#ifndef ADC_CFG_H_
#define ADC_CFG_H_

//Voltage Reference Selection
#define ADC_VREF_VCC_5V 0
#define ADC_VREF_INT_2.56V 1
#define ADC_VREF_AREF 2
#define ADC_VREF_VALUE ADC_VREF_VCC_5V

//Presentation of ADC conversion
#define ADC_LEFT_ADJUST 0
#define ADC_RIGHT_ADJUST 1
#define ADC_ADJUST_VALUE ADC_RIGHT_ADJUST

//Select Pre_scaler
#define ADC_PRE_2 0
#define ADC_PRE_4 1
#define ADC_PRE_8 2
#define ADC_PRE_16 3
#define ADC_PRE_32 4
#define ADC_PRE_64 5
#define ADC_PRE_128 6
#define ADC_PRE_VALUE ADC_PRE_8

#endif /* ADC_CFG_H_ */
