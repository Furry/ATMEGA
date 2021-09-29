#include <C:/atmega/includes/iom328p.h>

// Create a hashmap containing a uint_8 as the key and a tuple with a two uint_8s as the value.
// The first uint_8 is the register address, the second is the value to write to the register.
// This is used to set the registers on the device.
typedef struct {
  uint_8 regAddr;
  uint_8 regValue;
} regTuple;

