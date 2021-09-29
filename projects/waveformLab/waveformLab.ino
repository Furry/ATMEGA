const int F4 = 349;

void setup() {
    DDRD = 0x00;
    TCCR0A = 0x42;
    // TCCR0B = 0x09;
    TCCR0B = 0x04;
    OCR0A = F4 * 2;
    SREG |= 0x80;
    
}

int main() {
    setup();
    while (1) {
        // Do nothing
    }
}