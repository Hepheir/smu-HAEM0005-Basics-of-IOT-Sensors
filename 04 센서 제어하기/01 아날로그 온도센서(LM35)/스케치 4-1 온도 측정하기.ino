/*
  Author: 202115064 김동주 <hepheir@gmail.com>
*/

#define PIN A0

int reading;
float tempC;

void setup() {
    Serial.begin(9600);
}

void loop() {
    reading = analogRead(PIN);

    // LM35's calculation formula
    tempC = (5.0 * reading * 100.0) / 1024.0;

    Serial.print(tempC);
    Serial.println(" 도");

    delay(1000);
}