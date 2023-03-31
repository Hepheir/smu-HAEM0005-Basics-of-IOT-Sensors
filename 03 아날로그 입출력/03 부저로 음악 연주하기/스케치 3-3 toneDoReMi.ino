#define BUZZER_PIN 3
#define BUZZER_DURATION 500

int tone_freq[4] = { 523, 587, 659, 698 };

void setup() {
    for (int i = 0; i < 4; i++) {
        tone(BUZZER_PIN, tone_freq[i], BUZZER_DURATION);
        delay(1000);
    }
}

void loop() {
}