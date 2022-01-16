#include <FastLED.h>
#define lct 120
#define DATA_PIN 2
CRGB leds[lct];

int L = 0;

void setup() {
  Serial.begin(115200);
  delay(2000);

  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, lct);  // GRB ordering is typical
}
void loop() {
  if (Serial.available()) {
    leds[L] = CRGB(0, 0, 0);
    L = Serial.parseInt();
    leds[L] = CRGB(0, 255, 0);
    FastLED.show();
  }
}
