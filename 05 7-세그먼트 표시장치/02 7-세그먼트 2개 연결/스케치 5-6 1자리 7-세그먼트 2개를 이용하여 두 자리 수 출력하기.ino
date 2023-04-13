/*
  Author: 202115064 김동주 <hepheir@gmail.com>
 */
byte seg_digit_to_pin_table[10] = {
    0b11111100,
    0b01100000,
    0b11011010,
    0b11110010,
    0b01100110,
    0b10110110,
    0b10111110,
    0b11100100,
    0b11111110,
    0b11110110};

#define SEG_PIN_COUNT 8
#define SEG_COUNT 2

int seg_pins[SEG_PIN_COUNT] = {2, 3, 4, 5, 6, 7, 8, 9};
int segs[SEG_COUNT] = {10, 11};

void displayDigit(int val, int dst)
{
    for (int i = 0; i < SEG_COUNT; i++)
    {
        digitalWrite(segs[i], LOW);
    }
    for (int i = 0; i < SEG_PIN_COUNT; i++)
    {
        if (seg_digit_to_pin_table[val] & (0b10000000 >> i))
        {
            digitalWrite(seg_pins[i], HIGH);
        }
        else
        {
            digitalWrite(seg_pins[i], LOW);
        }
    }
    digitalWrite(segs[dst], HIGH);
}

void displayNumber(int val)
{
    for (int i = 0; i < SEG_COUNT; i++)
    {
        displayDigit(val % 10, i);
        val /= 10;
        delay(10);
    }
}

void setup()
{
    for (int i = 0; i < SEG_COUNT; i++)
    {
        pinMode(segs[i], OUTPUT);
    }
    for (int i = 0; i < SEG_PIN_COUNT; i++)
    {
        pinMode(seg_pins[i], OUTPUT);
    }
}

void loop()
{
    for (int i = 0; i < 100; i++)
    {
        displayNumber(i);
    }
}