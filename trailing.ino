#include <FastLED.h>
#include <FastLED_NeoMatrix.h>
#include <gamma.h>
#include <math.h>


#include <Adafruit_GFX.h>

#define PIN 30
#define TRAIL 10
#define DELAY 30

#define mw 37
#define mh 4
#define NUMMATRIX (mw*mh)
#define MULTIPLES 4

CRGB leds[NUMMATRIX];
// Define matrix width and height.
FastLED_NeoMatrix *matrix = new FastLED_NeoMatrix(leds, mw, mh, 
  NEO_MATRIX_TOP     + NEO_MATRIX_LEFT +
    NEO_MATRIX_ROWS + NEO_MATRIX_ZIGZAG);

void setup() {
  FastLED.addLeds<NEOPIXEL,PIN>(leds, NUMMATRIX);
  matrix->begin();
  matrix->setBrightness(20);
}

void loop() {
  int j = 0;
  for (int w=-7; w < mw; w++) {
    delay(DELAY);
    if (j < TRAIL) {
      j++;
    }
    else {
      if (mw-w > j) {
        j = 0;
        delay(100);
      }
      
    }
    int r = 10+j*25;
    matrix->drawLine(w,0,w+8,4, matrix->Color(r,r,r));
    matrix->show();
  }
  matrix->clear();
}
