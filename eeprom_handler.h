#ifndef _EEPROM_HANDLER_INCLUDED_
#define _EEPROM_HANDLER_INCLUDED_

extern void eeprom_write_data(uint16_t uiAddress, uint8_t ucData);
extern uint8_t eeprom_read_data(uint16_t uiAddress);

#endif /* _EEPROM_HANDLER_H */
