/*
  Author: 202115064 김동주 <hepheir@gmail.com>
 */

byte seg_digit_to_pin_table[10][8] = {
    {1, 1, 1, 1, 1, 1, 0, 0},
    {0, 1, 1, 0, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 1, 0},
    {1, 1, 1, 1, 0, 0, 1, 0},
    {0, 1, 1, 0, 0, 1, 1, 0},
    {1, 0, 1, 1, 0, 1, 1, 0},
    {1, 0, 1, 1, 1, 1, 1, 0},
    {1, 1, 1, 0, 0, 1, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 0},
    {1, 1, 1, 1, 0, 1, 1, 0}};

#define SEG_PIN_COUNT 8
#define SEG_PIN_GND 10

int seg_pins[SEG_PIN_COUNT] = {2, 3, 4, 5, 6, 7, 8, 9};
int num = 0;

void setup()
{
  for (int i = 0; i < SEG_PIN_COUNT; i++)
  {
    pinMode(seg_pins[i], OUTPUT);
  }
  digitalWrite(seg_pins[7], HIGH);
}

void loop()
{
  for (int i = 0; i < 8; i++) {
    digitalWrite(seg_pins[i], seg_digit_to_pin_table[num][i]);
  }

  num++;
  if (num > 9) {
    num = 0;
  }
  delay(1000);
}