#include <C:/atmega/includes/iom328p.h>

// Toggle a bit on or off when given a register and bit number.
// void toggleBit(int selector, int bit) {
//     switch (selector) {
//         case 0x0B:
//             auto reg = PORTD;
//             PORTD = (PORTD ^ (1 << bit));
//             break;
//         default:
//             break;
//         }
//     PORTD = ~PORTD;
// }

void bitFlip(uint8_t regester, uint8_t bit) {
    _SFR_IO8(regester) ^= (1 << bit);
}

// Give a bit at a set position an on or off value with a boolean.
// void setBit(volatile uint8_t* reg, uint8_t bit, bool on) {
//     uint8_t mask = 1 << bit;
//     if (on) {
//         reg |= mask;
//     } else {
//         reg &= ~mask;
//     }
// }
