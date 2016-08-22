#include <TM1638.h>
#include <Wire.h>
#include <ACROBOTIC_SSD1306.h>

TM1638 module(12, 13, 14);

void setup() {
  module.setDisplayToDecNumber(13092016, 0);
  Wire.begin();  
  oled.init();
  oled.clearDisplay();
  oled.setTextXY(0,2);
  oled.putString("1309 - 2016");
  oled.setTextXY(1,0);
  oled.putString("Ukraine");
  oled.setTextXY(2,0);
  oled.putString("Kiev");
  oled.setTextXY(3,0);
  oled.putString("Alef");
}

void loop() {
  byte keys = module.getButtons();
  module.setLEDs(((keys & 0xF0) << 8) | (keys & 0xF));
}
