#include <FastLED.h>
#define lct 120
#define x 0
#define y 1
#define cx 122
#define cy 90
#define DATA_PIN 2
#include "coords.h"
CRGB leds[lct];

void setup() {
  Serial.begin(115200);
  delay(2000);

  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, lct);  // GRB ordering is typical
}
void loop() {
  for (int L = 0; L < lct; L++) {

    //rainbow inward circle
    leds[L] = CHSV(millis() / 10 + 3 * sqrt(sq(coords[L][x] - cx) + sq(coords[L][y] - cy)), 255, 100);

    //inward hard edge circle
    //    if (((byte)(millis() / 2 + 3 * sqrt(sq(coords[L][x] - cx) + sq(coords[L][y] - cy)))) < 20) {
    //      leds[L] = CRGB(255, 0, 255);
    //    } else {
    //      leds[L] = CRGB(0, 0, 0);
    //    }


  }
  FastLED.show();
}
