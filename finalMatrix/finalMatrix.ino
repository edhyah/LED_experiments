const int SER = 8;
const int LATCH = 9;
const int CLK = 10;

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
  digitalWrite(LATCH, LOW);
  shiftOut(SER, CLK, LSBFIRST, B10101010);
  shiftOut(SER, CLK, LSBFIRST, 0);
  shiftOut(SER, CLK, LSBFIRST, 0);
  shiftOut(SER, CLK, LSBFIRST, 0);
  digitalWrite(LATCH, HIGH);
  delay(1);
}
