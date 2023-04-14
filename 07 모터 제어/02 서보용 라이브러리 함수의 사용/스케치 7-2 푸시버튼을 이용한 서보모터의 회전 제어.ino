/**
  Author: Hepheir<hepheir@gmail.com>

  Dependencies:
  - name: Servo
    author: Michael Margolis, Arduino
    version: 1.0.0
 */

#include <Servo.h>

#define SERVO_PIN 12
#define PUSH_BTN_PIN 7

#define DIRECTION_CLOCKWISE 0
#define DIRECTION_COUNTERCLOCKWISE 1

Servo myServo;
int angle = 0;
int direction = DIRECTION_CLOCKWISE;

void setup() {
  myServo.attach(SERVO_PIN);
  myServo.write(0);

  pinMode(PUSH_BTN_PIN, INPUT);

  Serial.begin(9600);
  Serial.println("Enter the push button.");
}

void loop() {
  if (digitalRead(PUSH_BTN_PIN) != HIGH) {
    return;
  }
  if (direction == DIRECTION_CLOCKWISE) {
    angle += 1;
    if (angle >= 180) {
      direction = DIRECTION_COUNTERCLOCKWISE;
    }
  }
  else {
    angle -= 1;
    if (angle <= 0) {
      direction = DIRECTION_CLOCKWISE;
    }
  }
  myServo.write(angle);
  delay(10);
  Serial.println(angle);
}