#define PIN_BTN 4
#define PIN_LED 13

int buttonState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_BTN, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(PIN_BTN);
  if (buttonState == HIGH) {
    digitalWrite(PIN_LED, HIGH);
  }
  else {
    digitalWrite(PIN_LED, LOW);
  }
}
