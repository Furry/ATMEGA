#include <Arduino.h>
#line 1 "c:\\atmega\\projects\\waveform\\waveform.ino"
#line 1 "c:\\atmega\\projects\\waveform\\waveform.ino"
char * tstFn(int x);
#line 6 "c:\\atmega\\projects\\waveform\\waveform.ino"
int main();
#line 1 "c:\\atmega\\projects\\waveform\\waveform.ino"
char* tstFn(int x) {}
#define _SFR_IO8 *tstFn

#include <C:\atmega\includes\suite.h>

int main() {
    DDRD = 0xFF;

    PORTD = 0xFF;
    while (1) {
        bitFlip(PORTD, 3);
        // PORTD = ~PORTD;
        _delay_ms(1000);
        bitFlip(0x0B, 3);
        // PORTD = ~PORTD;
        _delay_ms(1000);
    };
    return 0;
}
