#include <config.h>
#include <Sensor.h>
#include <Controller.h>

SensorManager sensor;
Controller controller;

void setup() {
  Serial.begin(SERIAL);
  sensor.begin();
  controller.begin();
  Serial.println("Danielllllll Lets Goooo");

}

void loop() {
  float near = sensor.getDist();
  controller.update(near);

  sensor.health_check();

  delay(DELAY);
}

