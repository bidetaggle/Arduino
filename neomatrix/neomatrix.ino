#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#ifndef PSTR
 #define PSTR // Make Arduino Due happy
#endif

#define PIN 6
#define WIDTH 10
#define HEIGHT 6
#define DELAY 30

// Example for NeoPixel Shield.  In this application we'd like to use it
// as a 5x8 tall matrix, with the USB port positioned at the top of the
// Arduino.  When held that way, the first pixel is at the top right, and
// lines are arranged in columns, progressive order.  The shield uses
// 800 KHz (v2) pixels that expect GRB color data.
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(
  10, // width of NeoPixel matrix
  6,  // height of matrix
  PIN,
  /* matrix layout flags (see readme.md section neomatrix library for more explanations) */
  NEO_MATRIX_TOP  + NEO_MATRIX_RIGHT +
  NEO_MATRIX_ROWS + NEO_MATRIX_ZIGZAG,
  /* pixel type flags (see readme.md for neomatrix library more explanations) */
  NEO_GRB         + NEO_KHZ800
);

const uint16_t colors[] = { matrix.Color(255, 0, 0), matrix.Color(0, 255, 0), matrix.Color(0, 0, 255) };

void drawArrow(int x, int y, uint16_t color){
  matrix.drawLine(x  , y+3, x+4, y+3, color);
  matrix.drawLine(x+7, y+3, x+4, y  , color);
  matrix.drawLine(x+7, y+3, x+4, y+6, color);
}
void animationArrow(){
  for(int j=-2 ; j<HEIGHT-4 ; j++)
    for(int i=-WIDTH ; i<WIDTH ; i++){
      matrix.fillScreen(matrix.Color(21, 28, 47));
      drawArrow(i, j, matrix.Color(154, 205, 50));
      matrix.show();
      delay(50);
    }
  for(int j=-2 ; j<HEIGHT-4 ; j++)
    for(int i=-WIDTH ; i<WIDTH ; i++){
      matrix.fillScreen(matrix.Color(0,0,0));
      drawArrow(i, j, matrix.Color(25, 209, 233));
      matrix.show();
      delay(50);
    }
  for(int j=-2 ; j<HEIGHT-4 ; j++)
    for(int i=-WIDTH ; i<WIDTH ; i++){
      matrix.fillScreen(matrix.Color(36, 41, 46));
      drawArrow(i, j, matrix.Color(241, 200, 224));
      matrix.show();
      delay(50);
    }
}

void animationSpin(){
  for(int k=0 ; k<15 ; k++){
    for(int j=1 ; j<HEIGHT ; j++){
      matrix.fillScreen(0);
      matrix.drawLine(0, j, WIDTH-1, HEIGHT-1-j, colors[0]);
      matrix.show();
      delay(DELAY);
    }
    for(int i=1 ; i<WIDTH ; i++){
      matrix.fillScreen(0);
      matrix.drawLine(i, HEIGHT-1, WIDTH-1-i, 0, colors[1]);
      matrix.show();
      delay(DELAY);
    }
  }
}

void animationCircle(){
  for(int i=0 ; i<WIDTH/2 ; i++){
    matrix.fillScreen(0);
    matrix.drawCircle(WIDTH/2,HEIGHT/2,i,matrix.Color(241, 200, 224));
    matrix.show();
    delay(DELAY);
  }
}

void setup() {
  matrix.begin();
}

void loop() {
  animationArrow();
  animationSpin();
  animationCircle();
}
