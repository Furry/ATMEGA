# 1 "c:\\atmega\\projects\\robot\\robot.ino"
# 2 "c:\\atmega\\projects\\robot\\robot.ino" 2

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
    
# 17 "c:\\atmega\\projects\\robot\\robot.ino" 3
   (*(volatile uint8_t *)(0xB3)) 
# 17 "c:\\atmega\\projects\\robot\\robot.ino"
         = 0;
    
# 18 "c:\\atmega\\projects\\robot\\robot.ino" 3
   (*(volatile uint8_t *)((0x27) + 0x20)) 
# 18 "c:\\atmega\\projects\\robot\\robot.ino"
         = 255;
    _delay_ms(1000);
    // stop();
}

void forward() {
    start();
    
# 25 "c:\\atmega\\projects\\robot\\robot.ino" 3
   (*(volatile uint8_t *)((0x27) + 0x20)) 
# 25 "c:\\atmega\\projects\\robot\\robot.ino"
         = 255/2;
    
# 26 "c:\\atmega\\projects\\robot\\robot.ino" 3
   (*(volatile uint8_t *)(0xB3)) 
# 26 "c:\\atmega\\projects\\robot\\robot.ino"
         = 255/2;
    _delay_ms(1000);
    stop();
}

int main() {
    // Enable OUTPUT on Pins 7, 6, 5, 4, 3, 2, 1, 0 (0x11111111) 
    
# 33 "c:\\atmega\\projects\\robot\\robot.ino" 3
   (*(volatile uint8_t *)((0x0A) + 0x20)) 
# 33 "c:\\atmega\\projects\\robot\\robot.ino"
        |= 0xFF;
    
# 34 "c:\\atmega\\projects\\robot\\robot.ino" 3
   (*(volatile uint8_t *)((0x05) + 0x20)) 
# 34 "c:\\atmega\\projects\\robot\\robot.ino"
         |= 0xFF;

    // Set Standby pin 3 to 1;
    
# 37 "c:\\atmega\\projects\\robot\\robot.ino" 3
   (*(volatile uint8_t *)((0x0B) + 0x20)) 
# 37 "c:\\atmega\\projects\\robot\\robot.ino"
         = 0x00 | (1 << 
# 37 "c:\\atmega\\projects\\robot\\robot.ino" 3
                        3
# 37 "c:\\atmega\\projects\\robot\\robot.ino"
                             );

    
# 39 "c:\\atmega\\projects\\robot\\robot.ino" 3
   (*(volatile uint8_t *)((0x0B) + 0x20)) 
# 39 "c:\\atmega\\projects\\robot\\robot.ino"
         |= (1 << 
# 39 "c:\\atmega\\projects\\robot\\robot.ino" 3
                  2
# 39 "c:\\atmega\\projects\\robot\\robot.ino"
                       );

    // SREG = 0x80;
    // OCR0A (PWM-A) is Pin 6;
    // IN2 is Pin 5;
    // IN1 is Pin 4;
    // Standby is Pin 3;

    // Enable TCCR0A and TCCR0B for PWM on Pin 6.
    
# 48 "c:\\atmega\\projects\\robot\\robot.ino" 3
   (*(volatile uint8_t *)((0x24) + 0x20)) 
# 48 "c:\\atmega\\projects\\robot\\robot.ino"
          |= (1 << 
# 48 "c:\\atmega\\projects\\robot\\robot.ino" 3
                   7
# 48 "c:\\atmega\\projects\\robot\\robot.ino"
                         ) | (1 << 
# 48 "c:\\atmega\\projects\\robot\\robot.ino" 3
                                   0
# 48 "c:\\atmega\\projects\\robot\\robot.ino"
                                        ) | (1 << 
# 48 "c:\\atmega\\projects\\robot\\robot.ino" 3
                                                  1
# 48 "c:\\atmega\\projects\\robot\\robot.ino"
                                                       ) << (1 << 
# 48 "c:\\atmega\\projects\\robot\\robot.ino" 3
                                                                  3
# 48 "c:\\atmega\\projects\\robot\\robot.ino"
                                                                       );
    
# 49 "c:\\atmega\\projects\\robot\\robot.ino" 3
   (*(volatile uint8_t *)((0x25) + 0x20)) 
# 49 "c:\\atmega\\projects\\robot\\robot.ino"
          |= (1 << 
# 49 "c:\\atmega\\projects\\robot\\robot.ino" 3
                   0
# 49 "c:\\atmega\\projects\\robot\\robot.ino"
                       );

    
# 51 "c:\\atmega\\projects\\robot\\robot.ino" 3
   (*(volatile uint8_t *)(0xB0)) 
# 51 "c:\\atmega\\projects\\robot\\robot.ino"
          |= (1 << 
# 51 "c:\\atmega\\projects\\robot\\robot.ino" 3
                   7
# 51 "c:\\atmega\\projects\\robot\\robot.ino"
                         ) | (1 << 
# 51 "c:\\atmega\\projects\\robot\\robot.ino" 3
                                   0
# 51 "c:\\atmega\\projects\\robot\\robot.ino"
                                        ) | (1 << 
# 51 "c:\\atmega\\projects\\robot\\robot.ino" 3
                                                  1
# 51 "c:\\atmega\\projects\\robot\\robot.ino"
                                                       );
    
# 52 "c:\\atmega\\projects\\robot\\robot.ino" 3
   (*(volatile uint8_t *)(0xB1)) 
# 52 "c:\\atmega\\projects\\robot\\robot.ino"
          |= (1 << 
# 52 "c:\\atmega\\projects\\robot\\robot.ino" 3
                   0
# 52 "c:\\atmega\\projects\\robot\\robot.ino"
                       );

    // moveCycle();

    
# 56 "c:\\atmega\\projects\\robot\\robot.ino" 3
   (*(volatile uint8_t *)((0x0B) + 0x20)) 
# 56 "c:\\atmega\\projects\\robot\\robot.ino"
         |= 0x10;

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
    
# 81 "c:\\atmega\\projects\\robot\\robot.ino" 3
   (*(volatile uint8_t *)((0x0B) + 0x20)) 
# 81 "c:\\atmega\\projects\\robot\\robot.ino"
         = 0x00;
    while (1) {}
}
