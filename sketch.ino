#include <Adafruit_NeoPixel.h>

#define LED_PIN 6        // Data Pin
#define LED_COUNT 16     // Number of LEDs in your RGB strip

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show();  // Initialize all pixels to 'off'
}

void loop() {
  // Flicker effect
  for (int j = 0; j < 10; j++) {  // Repeat the flicker 10 times
    flickerEffect(strip.Color(255, 0, 0));  // Red color for flickering
    delay(500);  // Delay between flickers
  }

  // Reset to off
  setColor(strip.Color(0, 0, 0));
  delay(1000);  // Delay for 1 second before starting again
}

void flickerEffect(uint32_t flickerColor) {
  for (int i = 0; i < LED_COUNT; i++) {
    if (random(3) == 0) {  // Randomly flicker this LED
      strip.setPixelColor(i, flickerColor);  // Use flickerColor parameter
    } else {
      strip.setPixelColor(i, strip.Color(0, 0, 0));  // Off
    }
  }
  strip.show();
}

void setColor(uint32_t color) {
  for (int i = 0; i < LED_COUNT; i++) {
    strip.setPixelColor(i, color);
  }
  strip.show();
}
