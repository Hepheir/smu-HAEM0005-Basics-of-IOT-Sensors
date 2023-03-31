#define LED_COUNT 3

int LED[LED_COUNT] = { 2, 4, 6 };
int DELAY[LED_COUNT] = { 500, 300, 500 };

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
    delay(DELAY[i]);
    digitalWrite(LED[i], LOW);
    delay(DELAY[i]);
  }
}
