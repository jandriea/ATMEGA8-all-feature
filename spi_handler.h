#ifndef _SPI_HANDLER_INCLUDED_
#define _SPI_HANDLER_INCLUDED_

extern void SPI_MasterInit(void);
extern void SPI_MasterTransmit(int8_t cData);
extern void SPI_SlaveInit(void);
extern int8_t SPI_SlaveReceive(void);

#endif
