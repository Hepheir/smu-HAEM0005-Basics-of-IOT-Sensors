/*
  Author: 202115064 김동주 <hepheir@gmail.com>
 */

int segment_led_pins[8] = {2, 3, 4, 5, 6, 7, 8, 9};
int segment_sel_pins[4] = {10, 11, 12, 13};
byte segment_digits[10] = {
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
int delayTime = 3;

void displayNumber(int pos, int n)
{
    for (int i = 0; i < 4; i++)
    {
        digitalWrite(segment_sel_pins[i], (segment_sel_pins[i] == pos) ? LOW : HIGH);
    }

    for (int i = 0; i < 7; i++)
    {
        digitalWrite(segment_led_pins[i], (segment_digits[n] & (1 << (7 - i))) ? HIGH : LOW);
    }
    delay(delayTime);
}

void clearLEDs()
{
    for (int i = 0; i < 8; i++)
    {
        digitalWrite(segment_led_pins[i], LOW);
    }
    for (int i = 0; i < 4; i++)
    {
        digitalWrite(segment_sel_pins[i], LOW);
    }
    delay(delayTime);
}

int n = 0;
int readValue;

void setup()
{
    Serial.begin(9600);
    for (int i = 0; i < 8; i++)
    {
        pinMode(segment_led_pins[i], OUTPUT);
    }
    for (int i = 0; i < 4; i++)
    {
        pinMode(segment_sel_pins[i], OUTPUT);
    }
}

void loop()
{
    n++;
    if (n % 50 == 1)
    {
        readValue = analogRead(A0);
        Serial.println(readValue);
    }
    int c[4] = {0, 0, 0, 0};

    c[0] = readValue / 1000;
    c[1] = readValue / 100 % 10;
    c[2] = readValue / 10 % 10;
    c[3] = readValue % 10;

    for (int i = 0; i < 4; i++)
    {
        displayNumber(segment_sel_pins[i], c[i]);
    }
    clearLEDs();
    delay(delayTime);
}