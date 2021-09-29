#include <Arduino.h>
#line 1 "c:\\atmega\\projects\\waveform\\waveform.ino"
// // char* tstFn(int x) {}
// // #define _SFR_IO8 *tstFn

#include <C:\atmega\includes\suite.h>

// // int main() {
// //     // Set timer counter to empty
// //     TCNT0 = 0;

// //     TCCR0B |= (1 << WGM01); // Set CTC mode

// //     // Enable the 256 prescaler for TCCR0B
// //     TCCR0B |= (1 << 0x05);

// //     TIMSK0 |= (1 << OCIE0A); // Enable the compare match interrupt

// //     return 0;
// // }

// // int main() {
// //     // TIMER 1 for interrupt frequency 392.0031360250882 Hz:
// //     cli(); // stop interrupts
// //     TCCR1A = 0; // set entire TCCR1A register to 0
// //     TCCR1B = 0; // same for TCCR1B
// //     TCNT1  = 0; // initialize counter value to 0
// //     // set compare match register for 392.0031360250882 Hz increments
// //     OCR1A = 40815; // = 16000000 / (1 * 392.0031360250882) - 1 (must be <65536)
// //     // turn on CTC mode
// //     TCCR1B |= (1 << WGM12);
// //     // Set CS12, CS11 and CS10 bits for 1 prescaler
// //     TCCR1B |= (0 << CS12) | (0 << CS11) | (1 << CS10);
// //     // enable timer compare interrupt
// //     TIMSK1 |= (1 << OCIE1A);
// //     sei(); // allow interrupts

// //     while (1) {
// //         // do nothing
// //     }

// //     return 0;
// // }
 
// // Create a hashtable with a string as a key, and an int as a value


// //F4 - 349.23
// //22,392.6
// //256 - 87
// int main() {

//     DDRB = (1 << PINB0);

//     TCCR1A = (1 << COM1A1) | (1 << WGM13) | (1 << WGM12) | (1 << WGM11) | (1 << WGM10);
//     TCCR1B = (1 << CS10);
//     while (1) {
//         // do nothing
//     }
//     return 0;
// }

// void play() {
//     int notes[] = { 
//         NoteType::E, NoteType::HALF_NOTE,
//         NoteType::REST, NoteType::WHOLE_NOTE,
//         NoteType::F, NoteType::HALF_NOTE,
//         NoteType::G_SHARP, NoteType::WHOLE_NOTE
//     }; 

//     for (int i = 0; i < sizeof(notes); i += 2) {
//         int freq = notes[i];
//         int duration = notes[i + 1];

//         OCR1A = 16000000 / (freq * 256 * 2);

//         // Generate a frequency of 'freq' using TCCR1A and TCCR1B.
        
//     }
// }

enum NoteType {
    C = 261,
    D = 294,
    E = 329,
    F = 349,
    G = 391,
    A = 440,
    B = 493,
    C_SHARP = 277,
    D_SHARP = 311,
    F_SHARP = 370,
    G_SHARP = 415,
    A_SHARP = 466,
    C_FLAT = 277,
    D_FLAT = 311,
    F_FLAT = 370,
    G_FLAT = 415,
    A_FLAT = 466,
    REST = 0,

    WHOLE_NOTE = 1000,
    HALF_NOTE = NoteType::WHOLE_NOTE / 2,
    QUARTER_NOTE =  NoteType::HALF_NOTE / 2,
    EIGHTH_NOTE = NoteType::QUARTER_NOTE / 2,
};

const long CPUFREQ = 16000000;
const uint16_t TIMER1_PRESCALER = 8;

#line 109 "c:\\atmega\\projects\\waveform\\waveform.ino"
void delay(int length);
#line 117 "c:\\atmega\\projects\\waveform\\waveform.ino"
int main(void);
#line 109 "c:\\atmega\\projects\\waveform\\waveform.ino"
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
            Notes::NoteC4_SHARP, Notes::WHOLE_NOTE,
            
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

            OCR1A = 16000000 / (freq * TIMER1_PRESCALER * 2);     
            delay(duration);   
        }

        _delay_ms(2500);

        while (1) {
            //
        }

    }
}
