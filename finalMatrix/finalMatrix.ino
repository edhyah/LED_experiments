/*
 * Final 24x8 LED Matrix Code
 * by Edward Ahn
 *
 */
 
// Arduino Pins
const int SER = 8;
const int LATCH = 9;
const int CLK = 10;

// Row Values
const int ROWS[] = {1, 2, 4, 8, 16, 32, 64, 128};

// Alphabet
#define A {B01110000, B10001000, B10001000, B10001000, B11111000, B10001000, \
  B10001000, B10001000}
#define B {B11110000, B10001000, B10001000, B11110000, B10001000, B10001000, \
  B10001000, B11110000}
#define C {B01110000, B10001000, B10000000, B10000000, B10000000, B10000000, \
  B10001000, B01110000}
#define D {

void setup() {
  pinMode(SER, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLK, OUTPUT);
  Serial.begin(9600);
  
  /*
  digitalWrite(LATCH, LOW);
  shiftOut(SER, CLK, LSBFIRST, B11111111);
  shiftOut(SER, CLK, LSBFIRST, B11111111);
  shiftOut(SER, CLK, LSBFIRST, B01111111);
  shiftOut(SER, CLK, MSBFIRST, 1);
  digitalWrite(LATCH, HIGH);
  */
}

void loop() {
  /*
  for (int row = 0; row < 8; row++) {
    digitalWrite(LATCH, LOW);
    shiftOut(SER, CLK, LSBFIRST, B11111111);
    shiftOut(SER, CLK, LSBFIRST, B11111111);
    shiftOut(SER, CLK, LSBFIRST, B11011111);
    shiftOut(SER, CLK, MSBFIRST, L[row]);
    digitalWrite(LATCH, HIGH);
    delay(1000);
  }
  */
}
