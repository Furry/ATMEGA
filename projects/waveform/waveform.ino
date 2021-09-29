#include <C:\atmega\includes\suite.h>

const int PRESCALE = 8;

void delay(int length) {
    int cycledMs = 0;
    while (cycledMs != length) {
        _delay_ms(1);
        cycledMs++;
    }
}

int main(void)
{

   DDRB |= 0x03; // Set pin B0 as output


   TCCR1A |= 0x40; // CTC on, with a prescaler of 8.
   TCCR1B |= 0x09;

    while (1)
    {
        int notes[] = { 
            Notes::NoteC5, Notes::WHOLE_NOTE,
            Notes::NoteA4, Notes::WHOLE_NOTE,
            Notes::NoteF4, Notes::WHOLE_NOTE,
            Notes::NoteC4, Notes::WHOLE_NOTE,

            Notes::NoteD4, Notes::THIRD_NOTE,
            Notes::NoteE4, Notes::THIRD_NOTE,
            Notes::NoteF4, Notes::THIRD_NOTE,

            Notes::NoteD4, Notes::HALF_NOTE,
            Notes::NoteF4, Notes::THIRD_NOTE,

            Notes::NoteC4, Notes::WHOLE_NOTE,
            Notes::NoteC4, Notes::WHOLE_NOTE,

            Notes::NoteD4, Notes::WHOLE_NOTE,
            Notes::NoteA4_SHARP, Notes::WHOLE_NOTE,
            
            Notes::NoteA4, Notes::WHOLE_NOTE,
            
            Notes::NoteF4, Notes::WHOLE_NOTE,

            Notes::NoteD4, Notes::THIRD_NOTE,
            Notes::NoteE4, Notes::THIRD_NOTE,
            Notes::NoteF4, Notes::THIRD_NOTE,

            Notes::NoteG4, Notes::HALF_NOTE,
            Notes::NoteA4, Notes::THIRD_NOTE,

            Notes::NoteG4, Notes::WHOLE_NOTE,
            Notes::NoteG4, Notes::WHOLE_NOTE,
            Notes::NoteG4, Notes::WHOLE_NOTE
        }; 


        for (int i = 0; i < sizeof(notes); i += 2) {
            int freq = notes[i];
            int duration = notes[i + 1];

            OCR1A = 16000000 / (freq * PRESCALE * 2);     
            delay(duration);   
        }

        _delay_ms(2500);

        while (1) {
            // Do nothing pls
        }

    }
}