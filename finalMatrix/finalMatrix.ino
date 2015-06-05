const int SER = 8;
const int LATCH = 9;
const int CLK = 10;

int seq[16] = {
  B10000111, B10001011, B10001101, B10001110,
  B01001110, B01001101, B01001011, B01000111,
  B00100111, B00101011, B00101101, B00101110,
  B00011110, B00011101, B00011011, B00010111
};

/*
Define alphabet here
*/

/*
void display(String word) {
  for (int i = 0; i < word.length(); i++) {
    digitalWrite(LATCH, LOW);
    shiftOut(SER, CLK, LSBFIRST, /* letter */);
    digitalWrite(LATCH, HIGH);
  }
}
*/

void setup() {
  pinMode(SER, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLK, OUTPUT);
}

void loop() {
  for (int i = 0; i < 16; i++) {
    digitalWrite(LATCH, LOW);
    shiftOut(SER, CLK, LSBFIRST, seq[i]);
    digitalWrite(LATCH, HIGH);
    delay(100);
  }
  for (int i = 15; i >= 0; i--) {
    digitalWrite(LATCH, LOW);
    shiftOut(SER, CLK, LSBFIRST, seq[i]);
    digitalWrite(LATCH, HIGH);
    delay(100);
  }
}
