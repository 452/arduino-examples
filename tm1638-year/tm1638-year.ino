#include <TM1638.h>

#define PIN_DATA 12   //D6
#define PIN_CLOCK 13  //D7
#define PIN_STROBE 14 //D5

TM1638 module(PIN_DATA, PIN_CLOCK, PIN_STROBE);

// http://www.uize.com/examples/seven-segment-display.html

const byte MESSAGE[] = {
  0b01101111, // 9
  0b01111111, // 8
  0b11100110, // 4
  0b1101110,  // Y
  0b01111001, // E
  0b01110111, // A
  0b01110111, // R 
  //0b01010000,  // r
  0b01101101  // S
};

void setup() {
  module.setDisplay(MESSAGE, 8);
}

void loop() {
  byte keys = module.getButtons();
  module.setLEDs(((keys & 0xF0) << 8) | (keys & 0xF));
}
