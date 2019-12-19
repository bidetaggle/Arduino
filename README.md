# Basics

`git clone https://github.com/bidetaggle/Arduino.git` into your home directory because the Arduino IDE use the absolute path `~/Arduino/libraries`

# neomatrix library

## Matrix declaration: `Adafruit_NeoMatrix()` object

### 4th parameter: matrix layout flags

Add together as needed:

- Position of the FIRST LED in the matrix; pick two:
`NEO_MATRIX_TOP` or `NEO_MATRIX_BOTTOM` + `NEO_MATRIX_LEFT` or `NEO_MATRIX_RIGHT`

- LEDs arranged in rows or in vertical columns, respectively; pick one:
`NEO_MATRIX_ROWS` or `NEO_MATRIX_COLUMNS`

- Matrix lines order, interlaced display or all pixels lines in the same direction; pick one:
`NEO_MATRIX_PROGRESSIVE` or `NEO_MATRIX_ZIGZAG`

Full example: `NEO_MATRIX_TOP  + NEO_MATRIX_RIGHT + NEO_MATRIX_ROWS + NEO_MATRIX_ZIGZAG`
Position of the first led in the matrix is the top right corner, leds arranged in rows and the display is interlaced

### 5th parameter: pixel type flags

Add together as needed:

- `NEO_KHZ800`: 800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
- `NEO_KHZ400`: 400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
- `NEO_GRB`:    Pixels are wired for GRB bitstream (most NeoPixel products)
- `NEO_GRBW`:   Pixels are wired for GRBW bitstream (RGB+W NeoPixel products)
- `NEO_RGB`:    Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)

Full example: `NEO_GRB + NEO_KHZ800`
