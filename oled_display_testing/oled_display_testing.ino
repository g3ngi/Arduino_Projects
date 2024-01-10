#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // initialize with the I2C addr 0x3C
  display.clearDisplay(); // Clear the buffer
  fillDisplay(); // Fills the display line by line
}

void loop() {
}

void fillDisplay(void) {

  display.clearDisplay();
  for (int j = 0; j < 63; j++) {
    for (int i = 0; i < 127; i++) {
      display.drawPixel(i, j, WHITE);
    }
    display.display();
    delay(2);
  }
}