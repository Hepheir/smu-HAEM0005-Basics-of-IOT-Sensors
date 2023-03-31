#define LED_1 5
#define LED_2 11

void setup() {
    pinMode(LED_1, OUTPUT);
    pinMode(LED_2, OUTPUT);
}

void loop() {
    analogWrite(LED_1, 50);
    analogWrite(LED_2, 255);
}