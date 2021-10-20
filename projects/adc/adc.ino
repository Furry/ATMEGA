uint16_t adc_value_current = 0;
uint16_t adc_value_max = 0;
uint16_t adc_value_min = 0;
bool adc_updated = false;

ISR(ADC_vect) {
    // read the ADC value
    adc_value_current = ADCL;
    adc_value_current |= ((ADCH & 0x03) << 8);
    adc_updated = true;
}

int main() {
    ADMUX = 0x41; // ADC1, right adjusted
    ADCSRA = 0x81; // enable ADC, start conversion, interrupt enable
    DIDR0 = 0x02; // disable digital input on ADC1

    // Taken from waveform code to enable waveform generation.
    DDRB |= 0x03; // Set pin B0 as output
    TCCR1A |= 0x40; // CTC on, with a prescaler of 8.
    TCCR1B |= 0x09;
    SREG |= 0x80; // Enable global interrupts

    while (1) {
        if (adc_updated) {
            // Scale ORC1A to the range of 0-255.
            OCR1A = (adc_value_current * 255) / 1024;
            adc_updated = false;
        }
    }

    return 0;
}