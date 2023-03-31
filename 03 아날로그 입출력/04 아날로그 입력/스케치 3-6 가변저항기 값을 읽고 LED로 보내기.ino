#define LED_PIN 13

int value = 0;

void setup() {
    Serial.begin(9600);
}

void loop() {
  value = analogRead(A0);
  digitalWrite(LED_PIN, HIGH);
  delay(value);
  digitalWrite(LED_PIN, LOW);
  delay(value);
}