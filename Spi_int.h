/*
 * Spi_int.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: lenovo 1
 */

#ifndef SPI_INT_H_
#define SPI_INT_H_

#define SPI_u8DUMMY_DATA    0xFF

void Spi_vidMasterInit(void);
void Spi_vidSlaveInit(void);

u8   Spi_u8MasterTransfer(u8 Data);
u8   Spi_u8SlaveTransfer(u8 Data);

#endif /* SPI_INT_H_ */
