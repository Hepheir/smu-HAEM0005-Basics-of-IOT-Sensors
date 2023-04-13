/*
  Author: 202115064 김동주 <hepheir@gmail.com>
 */

#define SEG_PIN_COUNT 8
#define PUSH_BTN_INC 12
#define PUSH_BTN_DEC 13

byte seg_digit_to_pin_table[10] = { 0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE4, 0xFE, 0xF6 };
int seg_pins[SEG_PIN_COUNT] = { 2, 3, 4, 5, 6, 7, 8, 9 };

int num = 0;

void displayNumbers(int n) {
  for (int i = 0; i < 8; i++) {
    digitalWrite(seg_pins[i], bitRead(seg_digit_to_pin_table[n], 7 - i));
  }
}

void setup() {
  pinMode(PUSH_BTN_INC, INPUT);
  pinMode(PUSH_BTN_DEC, INPUT);
  for (int i = 0; i < SEG_PIN_COUNT; i++) {
    pinMode(seg_pins[i], OUTPUT);
  }
  digitalWrite(seg_pins[7], HIGH);
}

void loop() {
  if (digitalRead(PUSH_BTN_INC) == HIGH) {
    ++num;
    if (num > 9) {
      num = 0;
    }
  }
  if (digitalRead(PUSH_BTN_DEC) == HIGH) {
    --num;
    if (num < 0) {
      num = 9;
    }
  }
  displayNumbers(num);
  delay(300);
}