/*
 * 24x8 LED Matrix Code
 * Copyright 2015 Edward Ahn.
 *
 */
 
// Arduino Pins
const int SER = 8;
const int LATCH = 9;
const int CLK = 10;

// Row Values
const int ROWS[] = {1, 2, 4, 8, 16, 32, 64, 128};

// Alphabet and 5-Bit Width Symbols
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
const byte SYM_EXC[] = {B00100000, B00100000, B00100000, B00100000, \
  B00100000, B00100000, 0, B00100000};

// Numbers and 4-Bit Width Symbols
const int NUM_WIDTH = 4;
const byte SYM_0[] = {B01110000, B10001000, B10001000, B10001000, B10001000, \
  B10001000, B10001000, B01110000};
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
const byte SYM_SPACE[] = {0, 0, 0, 0, 0, 0, 0, 0};

// Miscellaneous 2-Bit Width Symbols
const int MISC_WIDTH = 2;
const byte SYM_COLON[] = {0, B11000000, B11000000, 0, 0, B11000000, \
  B11000000, 0};

// Sets all elements in data to 0
void clearDataArray(int *data) {
  data[0] = 0;
  data[1] = 0;
  data[2] = 0;
}

// Pushes single letter of alphabet or 5-bit width symbols
// onto data array - helper function to getData
void pushAlpha(byte letter, int *data, int *count, int *reg) {
  int width = ALPHA_WIDTH;
  if (count < 0) {
    if (-*count > ALPHA_WIDTH) {
      *count += ALPHA_WIDTH;
      return;
    } else {
      letter << -(*count);
      width -= -(*count);
      *count = 0;
    }
  }
  data[*reg] = data[*reg] | letter >> (*count % 8);
  if (*count % 8 + ALPHA_WIDTH + 1 >= 8) {
    (*reg)++;
    if (*reg > 2) return;
    if (*count % 8 + ALPHA_WIDTH > 8) {
      data[*reg] = data[*reg] | letter << (8 - *count % 8);
    }
  }
  *count += width;
  (*count)++;
  
  // code that works
  /*
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
  */
}

// Pushes single number or 2-bit width symbols onto
// data array - helper function to getData
void pushNum(byte number, int *data, int *count, int *reg) {
  data[*reg] = data[*reg] | number >> (*count % 8);
  if (*count % 8 + NUM_WIDTH + 1 >= 8) {
    (*reg)++;
    if (*reg > 2) return;
    if (*count % 8 + NUM_WIDTH > 8) {
      data[*reg] = data[*reg] | number << (8 - *count % 8);
    }
  }
  *count += NUM_WIDTH;
  (*count)++;
}

// Pushes miscellanceous character onto data
// array - helper function to getData
void pushMisc(byte chr, int *data, int *count, int *reg) {
  data[*reg] = data[*reg] | chr >> (*count % 8);
  if (*count % 8 + MISC_WIDTH + 1 >= 8) {
    (*reg)++;
    if (*reg > 2) return;
    if (*count % 8 + MISC_WIDTH > 8) {
      data[*reg] = data[*reg] | chr << (8 - *count % 8);
    }
  }
  *count += MISC_WIDTH;
  (*count)++;
}

// Prepares data to contain integers that will be pushed
// onto shift registers to display column data for a given row
void getData(String text, int *data, int row, int shift) {
  int count = 0;
  int reg = 0;
  if (shift < 24) {
    count = 24 - shift - 1;
    if (shift < 8) reg = 2;
    else if (shift < 16) reg = 1;
  } else {
    count = shift - 24 - 1;
  }
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
      case 'C':
        pushAlpha(SYM_C[row], data, &count, &reg);
        break;
      case 'D':
        pushAlpha(SYM_D[row], data, &count, &reg);
        break;
      case 'E':
        pushAlpha(SYM_E[row], data, &count, &reg);
        break;
      case 'F':
        pushAlpha(SYM_F[row], data, &count, &reg);
        break;
      case 'G':
        pushAlpha(SYM_G[row], data, &count, &reg);
        break;
      case 'H':
        pushAlpha(SYM_H[row], data, &count, &reg);
        break;
      case 'I':
        pushAlpha(SYM_I[row], data, &count, &reg);
        break;
      case 'J':
        pushAlpha(SYM_J[row], data, &count, &reg);
        break;
      case 'K':
        pushAlpha(SYM_K[row], data, &count, &reg);
        break;
      case 'L':
        pushAlpha(SYM_L[row], data, &count, &reg);
        break;
      case 'M':
        pushAlpha(SYM_M[row], data, &count, &reg);
        break;
      case 'N':
        pushAlpha(SYM_N[row], data, &count, &reg);
        break;
      case 'O':
        pushAlpha(SYM_O[row], data, &count, &reg);
        break;
      case 'P':
        pushAlpha(SYM_P[row], data, &count, &reg);
        break;
      case 'Q':
        pushAlpha(SYM_Q[row], data, &count, &reg);
        break;
      case 'R':
        pushAlpha(SYM_R[row], data, &count, &reg);
        break;
      case 'S':
        pushAlpha(SYM_S[row], data, &count, &reg);
        break;
      case 'T':
        pushAlpha(SYM_T[row], data, &count, &reg);
        break;
      case 'U':
        pushAlpha(SYM_U[row], data, &count, &reg);
        break;
      case 'V':
        pushAlpha(SYM_V[row], data, &count, &reg);
        break;
      case 'W':
        pushAlpha(SYM_W[row], data, &count, &reg);
        break;
      case 'X':
        pushAlpha(SYM_X[row], data, &count, &reg);
        break;
      case 'Y':
        pushAlpha(SYM_Y[row], data, &count, &reg);
        break;
      case 'Z':
        pushAlpha(SYM_Z[row], data, &count, &reg);
        break;
      case '?':
        pushAlpha(SYM_QUERY[row], data, &count, &reg);
        break;
      case '.':
        pushAlpha(SYM_PER[row], data, &count, &reg);
        break;
      case '!':
        pushAlpha(SYM_EXC[row], data, &count, &reg);
        break;
      case '0':
        pushNum(SYM_0[row], data, &count, &reg);
        break;
      case '1':
        pushNum(SYM_1[row], data, &count, &reg);
        break;
      case '2':
        pushNum(SYM_2[row], data, &count, &reg);
        break;
      case '3':
        pushNum(SYM_3[row], data, &count, &reg);
        break;
      case '4':
        pushNum(SYM_4[row], data, &count, &reg);
        break;
      case '5':
        pushNum(SYM_5[row], data, &count, &reg);
        break;
      case '6':
        pushNum(SYM_6[row], data, &count, &reg);
        break;
      case '7':
        pushNum(SYM_7[row], data, &count, &reg);
        break;
      case '8':
        pushNum(SYM_8[row], data, &count, &reg);
        break;
      case '9':
        pushNum(SYM_9[row], data, &count, &reg);
        break;
      case ' ':
        pushNum(SYM_SPACE[row], data, &count, &reg);
        break;
      case ':':
        pushMisc(SYM_COLON[row], data, &count, &reg);
        break;
    }
  }
  return;
}

// Displays text onto matrix
void displayText(String text, int shift) {
  int data[3];
  text.toUpperCase();
  for (int row = 0; row < 8; row++) {
    getData(text, data, row, shift);
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
}

void loop() {
  String text = "HelloWorld";
  unsigned long time;
  //displayText(text, 0);
  int total = 24 + text.length();
  //int total = 24;
  for (int i = 0; i < total; i++) {
    time = millis();
    while (millis() - time < 50) displayText(text, i);
  }
}
