#include <Controller.h>
#include <config.h>

void Controller::begin() {
  pinMode(BUZZER, OUTPUT);
}

float Controller::Simons(float newDistance) {
  if(simons < 0) {
    return newDistance; // Let's Go Bed.
  }

  return SIMONS * newDistance + (1 - SIMONS) * simons; // 시몬스.
}

unsigned long Controller::disttime(float dist) {
  dist = constrain(dist, DETECT_CLOSE, DETECT_RANGE);
  float ratio = (dist - DETECT_CLOSE) / (DETECT_RANGE - DETECT_CLOSE);
  return (unsigned long)(NEAR + ratio * (FAR - NEAR));
}

void Controller::update(float nearDist) {
  if(nearDist <= 0) {
    simons = -1;
    noTone(BUZZER);
    return;
  }

  simons = Simons(nearDist);
  unsigned long now = millis();

  if(sc:\SmartCane\SmartCane.inoimons <= WTF_NEAR) {
    tone(BUZZER, TONE);
    return;
  }
x
  unsigned long time = disttime(simons);
  if(now - wtfnoise >= time) {
    tone(BUZZER, TONE, DURATION);
    wtfnoise = now;
  }
}