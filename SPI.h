/*
 * SPI.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: lenovo 1
 */

#ifndef SPI_H_
#define SPI_H_


typedef enum
{

SPI_DISABLE,
SPI_ENABLE,

}SPI_ENABLE_MODE;



typedef enum
{

SPI_INTERRUPT_DISABLE,
SPI_INTERRUPT_ENABLE,

}SPI_INTERRUPT_STAE;


typedef enum
{

SPI_MSB,
SPI_LSB,

}SPI_DATA_ORDER;


typedef enum
{

SPI_MASTER,
SPI_SLAVE,

}SPI_MODE;



typedef enum
{

SPI_MODE0,
SPI_MODE1,
SPI_MODE2,
SPI_MODE3,

}SPI_CLOCK_MODES;


typedef enum
{

SPI_FCPU_2,
SPI_FCPU_4,
SPI_FCPU_8,
SPI_FCPU_16,
SPI_FCPU_32,
SPI_FCPU_64,
SPI_FCPU_128,

}SPI_FREQ;


typedef enum
{

SPI_NO_ERROR,
SPI_WRITE_COLISION,

}SPI_ERROR;


typedef struct
{
SPI_ENABLE_MODE      ENABLE_MODE;
SPI_INTERRUPT_STAE   INTERRUPT_STAE;
SPI_DATA_ORDER       DATA_ORDER;
SPI_MODE             MODE;
SPI_CLOCK_MODES      CLOCK_MODES;
SPI_FREQ             FREQ;
SPI_ERROR            ERROR;

}SPI_CONFIG_STRUCT;

extern SPI_CONFIG_STRUCT  SPI0;
void (*SPI_INTTERUPT_CB)(void);

void SPI_Init(void);
u8 SPI_Exchange_Data(u8 Data);


#endif /* SPI_H_ */
