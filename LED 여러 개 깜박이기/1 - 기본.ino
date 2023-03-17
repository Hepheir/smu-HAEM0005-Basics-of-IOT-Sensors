int LED[3] = { 2, 4, 6 };

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 3; i++) {
    pinMode(LED[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int i;
  for (i = 0; i < 3; i++) {
    digitalWrite(LED[i], HIGH);
  }
  delay(1000);
  for (i = 0; i < 3; i++) {
    digitalWrite(LED[i], LOW);
  }
  delay(1000);
}
