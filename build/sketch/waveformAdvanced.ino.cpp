#include <Arduino.h>
#line 1 "c:\\atmega\\projects\\waveformAdvanced\\waveformAdvanced.ino"
#include <C:\atmega\includes\suite.h>

#line 3 "c:\\atmega\\projects\\waveformAdvanced\\waveformAdvanced.ino"
void delay(int length);
#line 13 "c:\\atmega\\projects\\waveformAdvanced\\waveformAdvanced.ino"
int main(void);
#line 3 "c:\\atmega\\projects\\waveformAdvanced\\waveformAdvanced.ino"
void delay(int length) {
    int cycledMs = 0;
    while (cycledMs != length) {
        _delay_ms(1);
        cycledMs++;
    }
}

int TIMER1_PRESCALER = 8;

int main(void) {

   DDRB |= 0x03; // Set pin B0 as output


   TCCR1A |= 0x40; // CTC on, with a prescaler of 8.
   TCCR1B |= 0x09;

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
        OCR1A = 16000000 / (freq * TIMER1_PRESCALER * 2);
        _delay_ms(500);

        freq = NoteManager::getNoteFrequency(Note::CS, octave);
        OCR1A = 16000000 / (freq * TIMER1_PRESCALER * 2);
        _delay_ms(500);

        freq = NoteManager::getNoteFrequency(Note::D, octave);
        OCR1A = 16000000 / (freq * TIMER1_PRESCALER * 2);
        _delay_ms(500);

        freq = NoteManager::getNoteFrequency(Note::DS, octave);
        OCR1A = 16000000 / (freq * TIMER1_PRESCALER * 2);
        _delay_ms(500);

        freq = NoteManager::getNoteFrequency(Note::E, octave);
        OCR1A = 16000000 / (freq * TIMER1_PRESCALER * 2);
        _delay_ms(500);

        freq = NoteManager::getNoteFrequency(Note::F, octave);
        OCR1A = 16000000 / (freq * TIMER1_PRESCALER * 2);
        _delay_ms(500);

        freq = NoteManager::getNoteFrequency(Note::FS, octave);
        OCR1A = 16000000 / (freq * TIMER1_PRESCALER * 2);
        _delay_ms(500);

        freq = NoteManager::getNoteFrequency(Note::G, octave);
        OCR1A = 16000000 / (freq * TIMER1_PRESCALER * 2);
        _delay_ms(500);

        freq = NoteManager::getNoteFrequency(Note::GS, octave);
        OCR1A = 16000000 / (freq * TIMER1_PRESCALER * 2);
        _delay_ms(500);

        freq = NoteManager::getNoteFrequency(Note::A, octave);
        OCR1A = 16000000 / (freq * TIMER1_PRESCALER * 2);
        _delay_ms(500);

        freq = NoteManager::getNoteFrequency(Note::AS, octave);
        OCR1A = 16000000 / (freq * TIMER1_PRESCALER * 2);
        _delay_ms(500);

        freq = NoteManager::getNoteFrequency(Note::B, octave);
        OCR1A = 16000000 / (freq * TIMER1_PRESCALER * 2);
        _delay_ms(500);
        octave++;
    }

}
