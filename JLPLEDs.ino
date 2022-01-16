/*
   January 2022:
      found coordinates of each light
      programmed first patterns
*/
#include <FastLED.h>
#define DATA_PIN 2
#define lct 120
#define x 0
#define y 1
#define cx 122
#define cy 90
#define led leds[L]
#define coordx (coords[L][x] - cx)
#define coordy (coords[L][y] - cy)
#define letterJ (coordx + cx < 80)
#define letterL (coordx + cx >= 80 && coordx + cx < 150)
#define letterP (coordx + cx >= 150)
#include "coords.h"
CRGB leds[lct];
byte L;
unsigned long pixelTime[lct];

void setup() {
  Serial.begin(115200);
  delay(2000);

  memset(pixelTime, 0, lct * sizeof(unsigned long));

  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, lct);  // GRB ordering is typical
}
void loop() {
  for (L = 0; L < lct; L++) {

    //    //inward rainbow circle
    //    leds[L] = CHSV(millis() / 8 + 3 * sqrt(sq(coordx) + sq(coordy)), 255, 255);

    //    //outward rainbow circle
    //    leds[L] = CHSV(millis() / 8 - 3 * sqrt(sq(coordx) + sq(coordy)), 255, 255);

    //    //inward hard edge circle
    //    if (((byte)(millis() / 2 + 3 * sqrt(sq(coordx) + sq(coordy)))) < 20) {
    //      leds[L] = CRGB(255, 0, 255);
    //    } else {
    //      leds[L] = CRGB(0, 0, 0);
    //    }

    //    //outward hard edge circle
    //    if (((byte)(millis() / 2 - 3 * sqrt(sq(coordx) + sq(coordy)))) < 20) {
    //      leds[L] = CRGB(255, 0, 255);
    //    } else {
    //      leds[L] = CRGB(0, 0, 0);
    //    }

    //    inward circle
    //    byte d = ((byte)(millis() / 2 + 3 * sqrt(sq(coordx) + sq(coordy))));
    //    if (d < 30) {
    //      leds[L] = CRGB(150, (15 - abs(d - 15)) * 17, 255 );
    //    } else {
    //      leds[L] = CRGB(150, 0, 255);
    //    }

    //    //outward rainbow circle
    //    leds[L] = CHSV(millis() / 8 - 3 * sqrt(sq(coordx) + sq(coordy)), 255, 100);

    //    //outward circle
    //    byte d = ((byte)(millis() / 2 - 3 * sqrt(sq(coordx) + sq(coordy))));
    //    if (d < 30) {
    //      leds[L] = CRGB(150, (15 - abs(d - 15)) * 17, 255 );
    //    } else {
    //      leds[L] = CRGB(150, 0, 255);
    //    }

    //    //colorwheel
    //    leds[L] = CHSV((byte)(millis() / 10 + 255 * (PI + atan2(coordy, coordx)) / TWO_PI), 255, 255);

    //    //spinning wiper
    //    byte v = (millis() / 10 + 255 * (PI + atan2(coordy, coordx)) / TWO_PI);
    //    v = v < 25 ? 250 - v * 10 : 0;
    //    leds[L] = CHSV(0, 0, v);

    //    //radar screen
    //    byte v = (millis() / 10 + 255 * (PI + atan2(coordy, coordx)) / TWO_PI);
    //    if (v < 1) {
    //      pixelTime[L] = millis();
    //    }
    //    v = v < 25 ? 250 - v * 10 : 0;
    //
    //    if (millis() - pixelTime[L] < 1000) {
    //      leds[L] = CRGB(map(millis() - pixelTime[L], 0, 1000, 255, 0), 0, map(millis() - pixelTime[L], 0, 1000, 255, 0));
    //    } else {
    //      leds[L] = CRGB(v, v, v);
    //    }

    //    //4 direction wipers
    //    static CRGB color;
    //    int t = millis() % 4000;
    //    int d = 0;
    //    if (t < 1000) {
    //      if (L == 0 && t < 50) {
    //        color = CHSV(random(256), 255, 255);
    //      }
    //      d = -coordx + ( t - 500);
    //    } else  if (t < 2000) {
    //      if (L == 0 && t < 1050) {
    //        color = CHSV(random(256), 255, 255);
    //      }
    //      d = -coordy + (t - 1500) / 2;
    //    } else  if (t < 3000) {
    //      if (L == 0 && t < 2050) {
    //        color = CHSV(random(256), 255, 255);
    //      }
    //      d = -coordx - (t - 2500);
    //    } else {
    //      if (L == 0 && t < 3050) {
    //        color = CHSV(random(256), 255, 255);
    //      }
    //      d = -coordy - (t - 3500) / 2;
    //    }
    //    if (abs(d) < 10) {
    //      led = color;
    //    } else {
    //      led = CRGB(0, 0, 0);
    //    }

    //    //color by letters with sparkles
    //    if (random(200) == 0) {
    //      led = CRGB(255, 255, 255);
    //    } else {
    //      if (letterJ) {
    //        led = CRGB(255, 0, 0);
    //      }
    //      if (letterL) {
    //        led = CRGB(255, 0, 255);
    //      }
    //      if (letterP) {
    //        led = CRGB(0, 0, 255);
    //      }
    //    }

  } // end of led iteration for loop

  FastLED.show();
}
