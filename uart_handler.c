#include <stdint.h>
#include "uart_handler.h"

#define FOSC 1843200 //Clock Speed
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1

void UART_Init(uint16_t ubrr){
  /* Set Baud rate */
  UBRRH = (uint8_t)(ubrr>>8);
  UBRRL = (uint8_t)(ubrr);
  /* Enable receiver and transmitter */
  UCSRB = (1<<RXEN)|(1<<TXEN);
  /* Set frame format: 8data, 1stop bit */
  UCSRC = (1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
}

void UART_Transmit(uint8_t data){
  /* Wait for empty transmit buffer */
  while ((UCSRA & (1<<UDRE)) == 0) {
    ; /* Wait until finish */
  }
  /* Put data into buffer, sends the data */
  UDR = data;
}

uint8_t UART_Receive(void){
  /* Wait for data to be received */
  while((UCSRA & (1<<RXC)) == 0){
    ; /* Wait until finish */
  }
  /* Get and return received data from buffer */
  return UDR;
}
