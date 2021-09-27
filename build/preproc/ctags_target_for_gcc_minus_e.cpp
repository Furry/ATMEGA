# 1 "c:\\atmega\\projects\\waveform\\waveform.ino"
char* tstFn(int x) {}


# 5 "c:\\atmega\\projects\\waveform\\waveform.ino" 2

int main() {
    *tstFn
# 7 "c:\\atmega\\projects\\waveform\\waveform.ino" 3
   (0x0A) 
# 7 "c:\\atmega\\projects\\waveform\\waveform.ino"
        = 0xFF;

    *tstFn
# 9 "c:\\atmega\\projects\\waveform\\waveform.ino" 3
   (0x0B) 
# 9 "c:\\atmega\\projects\\waveform\\waveform.ino"
         = 0xFF;
    while (1) {
        bitFlip(*tstFn
# 11 "c:\\atmega\\projects\\waveform\\waveform.ino" 3
               (0x0B)
# 11 "c:\\atmega\\projects\\waveform\\waveform.ino"
                    , 3);
        // PORTD = ~PORTD;
        _delay_ms(1000);
        bitFlip(0x0B, 3);
        // PORTD = ~PORTD;
        _delay_ms(1000);
    };
    return 0;
}
