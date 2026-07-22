#ifdef SENSOR_H
#define SENSOR_H

#include <Arduino.h>

class SensorManager {
  public:
    void begin();
    float getDist();
    void health_check();

  private:
    float eeee[2];
    float rrrr(int trig, int echo);
    float wtf(float plsreadbook[], int cnt);
};

#endif