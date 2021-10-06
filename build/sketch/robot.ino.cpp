#include <Arduino.h>
#line 1 "c:\\atmega\\projects\\robot\\robot.ino"
#include <C:\atmega\includes\suite.h>

#line 3 "c:\\atmega\\projects\\robot\\robot.ino"
int main();
#line 3 "c:\\atmega\\projects\\robot\\robot.ino"
int main() {
    // Enable OUTPUT on Pins 7, 6, 5, and 4. (0x11110000) 
    DDRD |= 0xF0;

    // OCR0A Output is Pin 6;

    // Enable TCCR0A and TCCR0B for PWM on Pin 6.
    TCCR0A |= (1 << COM0A1) | (1 << WGM00) | (1 << WGM01);
    TCCR0B |= (1 << CS00);

    uint8_t dutyCycle0 = 0;
    bool invert = true;

    while (1) {
        if (invert) {
            dutyCycle0++;
            if (dutyCycle0 == 255) {
                invert = false;
            }
        } else {
            dutyCycle0--;
            if (dutyCycle0 == 0) {
                invert = true;
            }
        }

        OCR0A = dutyCycle0;
        _delay_ms(10);
    }
}
