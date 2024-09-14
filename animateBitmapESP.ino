#include "constants.h"
#include <Wire.h>
#include "SSD1306Wire.h"
#include "animations/main.h"

SSD1306Wire display(0x3c, SDA, SCL);  // ADDRESS, SDA, SCL

// Variables for FPS calculation and toggle
unsigned long previousMillis = 0;
int frameCount = 0;
float fps = 0;
bool showFPS = false;  // Toggle variable to show/hide FPS
// The fps should be 1000 / frameDelay if the performance is good.
// If you want an specific frame rate you can set it like this: int frameDelay = 1000 / desiredFPS;

void setupDisplay() {
  display.init();
  display.flipScreenVertically();
}

// Function to animate a bitmap and update FPS
void animateBitmap(const unsigned char *bitmapArray[], int frames,
                   int frameDelay, int repetitions, int width, int height, int xPos, int yPos) {
  for (int j = 0; j < repetitions; j++) {
    for (int i = 0; i < frames; i++) {
      display.clear();  // Clear the screen for the new frame
      
      // Draw the animation frame
      display.drawXbm(xPos, yPos, width, height, bitmapArray[i]);
      
      // If FPS display is enabled, update FPS
      if (showFPS) {
        updateFPS();
      }
      
      // Display everything
      display.display();
      
      delay(frameDelay);  // Delay for frame rate
    }
  }
}

// Function to calculate and display FPS
void updateFPS() {
  frameCount++;
  unsigned long currentMillis = millis();
  
  // Calculate FPS every second
  if (currentMillis - previousMillis >= 1000) {
    fps = frameCount / ((currentMillis - previousMillis) / 1000.0);
    previousMillis = currentMillis;
    frameCount = 0;
  }
  
  // Display FPS in the top-left corner
  display.setFont(ArialMT_Plain_10);
  display.drawString(0, 0, "FPS: " + String(fps, 1));
}

void setup() {
  setupDisplay();
}

void loop() {
  animateBitmap(cat, 28, 16, 2, 30, 30, (DISPLAY_WIDTH - 30) / 2, (DISPLAY_HEIGHT - 30) / 2);
  animateBitmap(skate, 28, 16, 2, 32, 32, (DISPLAY_WIDTH - 32) / 2, (DISPLAY_HEIGHT - 30) / 2);
  // delay(2000);
}
