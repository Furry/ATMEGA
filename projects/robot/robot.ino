#include <C:\atmega\includes\suite.h>

/*
Ideally, a rotation on a left/right axis will provide a motor with more power.
OCR0 = (255 / 2) + rotationLeft;
OCR2 = (255 / 2) + rotationRight;
*/
int rotationLeft = 0;
int rotationRight = 0;

void rotateLeft() {
    rotationLeft++;
    if (rotationLeft == 125) {
        rotationLeft = 0;
    }
}

void rotateRight() {
    rotationRight++;
    if (rotationRight == 125) {
        rotationRight = 0;
    }
}

void jumpRight(uint8_t distance) {
    for (uint8_t i = 0; i < distance; i++) {
        rotateRight();
    };
}

void jumpLeft(uint8_t distance) {
    for (uint8_t i = 0; i < distance; i++) {
        rotateLeft();
    };
}

void move(time) {
    OCR0A = (255 / 2) + rotationLeft;
    OCR2A = (255 / 2) + rotationRight;
    _delay_ms(time);
}

void moveCycle() {
    // Proof-Of-Concept code to do a square.
    rotationLeft = 0;
    rotationRight = 0;
    move(2000);
    jumpLeft(25);
    move(2000);
    jumpLeft(25);
    move(2000);
    jumpLeft(25);
    move(2000);
};


int main() {
    // Enable OUTPUT on Pins 7, 6, 5, and 4. (0x11110000) 
    DDRD |= 0xF0;

    // OCR0A Output is Pin 6;

    // Enable TCCR0A and TCCR0B for PWM on Pin 6.
    TCCR0A |= (1 << COM0A1) | (1 << WGM00) | (1 << WGM01);
    TCCR0B |= (1 << CS00);

    TCCR2A |= (1 << COM2A1) | (1 << WGM20) | (1 << WGM21);
    TCCR2B |= (1 << CS20);

    moveCycle();

    PORTD |= 0x10;
    // Temporary Breathing Example for a LED on Pin 6
    // uint8_t dutyCycle0 = 0;
    // bool invert = true;

    // while (1) {
    //     if (invert) {
    //         dutyCycle0++;
    //         if (dutyCycle0 == 255) {
    //             invert = false;
    //         }
    //     } else {
    //         dutyCycle0--;
    //         if (dutyCycle0 == 0) {
    //             invert = true;
    //         }
    //     }
    //
    //     OCR0A = dutyCycle0;
    //     _delay_ms(10);
    // }
}