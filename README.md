# Bitmap Animations with ESP32 and ssd1306 oled

This project demonstrates a simple example of animating bitmap arrays (similar to GIFs) using an ESP32 and the powerful ThingPulse `esp8266-oled-ssd1306` library. The code showcases how to display animated images on an OLED screen by cycling through bitmap frames.

## Features

- Animates bitmaps using an OLED display connected to an ESP32.
- Supports multiple animations with adjustable frame rate, position, and repetitions.
- Uses the `SSD1306Wire` driver from the ThingPulse library to interface with the OLED screen.

## Hardware Requirements

- ESP32 development board
- OLED Display (128x64 or similar) with I2C interface
- Connecting wires (SDA, SCL)

## Software Requirements

- Arduino IDE with ESP32 board package installed
- [ThingPulse/esp8266-oled-ssd1306](https://github.com/ThingPulse/esp8266-oled-ssd1306) library

## Setup Instructions

1. Install the necessary libraries in the Arduino IDE:
   - `ThingPulse/esp8266-oled-ssd1306` library
2. Wire the OLED display to the ESP32:
   - **SDA** to ESP32 SDA pin
   - **SCL** to ESP32 SCL pin
3. Upload the provided code to your ESP32.

## Code Overview

- **`setupDisplay()`**: Initializes and sets up the OLED display for use.
- **`animateBitmap()`**: Animates a bitmap array by cycling through each frame, clearing the display, drawing the bitmap, and updating the screen.

```cpp
void animateBitmap(const unsigned char *bitmapArray[], int frames, int frameDelay, int repetitions, int width, int height, int xPos, int yPos);
```

Parameters:

- `bitmapArray[]`: Array containing the bitmaps for animation.
- `frames`: Number of frames in the animation.
- `frameDelay`: Delay between frames (in milliseconds).
- `repetitions`: How many times the animation repeats.
- `width`, `height`: Size of the bitmap to display.
- `xPos`, `yPos`: Position of the bitmap on the screen.

In the `loop()` function, two animations (`cat` and `skate`) are displayed consecutively with a small delay between them.

## Example Usage

This code animates two different bitmaps (`cat` and `skate`), each with 28 frames, a 20ms delay per frame, and repeated twice at the center of the screen.

## References

- ThingPulse OLED SSD1306 library: [GitHub Repository](https://github.com/ThingPulse/esp8266-oled-ssd1306)
