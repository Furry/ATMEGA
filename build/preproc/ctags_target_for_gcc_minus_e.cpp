# 1 "c:\\atmega\\projects\\robot\\robot.ino"
# 2 "c:\\atmega\\projects\\robot\\robot.ino" 2

int main() {
    // Enable OUTPUT on Pins 7, 6, 5, and 4. (0x11110000) 
    
# 5 "c:\\atmega\\projects\\robot\\robot.ino" 3
   (*(volatile uint8_t *)((0x0A) + 0x20)) 
# 5 "c:\\atmega\\projects\\robot\\robot.ino"
        |= 0xF0;

    // OCR0A Output is Pin 6;

    // Enable TCCR0A and TCCR0B for PWM on Pin 6.
    
# 10 "c:\\atmega\\projects\\robot\\robot.ino" 3
   (*(volatile uint8_t *)((0x24) + 0x20)) 
# 10 "c:\\atmega\\projects\\robot\\robot.ino"
          |= (1 << 
# 10 "c:\\atmega\\projects\\robot\\robot.ino" 3
                   7
# 10 "c:\\atmega\\projects\\robot\\robot.ino"
                         ) | (1 << 
# 10 "c:\\atmega\\projects\\robot\\robot.ino" 3
                                   0
# 10 "c:\\atmega\\projects\\robot\\robot.ino"
                                        ) | (1 << 
# 10 "c:\\atmega\\projects\\robot\\robot.ino" 3
                                                  1
# 10 "c:\\atmega\\projects\\robot\\robot.ino"
                                                       );
    
# 11 "c:\\atmega\\projects\\robot\\robot.ino" 3
   (*(volatile uint8_t *)((0x25) + 0x20)) 
# 11 "c:\\atmega\\projects\\robot\\robot.ino"
          |= (1 << 
# 11 "c:\\atmega\\projects\\robot\\robot.ino" 3
                   0
# 11 "c:\\atmega\\projects\\robot\\robot.ino"
                       );

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

        
# 29 "c:\\atmega\\projects\\robot\\robot.ino" 3
       (*(volatile uint8_t *)((0x27) + 0x20)) 
# 29 "c:\\atmega\\projects\\robot\\robot.ino"
             = dutyCycle0;
        _delay_ms(10);
    }
}
