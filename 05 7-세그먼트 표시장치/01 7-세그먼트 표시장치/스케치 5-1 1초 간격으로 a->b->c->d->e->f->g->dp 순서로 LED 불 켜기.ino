/*
  Author: 202115064 김동주 <hepheir@gmail.com>
 */

#define SEG_PIN_COUNT 8
#define SEG_PIN_GND 10

int seg_pins[SEG_PIN_COUNT] = { 2, 3, 4, 5, 6, 7, 8, 9 };

void setup() {
  for (int i = 0; i < SEG_PIN_COUNT; i++) {
    pinMode(seg_pins[i], OUTPUT);
  }
  digitalWrite(seg_pins[0], HIGH);
}

void loop() {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (i == j) {
        digitalWrite(seg_pins[j], HIGH);
      } else {
        digitalWrite(seg_pins[j], LOW);
      }
    }
    delay(1000);
  }
}