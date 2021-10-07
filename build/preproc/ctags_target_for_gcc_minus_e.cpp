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
void turnRight() {
    
# 15 "c:\\atmega\\projects\\robot\\robot.ino" 3
   (*(volatile uint8_t *)(0xB3)) 
# 15 "c:\\atmega\\projects\\robot\\robot.ino"
         = 255;
    
# 16 "c:\\atmega\\projects\\robot\\robot.ino" 3
   (*(volatile uint8_t *)((0x27) + 0x20)) 
# 16 "c:\\atmega\\projects\\robot\\robot.ino"
         = 0;
    _delay_ms(900);
}

void turnLeft() {
    // start();
    
# 22 "c:\\atmega\\projects\\robot\\robot.ino" 3
   (*(volatile uint8_t *)(0xB3)) 
# 22 "c:\\atmega\\projects\\robot\\robot.ino"
         = 0;
    
# 23 "c:\\atmega\\projects\\robot\\robot.ino" 3
   (*(volatile uint8_t *)((0x27) + 0x20)) 
# 23 "c:\\atmega\\projects\\robot\\robot.ino"
         = 255;
    _delay_ms(900);
    // stop();
}

void forward() {
    start();
    
# 30 "c:\\atmega\\projects\\robot\\robot.ino" 3
   (*(volatile uint8_t *)((0x27) + 0x20)) 
# 30 "c:\\atmega\\projects\\robot\\robot.ino"
         = 150;
    
# 31 "c:\\atmega\\projects\\robot\\robot.ino" 3
   (*(volatile uint8_t *)(0xB3)) 
# 31 "c:\\atmega\\projects\\robot\\robot.ino"
         = 150;
    _delay_ms(1000);
    stop();
}

int main() {
    // Enable OUTPUT on Pins 7, 6, 5, 4, 3, 2, 1, 0 (0x11111111) 
    
# 38 "c:\\atmega\\projects\\robot\\robot.ino" 3
   (*(volatile uint8_t *)((0x0A) + 0x20)) 
# 38 "c:\\atmega\\projects\\robot\\robot.ino"
        |= 0xFF;
    
# 39 "c:\\atmega\\projects\\robot\\robot.ino" 3
   (*(volatile uint8_t *)((0x05) + 0x20)) 
# 39 "c:\\atmega\\projects\\robot\\robot.ino"
         |= 0xFF;

    // Set Standby pin 3 to 1;
    
# 42 "c:\\atmega\\projects\\robot\\robot.ino" 3
   (*(volatile uint8_t *)((0x0B) + 0x20)) 
# 42 "c:\\atmega\\projects\\robot\\robot.ino"
         = 0x00 | (1 << 
# 42 "c:\\atmega\\projects\\robot\\robot.ino" 3
                        3
# 42 "c:\\atmega\\projects\\robot\\robot.ino"
                             );

    
# 44 "c:\\atmega\\projects\\robot\\robot.ino" 3
   (*(volatile uint8_t *)((0x0B) + 0x20)) 
# 44 "c:\\atmega\\projects\\robot\\robot.ino"
         |= (1 << 
# 44 "c:\\atmega\\projects\\robot\\robot.ino" 3
                  2
# 44 "c:\\atmega\\projects\\robot\\robot.ino"
                       );

    // SREG = 0x80;
    // OCR0A (PWM-A) is Pin 6;
    // IN2 is Pin 5;
    // IN1 is Pin 4;
    // Standby is Pin 3;

    // Enable TCCR0A and TCCR0B for PWM on Pin 6.
    
# 53 "c:\\atmega\\projects\\robot\\robot.ino" 3
   (*(volatile uint8_t *)((0x24) + 0x20)) 
# 53 "c:\\atmega\\projects\\robot\\robot.ino"
          |= (1 << 
# 53 "c:\\atmega\\projects\\robot\\robot.ino" 3
                   7
# 53 "c:\\atmega\\projects\\robot\\robot.ino"
                         ) | (1 << 
# 53 "c:\\atmega\\projects\\robot\\robot.ino" 3
                                   0
# 53 "c:\\atmega\\projects\\robot\\robot.ino"
                                        ) | (1 << 
# 53 "c:\\atmega\\projects\\robot\\robot.ino" 3
                                                  1
# 53 "c:\\atmega\\projects\\robot\\robot.ino"
                                                       ) | (1 << 
# 53 "c:\\atmega\\projects\\robot\\robot.ino" 3
                                                                 3
# 53 "c:\\atmega\\projects\\robot\\robot.ino"
                                                                      );
    
# 54 "c:\\atmega\\projects\\robot\\robot.ino" 3
   (*(volatile uint8_t *)((0x25) + 0x20)) 
# 54 "c:\\atmega\\projects\\robot\\robot.ino"
          |= (1 << 
# 54 "c:\\atmega\\projects\\robot\\robot.ino" 3
                   0
# 54 "c:\\atmega\\projects\\robot\\robot.ino"
                       );

    
# 56 "c:\\atmega\\projects\\robot\\robot.ino" 3
   (*(volatile uint8_t *)(0xB0)) 
# 56 "c:\\atmega\\projects\\robot\\robot.ino"
          |= (1 << 
# 56 "c:\\atmega\\projects\\robot\\robot.ino" 3
                   7
# 56 "c:\\atmega\\projects\\robot\\robot.ino"
                         ) | (1 << 
# 56 "c:\\atmega\\projects\\robot\\robot.ino" 3
                                   0
# 56 "c:\\atmega\\projects\\robot\\robot.ino"
                                        ) | (1 << 
# 56 "c:\\atmega\\projects\\robot\\robot.ino" 3
                                                  1
# 56 "c:\\atmega\\projects\\robot\\robot.ino"
                                                       );
    
# 57 "c:\\atmega\\projects\\robot\\robot.ino" 3
   (*(volatile uint8_t *)(0xB1)) 
# 57 "c:\\atmega\\projects\\robot\\robot.ino"
          |= (1 << 
# 57 "c:\\atmega\\projects\\robot\\robot.ino" 3
                   0
# 57 "c:\\atmega\\projects\\robot\\robot.ino"
                       );

    // moveCycle();

    
# 61 "c:\\atmega\\projects\\robot\\robot.ino" 3
   (*(volatile uint8_t *)((0x0B) + 0x20)) 
# 61 "c:\\atmega\\projects\\robot\\robot.ino"
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



    // Square
    // forward();
    // turnLeft();
    // forward();
    // turnLeft();
    // forward();
    // turnLeft();
    // forward();
    // turnLeft();

    // Figure8
    turnLeft();
    turnLeft();
    turnLeft();
    forward();
    forward();
    turnRight();
    turnRight();
    turnRight();

    
# 97 "c:\\atmega\\projects\\robot\\robot.ino" 3
   (*(volatile uint8_t *)((0x0B) + 0x20)) 
# 97 "c:\\atmega\\projects\\robot\\robot.ino"
         = 0x00;
    while (1) {}
}
