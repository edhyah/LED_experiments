const int SER = 8;
const int LATCH = 9;
const int CLK = 10;

void setup() {
  pinMode(SER, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLK, OUTPUT);
}

void loop() {
  digitalWrite(LATCH, LOW);
  shiftOut(SER, CLK, LSBFIRST, B10101010);
  digitalWrite(LATCH, HIGH);
  delay(2000);
  
  digitalWrite(LATCH, LOW);
  shiftOut(SER, CLK, LSBFIRST, B01010101);
  digitalWrite(LATCH, HIGH);
  delay(2000);
}
