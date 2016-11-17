#ifndef _SPI_HANDLER_INCLUDED_
#define _SPI_HANDLER_INCLUDED_

/*************************************************************************
* Title   : C include file for the SPI interface
* Author  : Jatty_
* File    : spi_handler.h
* Software:
* Target  : ATMEGA8
**************************************************************************/

extern void SPI_MasterInit(void);
extern void SPI_MasterTransmit(int8_t cData);
extern void SPI_SlaveInit(void);
extern int8_t SPI_SlaveReceive(void);

#endif
