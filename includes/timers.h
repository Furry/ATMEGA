// // Timer0 8-bit PWM
// // Timer1 16-bit PWM
// // Timer2 8-bit PWM

// // Prescalers control overflow speed.

// // Timer0 Prescaler:
//     // 1:1
//     // 2:8
//     // 3:64
//     // 4:256
//     // 5:1024

// class TimerManager {
//     public:
//         const static int ClockSpeed = 16000000;

//         static startTimer() {
            
//         };
// };

// class Timer0 {
//     public:
//         const static enum Prescaler {
//             Prescaler0 = 1,
//             Prescaler8 = 8,
//             Prescaler64 = 64,
//             Prescaler256 = 256,
//             Prescaler1024 = 1024
//         };

//         static float timerSpeed(Timer0::Prescaler prescaler) {
//             return (float) TimerManager::ClockSpeed / (float) prescaler;
//         }

//         static float interuptFreq(Timer0::Prescaler prescaler, uint8_t compareRegister) {
//             return (float) TimerManager::ClockSpeed / ((float) prescaler * ((float) compareRegister + (float) 1));
//         }

//         static void init(Timer0::Prescaler prescaler) {
//             TCCR0A = 0x00;
//         }