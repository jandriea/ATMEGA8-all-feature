#include <stdint.h>
#include "eeprom_handler.h"

void eeprom_write_data(uint16_t uiAddress, uint8_t ucData){
  /* Wait for completion of previous write */
  while (EECR & (1 << EEWE)) {
    ; /* Wait until finish */
  }
  /* Set up address and data registers */
  EEAR = uiAddress;
  EEDR = ucData;

  /* Write logical ine to EEMWE */
  EECR |= (1<<EEMWE);
  /* Start eeprom write by setting EEWE */
  EECR |= (1<<EEWE);
}

uint8_t eeprom_read_data(uint16_t uiAddress)
{
  /* Wait for completion of previous write */
  while(EECR & (1<<EEWE)){
    ; /* Wait until finish */
  }
  /* Set up address register */
  EEAR = uiAddress;
  /* Start eeprom read by writing EERE */
  EECR |= (1<<EERE);
  /* Return data from data register */
  return EEDR;
}
