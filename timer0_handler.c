#include <stdint.h>
#include "timer0_handler.h"

void timer0_init(void) {
  /*

  Set prescaler
  CS02   CS01   CS00
   0      0      0  Timer stop
   0      0      1  clk/1
   0      1      0  clk/8
   0      1      1  clk/64
   1      0      0  clk/256
   1      0      1  clk/1024
   1      1      0  ext clock on T0 falling edge
   1      1      1  ext clock on T0 rising edge

   */

   /* Use prescaler 1024 */
   TCCR0 = (1<<CS02)|(1<<CS00);

   /* Set TCNT0 */
   TCNT0 = 0x00;
}

void timer0_stop(void) {
  /* Stop TIMER0*/
  TCCR0 = 0x00;

  /* Reset TCNT0 value */
  TCNT0 = 0x00;
}
