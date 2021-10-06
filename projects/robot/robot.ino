#include <C:\atmega\includes\suite.h>

void stop() {
    // PORTD = (0 << PIND3);
    // OCR0A = 0;
    // OCR2A = 0;
    // _delay_ms(1000);
}

void start() {
    // PORTD |= ~(1 << PIND3);
    // PORTD &= ~(1 << PIND3);
}

void turnLeft() {
    // start();
    OCR2A = 0;
    OCR0A = 255;
    _delay_ms(1000);
    // stop();
}

void forward() {
    start();
    OCR0A = 255/2;
    OCR2A = 255/2;
    _delay_ms(1000);
    stop();
}

int main() {
    // Enable OUTPUT on Pins 7, 6, 5, 4, 3, 2, 1, 0 (0x11111111) 
    DDRD |= 0xFF;
    PORTB |= 0xFF;

    // Set Standby pin 3 to 1;
    PORTD = 0x00 | (1 << PIND3);

    PORTD |= (1 << PIND2);

    // SREG = 0x80;
    // OCR0A (PWM-A) is Pin 6;
    // IN2 is Pin 5;
    // IN1 is Pin 4;
    // Standby is Pin 3;

    // Enable TCCR0A and TCCR0B for PWM on Pin 6.
    TCCR0A |= (1 << COM0A1) | (1 << WGM00) | (1 << WGM01) << (1 << WGM02);
    TCCR0B |= (1 << CS00);

    TCCR2A |= (1 << COM2A1) | (1 << WGM20) | (1 << WGM21);
    TCCR2B |= (1 << CS20);

    // moveCycle();

    PORTD |= 0x10;
    
    // Temporary Breathing Example for a LED on Pin 6
    // uint8_t dutyCycle0 = 0;
    // while (1) {
    //     dutyCycle0++;
    //     if (dutyCycle0 == 255) {
    //         dutyCycle0 = 0;
    //     }
    //     OCR0A = dutyCycle0;
    //     OCR2A = dutyCycle0;
    //     _delay_ms(10);
    // }



    // circleLeft();
    forward();
    turnLeft();
    forward();
    turnLeft();
    forward();
    turnLeft();
    forward();
    turnLeft();
    PORTD = 0x00;
    while (1) {}
}