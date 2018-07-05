#include "FastLED.h"

#define NUM_LEDS 24
#define DATA_PIN 6
CRGB leds[NUM_LEDS];
#define BRIGHTNESS  64

uint8_t hue = 5;

void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);
}

void loop() {
  EVERY_N_SECONDS(1) {
    hue++;
  }

  fill_solid(leds, NUM_LEDS, CHSV(hue, 0, 50));
  
  FastLED.show();
}
