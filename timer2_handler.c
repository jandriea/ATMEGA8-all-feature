#include <stdint.h>
#include "timer2_handler.h"

void timer2_init(void) {
  /*

  Set prescaler
  CS22   CS21   CS20
   0      0      0  Timer stop
   0      0      1  clk/1
   0      1      0  clk/8
   0      1      1  clk/32
   1      0      0  clk/64
   1      0      1  clk/128
   1      1      0  clk/256
   1      1      1  clk/1024

   */

   /* Use prescaler 1024 */
   TCCR2 = (1<<CS22)|(1<<CS20);

   /* Set TCNT2 */
   TCNT2 = 0x00;
}

void timer2_stop(void) {
  /* Stop TIMER2*/
  TCCR2 = 0x00;

  /* Reset TCNT2 value */
  TCNT2 = 0x00;
}
