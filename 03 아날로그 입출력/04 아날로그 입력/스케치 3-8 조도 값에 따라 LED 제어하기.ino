#define SENSOR_PIN 4

int sensorValue;

void setup() {
    Serial.begin(9600);
    pinMode(SENSOR_PIN, OUTPUT);
}

void loop() {
  sensorValue = analogRead(A0);

  Serial.println(sensorValue);

  if (sensorValue > 700) {
    digitalWrite(SENSOR_PIN, LOW);
  } else {
    digitalWrite(SENSOR_PIN, HIGH);
  }
}