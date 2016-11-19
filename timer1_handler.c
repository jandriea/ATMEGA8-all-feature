#include <stdint.h>
#include "timer1_handler.h"

void timer1_init(void) {
  /*

    Set prescaler
    CS12   CS11   CS10
     0      0      0  Timer stop
     0      0      1  clk/1
     0      1      0  clk/8
     0      1      1  clk/64
     1      0      0  clk/256
     1      0      1  clk/1024
     1      1      0  ext clock on T1 falling edge
     1      1      1  ext clock on T1 rising edge

   */

   /* Use prescaler 1024 */
   TCCR1B = (1<<CS12)|(1<<CS10);

   /* Set TCNT0 */
   TCNT1H = 0x00;
   TCNT1L = 0x00;
}

void timer1_stop(void) {
  /* Stop TIMER0*/
  TCCR1B = 0x00;

  /* Reset TCNT0 value */
  TCNT1H = 0x00;
  TCNT1L = 0x00;
}
