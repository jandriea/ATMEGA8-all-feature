#include <stdint.h>
#include "spi_handler.h"

void SPI_MasterInit(void){
  /* Set MOSI and SCK output, all others input */
  DDR_SPI = (1<<DD_MOSI)|(1<<DD_SCK);
  /* Enable SPI, Master, set clock rate fck/16 */
  SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}

void SPI_MasterTransmit(int8_t cData){
  /* Start Transmission */
  SPDR = cData;
  /* Wait for transmission complete */
  while ((SPSR & (1<<SPIF)) == 0) {
    ;/* Wait until finish */
  }
}

void SPI_SlaveInit(void){
  /* Set MISO outpput, all others input */
  DDR_SPI = (1<<DD_MISO);
  /* Enable SPI */
  SPCR = (1<<SPE);
}

int8_t SPI_SlaveReceive(void){
  /* Wait for reception complete */
  while ((SPSR & (1<<SPIF)) == 0) {
    ; /* Wait until finish */
  }
  /* Return data register */
  return SPDR;
}
