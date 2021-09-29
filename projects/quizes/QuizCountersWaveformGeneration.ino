// int main() {
//     // Set timer counter to empty
//     TCNT0 = 0;

//     TCCR0B |= (1 << WGM01); // Set CTC mode

//     // Enable the 256 prescaler for TCCR0B
//     TCCR0B |= (1 << 0x05);

//     TIMSK0 |= (1 << OCIE0A); // Enable the compare match interrupt

//     return 0;
// }