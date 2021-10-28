/* 
 *  Introduction to analog-to-digital conversion (ADC):
 *  the INT0 external interrupt on pad 2 triggers an ADC
 *  measurement on pad A1, which is then printed to the 
 *  Serial Monitor. 
 *  
 *  Because printing is time consuming, rather than 
 *  printing this information in the INT0 ISR, the main
 *  control loop checks a state variable to decide whether
 *  or not to print.
 *  
 *  Team Analysis Challenge: Measure voltage and predict ADC output
 *  Embedded Systems Week 08: Analog to Digital Conversion
 *  @author Caitrin Eaton
 *  @date 18 October 2018
 */
#include <avr/io.h>
#include "USART.h"

uint16_t measCur = 0;     // current ADC measurement
uint16_t cache [100] = {};

ISR( INT0_vect ){
    /* The user pressed the button on pad 2, so trigger
     * a new conversion on pad A1 by setting the ADSC bit. */
    ADCSRA |= 0x40;
}


ISR( ADC_vect ){
    /* Save the new measurement and set the state variable
     * so that the control loop will print it to the Serial
     * Monitor. */
     measCur = ADCL;                // must read low byte first to ensure both bytes are from the same conversion
     measCur |= ((ADCH&0x03) << 8); // must shift the high byte left 8 bits or it will overwrite the measCur's lower byte
}

// Function to average our Cache Array 
int avg(int *arr) {
  int container = 0;
  for (int a = 0; a < sizeof(arr); a = a + 1) {
    container += arr[a];
  }
  return container / sizeof(arr);
}

int main() {

  char pmsg[32];
  sprintf(pmsg, "avg,pos");
  /* INT0 Configuration */
  EICRA = 0x03;  // INT0 is rising-edge triggered
  EIMSK = 0x01;  // INT0's ISR enabled

  /* ADC Configuration */
  ADMUX  = 0x41;
  ADCSRA = 0x8F;
  DIDR0  = 0x02;

  /* Serial Comm Configuration */
  initUSART();
  
  SREG |= 0x80;
  
  char msg[32];
  int x = 0;
  while( true ){
    for (uint8_t z = 0; z < 100; z ++ ) {
       if (x > 100) {
         x = 0;
       }

      ADCSRA |= 0x40;
      cache[x] = measCur;
      sprintf( msg, "%d,%d\n", avg(cache), measCur );
      printString( msg );


      _delay_ms(1);
      x += 1; 
    }

    _delay_ms(5000);

  }

  return 0;
}
