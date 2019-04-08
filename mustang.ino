#include <FastLED.h>

#define NUM_LEDS 18
#define DATA_PIN_A 30
#define DATA_PIN_B 32
#define DATA_PIN_C 34
#define DATA_PIN_D 36
#define DELAY 20
#define TRAIL 8

CRGB leds_A[NUM_LEDS];
CRGB leds_B[NUM_LEDS];
CRGB leds_C[NUM_LEDS];
CRGB leds_D[NUM_LEDS];
CRGB* leds[] = {leds_A,leds_B,leds_C,leds_D};
bool flip;
int index;
int offset;

void setup() {

  FastLED.addLeds<NEOPIXEL, DATA_PIN_A>(leds_A, NUM_LEDS);
  FastLED.addLeds<NEOPIXEL, DATA_PIN_B>(leds_B, NUM_LEDS);
  FastLED.addLeds<NEOPIXEL, DATA_PIN_C>(leds_C, NUM_LEDS);
  FastLED.addLeds<NEOPIXEL, DATA_PIN_D>(leds_D, NUM_LEDS);
  flip = false;
}


void loop() {
  for (int j = 0; j < NUM_LEDS; j++) {
    FastLED.clear();
    delay(DELAY);
    offset = 0;
    for (int i = 0; i < 4; i++) {
      if (flip == true) {
        index = NUM_LEDS - j -1 - offset;
        flip = false;
      }
      else {
        index = j + offset;
        flip = true;
      }
      offset++;

      if (index > 0) {
        for (int k = 1; k < TRAIL; k++) {
          if (flip == true) {
            leds[i][index-k] = CHSV(0, 255,(255-k*30));
          }
          else {
            leds[i][index+k] = CHSV(0, 255,(255-k*30));
          }
        }
        
        
      }
      leds[i][index] = CHSV(0, 255, 255);
      
      FastLED.show();
    }
  }
  
  
}