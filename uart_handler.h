#ifndef _UART_HANDLER_INCLUDED_
#define _UART_HANDLER_INCLUDED_

extern void UART_Init(uint16_t ubrr);
extern void UART_Transmit(uint8_t data);
extern uint8_t UART_Receive(void);

#endif
