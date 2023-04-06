/*
  Author: 202115064 김동주 <hepheir@gmail.com>
*/

#include <string.h>

#define PIN A0
#define SERIAL_OUTPUT_LEN 32

int reading;
float celcius;
char serialOutput[SERIAL_OUTPUT_LEN];

void setup() {
  Serial.begin(9600);
  Serial.println("Serial connected.");
}

void loop() {
  reading = analogRead(PIN);

  // LM35's calculation formula
  celcius = (5.0 * reading * 100.0) / 1024.0;

  sprintf(serialOutput, "%sC (adc:%d)\n", String(celcius).c_str(), reading);
  Serial.print(serialOutput);
  delay(500);
}