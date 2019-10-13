#include <FastLED.h>

#define NUM_LEDS 20
#define LED_PIN 2

CRGB led[NUM_LEDS];

void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<NEOPIXEL, LED_PIN>(led, NUM_LEDS);
}

void loop() {
  // put your main code here, to run repeatedly:

}
