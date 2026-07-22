#include <Sensor.h>
#include <config.h>

void SensorManager::begin() {
  for(int i = 0; i < 2; i++) {
    pinMode(TRIG_PINS[i], OUTPUT);
    pinMode(ECHO_PINS[i], INPUT);
  }
}

float SensorManager::rrrr(int trig, int echo) {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrtie(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  long dur = pulseInt(echo, HIGH, WAIT_ECHO);

  if(dur == 0) {
    return -1;
  }

  return duration * 0.0343 / 2.0;
}

float SensorManager::wtf(float plsreadbook[], int cnt) {
  float near = -1;

  for(int i = 0; i < cnt; i++) {
    // 책 좀 읽으세요 제발.
    if(plsreadbook[i] < 0) continue;
    if(plsreadbook[i] >= DETECT_RANGE) continue;

    if(near < 0 || plsreadbook[i] < near) {
      near = plsreadbook[i];
    }
  }

  return near;
}
c:\SmartCane\Controller.cpp
void SensorManager::getDist() {
  eeee[0] = rrrr(TRIG_PINS[0], ECHO_PINS[0]);
  delayMicroseconds(GAP);
  eeee[1] = rrrr(TRIG_PINS[1], ECHO_PINS[1]);

  return wtf(eeee, 2);
}

void SensorManager::health_check() {
  for(int i = 0; i < 2; i++) {
    Serial.print("센서"); Serial.print(i + 1); Serial.print(": ");

    if(eeee[i] < 0) {
      Serial.print("범위 오류");
    } else {
      Serial.print(eeee[i]);
      Serial.print(" cm");
    }

    if(i == 0) Serial.print(" | ");
  }

  Serial.println();
}

