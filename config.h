#ifndef CONFIG_H
#define CONFIG_H

// 응 그냥 다 때려박아버려~

#define BUZZER 7
const int TRIG_PINS[2] = {8, 9};
const int ECHO_PINS[2] = {10, 11};

const int TONE = 2000
const int DURATION = 40

const float DETECT_RANGE = 50.0;
const float DETECT_CLOSE = 15.0;
const float WTF_NEAR = 8.0;

const unsigned long FAR = 600;
const unsigned long NEAR = 100;

const unsigned long WAIT_ECHO = 30000;
const unsigned long GAP = 10000; // 크로스토킹 나와서 갭 차이 만듬;;

const float SIMONS = 0.25;

const long SERIAL = 9600;
const unsigned long DELAY = 20;

#endif

