#include "constants.h"
#include <Wire.h>
#include "SSD1306Wire.h"
#include "animations/main.h"

SSD1306Wire display(0x3c, SDA, SCL);  // ADDRESS, SDA, SCL

void setupDisplay() {
  display.init();
  display.flipScreenVertically();
}

void animateBitmap(const unsigned char *bitmapArray[], int frames,
                   int frameDelay, int repetitions, int width, int height, int xPos, int yPos) {
  for (int j =0; j < repetitions; j++) {
    for (int i = 0; i < frames; i++) {
      display.clear();
      display.drawXbm(xPos, yPos, width, height, bitmapArray[i]);
      display.display();
      delay(frameDelay);
    }
  }
}

void setup() {
  setupDisplay();
}

void loop() {
  animateBitmap(cat, 28, 20, 2, 30, 30, (DISPLAY_WIDTH - 30) / 2, (DISPLAY_HEIGHT - 30) / 2);
  animateBitmap(skate, 28, 20, 2, 32, 32, (DISPLAY_WIDTH - 32) / 2, (DISPLAY_HEIGHT - 30) / 2);
  delay(2000);
}
