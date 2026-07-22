#ifdef CONTROLLER_H
#define CONTROLLER_H

#include <Arduino.h>

class Controller {
  public:
    void begin();
    void update(float nearDist);

  private:
    float simons = -1;
    unsigned long wtfnoise = 0;
    float smooth(float newDistance);
    unsigned long disttime(float dist);
};

#endif

