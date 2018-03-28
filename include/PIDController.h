#ifndef _SUBSYSTEMS_PIDCONTROLLER_H_
#define _SUBSYSTEMS_PIDCONTROLLER_H_

#include "main.h"

class PIDController {
  private:
    float kP = 0;
    float kI = 0;
    float kD = 0;
    float multiplier = 1;
    int motorChannel = 0;
    long integral = 0;
    int previousError = 0;
    int setpoint = 0;
    int currSensorValue = 0;
  public:
    PIDController(int motorChannel, float kP, float kI = 0, float kD = 0, float multiplier = 1);
    void setKp(float kP);
    void setKi(float kI);
    void setKd(float kD);
    void setSetpoint(int setpoint);
    void sensorValue(int value);
    void loop();
};

#endif
