int main() {
    DDRD |= 0b00000100 | 0x01;

    // TCCR1A CTC off
    TCCR1A = 0x40;
    TCCR1B |= 0x09; // Set to FastPWM mode for Timer 1

    OCR1A = 0x00; // Set the compare value to 0

    // Configure ADC for 10 bit resolution
    ADMUX |= 0x40;
    ADCSRA |= 0x88;
    DIDR0 |= 0x02;

    // Using the Timer 1 overflow interrupt to trigger the ADC and control the servo
    TIMSK1 |= 0x02;

    return 0;
}