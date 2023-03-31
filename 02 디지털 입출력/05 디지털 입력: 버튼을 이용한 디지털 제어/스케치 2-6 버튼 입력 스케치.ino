#define PUSH_BTN 4

int value = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(PUSH_BTN, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  value = digitalRead(PUSH_BTN);
  Serial.println(value);
  delay(100);
}
