int led = 9;           // the PWM pin the LED is attached to
int buttonState;
int brightness1 = 0;    // how bright the LED is
int fadeAmount1 = 5;    // how many points to fade the LED by
int brightness2 = 0;    // how bright the LED is
int fadeAmount2 = 3;    // how many points to fade the LED by
void setup() {
  pinMode(led, OUTPUT);
  pinMode(2, INPUT);
  flicker();
}

void loop() {
}
void flicker() {
  analogWrite(led, random(30) + 40);
  delay(random(100));
  buttonState = digitalRead(2);
  if (buttonState == HIGH) {
    delay(150);
    strongFlicker();
  }
  else {
    flicker();
  }
}
void strongFlicker() {
  analogWrite(led, random(120) + 130);
  delay(random(100));
  buttonState = digitalRead(2);
  if (buttonState == HIGH) {
    delay(150);
    light();
  }
  else {
    strongFlicker();
  }
}
void light() {
  analogWrite(led, 80);
  delay(100);
  buttonState = digitalRead(2);
  if (buttonState == HIGH) {
    delay(150);
    strongLight();
  }
  else {
    light();
  }
}
void strongLight() {
  analogWrite(led, 140);
  delay(100);
  buttonState = digitalRead(2);
  if (buttonState == HIGH) {
    delay(150);
    fade();
  }
  else {
    strongLight();
  }
}
void fade() {
  analogWrite(led, brightness1);
  brightness1 = brightness1 + fadeAmount1;
  if (brightness1 <= 0 || brightness1 >= 255) {
    fadeAmount1 = -fadeAmount1;
  }
  delay(30);
  buttonState = digitalRead(2);
  if (buttonState == HIGH) {
    delay(150);
    strongFade();
  }
  else {
    fade();
  }
}
void strongFade() {
  analogWrite(led, brightness2);
  brightness2 = brightness2 + fadeAmount2;
  if (brightness2 <= 0 || brightness2 >= 255) {
    fadeAmount2 = -fadeAmount2;
  }
  delay(10);
  buttonState = digitalRead(2);
  if (buttonState == HIGH) {
    delay(150);
    flicker();
  }
  else {
    strongFade();
  }
}
