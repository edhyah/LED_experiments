/*
 * Final 24x8 LED Matrix Code
 * by Edward Ahn 2015
 *
 */
 
// Arduino Pins
const int SER = 8;
const int LATCH = 9;
const int CLK = 10;

// Row Values
const int ROWS[] = {1, 2, 4, 8, 16, 32, 64, 128};

// Alphabet and Alphabet-Related Symbols
const int ALPHA_WIDTH = 5;
const byte SYM_A[] = {B01110000, B10001000, B10001000, B10001000, B11111000, \
  B10001000, B10001000, B10001000};
const byte SYM_B[] = {B11110000, B10001000, B10001000, B11110000, B10001000, \
  B10001000, B10001000, B11110000};
const byte SYM_C[] = {B01110000, B10001000, B10000000, B10000000, B10000000, \
  B10000000, B10001000, B01110000};
const byte SYM_D[] = {B11110000, B10001000, B10001000, B10001000, B10001000, \
  B10001000, B10001000, B11110000};
const byte SYM_E[] = {B11111000, B10000000, B10000000, B11110000, B10000000, \
  B10000000, B10000000, B11111000};
const byte SYM_F[] = {B11111000, B10000000, B10000000, B11110000, B10000000, \
  B10000000, B10000000, B10000000};
const byte SYM_G[] = {B01110000, B10001000, B10000000, B10000000, B10111000, \
  B10001000, B10001000, B01110000};
const byte SYM_H[] = {B10001000, B10001000, B10001000, B11111000, B10001000, \
  B10001000, B10001000, B10001000};
const byte SYM_I[] = {B11111000, B00100000, B00100000, B00100000, B00100000, \
  B00100000, B00100000, B11111000};
const byte SYM_J[] = {B11111000, B00010000, B00010000, B00010000, B00010000, \
  B00010000, B10010000, B01100000};
const byte SYM_K[] = {B10001000, B10010000, B10100000, B11000000, B11000000, \
  B10100000, B10010000, B10001000};
const byte SYM_L[] = {B10000000, B10000000, B10000000, B10000000, B10000000, \
  B10000000, B10000000, B11111000};
const byte SYM_M[] = {B10001000, B10001000, B11011000, B10101000, B10001000, \
  B10001000, B10001000, B10001000, B10001000};
const byte SYM_N[] = {B10001000, B10001000, B11001000, B10101000, B10011000, \
  B10001000, B10001000, B10001000};
const byte SYM_O[] = {B01110000, B10001000, B10001000, B10001000, B10001000, \
  B10001000, B10001000, B01110000};
const byte SYM_P[] = {B11110000, B10001000, B10001000, B11110000, B10000000, \
  B10000000, B10000000, B10000000};
const byte SYM_Q[] = {B01110000, B10001000, B10001000, B10001000, B10001000, \
  B10101000, B10011000, B01110000};
const byte SYM_R[] = {B11110000, B10001000, B10001000, B11110000, B11000000, \
  B10100000, B10010000, B10001000};
const byte SYM_S[] = {B01110000, B10001000, B10000000, B01110000, B00001000, \
  B00001000, B10001000, B01110000};
const byte SYM_T[] = {B11111000, B00100000, B00100000, B00100000, B00100000, \
  B00100000, B00100000, B00100000};
const byte SYM_U[] = {B10001000, B10001000, B10001000, B10001000, B10001000, \
  B10001000, B10001000, B01110000};
const byte SYM_V[] = {B10001000, B10001000, B10001000, B10001000, B10001000, \
  B10001000, B01010000, B00100000};
const byte SYM_W[] = {B10001000, B10001000, B10001000, B10001000, B10101000, \
  B10101000, B10101000, B01010000};
const byte SYM_X[] = {B10001000, B10001000, B01010000, B00100000, B01010000, \
  B01010000, B10001000, B10001000};
const byte SYM_Y[] = {B10001000, B10001000, B01010000, B00100000, B00100000, \
  B00100000, B00100000, B00100000};
const byte SYM_Z[] = {B11111000, B00001000, B00010000, B00100000, B01000000, \
  B10000000, B10000000, B11111000};
const byte SYM_QUERY[] = {B01110000, B10001000, B10001000, B00010000, \
  B00100000, B00100000, 0, B00100000};
const byte SYM_PER[] = {0, 0, 0, 0, 0, 0, 0, B01000000};

// Number and Number-Related Symbols
const int NUM_WIDTH = 4;
const byte SYM_1[] = {B00100000, B00100000, B00100000, B00100000, B00100000, \
  B00100000, B00100000, B00100000};
const byte SYM_2[] = {B11110000, B00010000, B00010000, B11110000, B10000000, \
  B10000000, B10000000, B11110000};
const byte SYM_3[] = {B11110000, B00010000, B00010000, B11110000, B00010000, \
  B00010000, B00010000, B11110000};
const byte SYM_4[] = {B10010000, B10010000, B10010000, B11110000, B00010000, \
  B00010000, B00010000, B00010000};
const byte SYM_5[] = {B11110000, B10000000, B10000000, B11110000, B00010000, \
  B00010000, B00010000, B11110000};
const byte SYM_6[] = {B11110000, B10000000, B10000000, B11110000, B10010000, \
  B10010000, B10010000, B11110000};
const byte SYM_7[] = {B11110000, B00010000, B00010000, B00010000, B00010000, \
  B00010000, B00010000, B00010000};
const byte SYM_8[] = {B11110000, B10010000, B10010000, B11110000, B10010000, \
  B10010000, B10010000, B11110000};
const byte SYM_9[] = {B11110000, B10010000, B10010000, B11110000, B00010000, \
  B00010000, B00010000, B11110000};
const byte SYM_COLON[] = {0, B01100000, B01100000, 0, 0, B01100000, \
  B01100000, 0};

void getData2(String text, int *data, int row) {
  data[0] = B11111111;
  data[1] = B11111111;
  data[2] = B11111111;
}

// Sets all elements in data to 0
void clearDataArray(int *data) {
  data[0] = 0;
  data[1] = 0;
  data[2] = 0;
}

// Pushes single letter of alphabet or alphabet-related symbols
// onto data array - helper function to getData
void pushAlpha(byte letter, int *data, int *count, int *reg) {
  data[*reg] = data[*reg] | letter >> (*count % 8);
  if (*count % 8 + ALPHA_WIDTH + 1 >= 8) {
    (*reg)++;
    if (*reg > 2) return;
    if (*count % 8 + ALPHA_WIDTH > 8) {
      data[*reg] = data[*reg] | letter << (8 - *count % 8);
    }
  }
  *count += ALPHA_WIDTH;
  (*count)++;
}

// Prepares data to contain integers that will be pushed
// onto shift registers to display column data for a given row
void getData(String text, int *data, int row) {
  int count = 0;
  int reg = 0;
  clearDataArray(data);
  for (int i = 0; i < text.length(); i++) {
    if (reg > 2) return;
    switch(text[i]) {
      case 'A':
        pushAlpha(SYM_A[row], data, &count, &reg);
        break;
      case 'B':
        pushAlpha(SYM_B[row], data, &count, &reg);
        break;
    }
  }
  return;
}

// Displays text onto matrix
void displayText(String text, int shift) {
  int data[3];
  int shiftDelay = 5;
  text.toUpperCase();
  for (int row = 0; row < 8; row++) {
    getData(text, data, row);
    digitalWrite(LATCH, LOW);
    shiftOut(SER, CLK, LSBFIRST, ~data[2]);
    shiftOut(SER, CLK, LSBFIRST, ~data[1]);
    shiftOut(SER, CLK, LSBFIRST, ~data[0]);
    shiftOut(SER, CLK, MSBFIRST, ROWS[row]);
    digitalWrite(LATCH, HIGH);
    delay(1);
  }
}

void setup() {
  pinMode(SER, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLK, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  displayText("babab", 0);
}
