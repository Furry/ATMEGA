# 1 "c:\\atmega\\projects\\waveformAdvanced\\waveformAdvanced.ino"
# 2 "c:\\atmega\\projects\\waveformAdvanced\\waveformAdvanced.ino" 2

void delay(int length) {
    int cycledMs = 0;
    while (cycledMs != length) {
        _delay_ms(1);
        cycledMs++;
    }
}

int TIMER1_PRESCALER = 8;

int main(void) {

   
# 15 "c:\\atmega\\projects\\waveformAdvanced\\waveformAdvanced.ino" 3
  (*(volatile uint8_t *)((0x04) + 0x20)) 
# 15 "c:\\atmega\\projects\\waveformAdvanced\\waveformAdvanced.ino"
       |= 0x03; // Set pin B0 as output


   
# 18 "c:\\atmega\\projects\\waveformAdvanced\\waveformAdvanced.ino" 3
  (*(volatile uint8_t *)(0x80)) 
# 18 "c:\\atmega\\projects\\waveformAdvanced\\waveformAdvanced.ino"
         |= 0x40; // CTC on, with a prescaler of 8.
   
# 19 "c:\\atmega\\projects\\waveformAdvanced\\waveformAdvanced.ino" 3
  (*(volatile uint8_t *)(0x81)) 
# 19 "c:\\atmega\\projects\\waveformAdvanced\\waveformAdvanced.ino"
         |= 0x09;

    // for (int i = 0; i < sizeof(notes); i += 2) {
        // int freq = notes[i];
        // int duration = notes[i + 1];

        // OCR1A = 16000000 / (freq * TIMER1_PRESCALER * 2);     
        // delay(duration);   
    // }

    int octave = 0;
    while (1) {
        float freq;
        freq = NoteManager::getNoteFrequency(Note::C, octave);
        
# 33 "c:\\atmega\\projects\\waveformAdvanced\\waveformAdvanced.ino" 3
       (*(volatile uint16_t *)(0x88)) 
# 33 "c:\\atmega\\projects\\waveformAdvanced\\waveformAdvanced.ino"
             = 16000000 / (freq * TIMER1_PRESCALER * 2);
        _delay_ms(500);

        freq = NoteManager::getNoteFrequency(Note::CS, octave);
        
# 37 "c:\\atmega\\projects\\waveformAdvanced\\waveformAdvanced.ino" 3
       (*(volatile uint16_t *)(0x88)) 
# 37 "c:\\atmega\\projects\\waveformAdvanced\\waveformAdvanced.ino"
             = 16000000 / (freq * TIMER1_PRESCALER * 2);
        _delay_ms(500);

        freq = NoteManager::getNoteFrequency(Note::D, octave);
        
# 41 "c:\\atmega\\projects\\waveformAdvanced\\waveformAdvanced.ino" 3
       (*(volatile uint16_t *)(0x88)) 
# 41 "c:\\atmega\\projects\\waveformAdvanced\\waveformAdvanced.ino"
             = 16000000 / (freq * TIMER1_PRESCALER * 2);
        _delay_ms(500);

        freq = NoteManager::getNoteFrequency(Note::DS, octave);
        
# 45 "c:\\atmega\\projects\\waveformAdvanced\\waveformAdvanced.ino" 3
       (*(volatile uint16_t *)(0x88)) 
# 45 "c:\\atmega\\projects\\waveformAdvanced\\waveformAdvanced.ino"
             = 16000000 / (freq * TIMER1_PRESCALER * 2);
        _delay_ms(500);

        freq = NoteManager::getNoteFrequency(Note::E, octave);
        
# 49 "c:\\atmega\\projects\\waveformAdvanced\\waveformAdvanced.ino" 3
       (*(volatile uint16_t *)(0x88)) 
# 49 "c:\\atmega\\projects\\waveformAdvanced\\waveformAdvanced.ino"
             = 16000000 / (freq * TIMER1_PRESCALER * 2);
        _delay_ms(500);

        freq = NoteManager::getNoteFrequency(Note::F, octave);
        
# 53 "c:\\atmega\\projects\\waveformAdvanced\\waveformAdvanced.ino" 3
       (*(volatile uint16_t *)(0x88)) 
# 53 "c:\\atmega\\projects\\waveformAdvanced\\waveformAdvanced.ino"
             = 16000000 / (freq * TIMER1_PRESCALER * 2);
        _delay_ms(500);

        freq = NoteManager::getNoteFrequency(Note::FS, octave);
        
# 57 "c:\\atmega\\projects\\waveformAdvanced\\waveformAdvanced.ino" 3
       (*(volatile uint16_t *)(0x88)) 
# 57 "c:\\atmega\\projects\\waveformAdvanced\\waveformAdvanced.ino"
             = 16000000 / (freq * TIMER1_PRESCALER * 2);
        _delay_ms(500);

        freq = NoteManager::getNoteFrequency(Note::G, octave);
        
# 61 "c:\\atmega\\projects\\waveformAdvanced\\waveformAdvanced.ino" 3
       (*(volatile uint16_t *)(0x88)) 
# 61 "c:\\atmega\\projects\\waveformAdvanced\\waveformAdvanced.ino"
             = 16000000 / (freq * TIMER1_PRESCALER * 2);
        _delay_ms(500);

        freq = NoteManager::getNoteFrequency(Note::GS, octave);
        
# 65 "c:\\atmega\\projects\\waveformAdvanced\\waveformAdvanced.ino" 3
       (*(volatile uint16_t *)(0x88)) 
# 65 "c:\\atmega\\projects\\waveformAdvanced\\waveformAdvanced.ino"
             = 16000000 / (freq * TIMER1_PRESCALER * 2);
        _delay_ms(500);

        freq = NoteManager::getNoteFrequency(Note::A, octave);
        
# 69 "c:\\atmega\\projects\\waveformAdvanced\\waveformAdvanced.ino" 3
       (*(volatile uint16_t *)(0x88)) 
# 69 "c:\\atmega\\projects\\waveformAdvanced\\waveformAdvanced.ino"
             = 16000000 / (freq * TIMER1_PRESCALER * 2);
        _delay_ms(500);

        freq = NoteManager::getNoteFrequency(Note::AS, octave);
        
# 73 "c:\\atmega\\projects\\waveformAdvanced\\waveformAdvanced.ino" 3
       (*(volatile uint16_t *)(0x88)) 
# 73 "c:\\atmega\\projects\\waveformAdvanced\\waveformAdvanced.ino"
             = 16000000 / (freq * TIMER1_PRESCALER * 2);
        _delay_ms(500);

        freq = NoteManager::getNoteFrequency(Note::B, octave);
        
# 77 "c:\\atmega\\projects\\waveformAdvanced\\waveformAdvanced.ino" 3
       (*(volatile uint16_t *)(0x88)) 
# 77 "c:\\atmega\\projects\\waveformAdvanced\\waveformAdvanced.ino"
             = 16000000 / (freq * TIMER1_PRESCALER * 2);
        _delay_ms(500);
        octave++;
    }

}
