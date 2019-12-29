#include <Adafruit_NeoPixel.h>

#define PIN       6
#define NUMPIXELS 240
#define DELAY 20

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(A0);
  pixels.clear();
  pixels.setPixelColor(sensorValue, pixels.Color(0, 150, 0));
  pixels.show();
  delay(DELAY);
}
