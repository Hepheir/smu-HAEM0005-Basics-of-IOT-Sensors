/*
  Author: 202115064 김동주 <hepheir@gmail.com>

  "IRremote" by "shirriff, z3t0, ArminJo" v0.1.0
 */

#include <IRremote.h>

#define RECV_PIN 11
#define LED_PIN 5

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);

  Serial.println("Enabling IRin");
  irrecv.enableIRIn();
  Serial.println("Enabled IRin");

  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume();
    if (results.value == 0xFF30CF) {
      digitalWrite(LED_PIN, HIGH);
    }
    if (results.value == 0xFF18E7) {
      digitalWrite(LED_PIN, LOW);
    }
  }
}