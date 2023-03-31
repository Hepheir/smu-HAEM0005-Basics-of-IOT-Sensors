#define C5 523
#define D5 587
#define E5 659
#define F5 698
#define G5 784
#define A5 880

#define BUZZER_PIN 3
#define BUZZER_DELAY_RATE 1.3

int myNote[] = { G5, E5, G5, E5, G5, A5, G5 };
int myDu[] = { 250, 250, 250, 250, 250, 250, 500 };

void setup() {
    for (int i = 0; i < 7; i++) {
        tone(BUZZER_PIN, myNote[i], myDu[i]);
        delay(myDu[i] * BUZZER_DELAY_RATE);
        noTone(BUZZER_PIN);
    }
}

void loop() {
}