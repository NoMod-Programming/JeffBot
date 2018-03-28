#ifndef _SUBSYSTEMS_BASE_H_
#define _SUBSYSTEMS_BASE_H_

#include "main.h"
#include "PIDController.h"

class Base {
  private:
    int leftSetpoint;
    int rightSetpoint;

    Encoder leftEncoder;
    Encoder rightEncoder;

    PIDController* leftMotor;
    PIDController* rightMotor;

    Gyro gyro;

    static constexpr float leftKp = 0.6;
    static constexpr float rightKp = 0.8;

    static Base* instance;
    Base();
  public:
    void moveBase(int leftSpeed, int  rightSpeed);
    void moveBaseTo(int leftSetpoint, int rightSetpoint);
    void turnDegrees(int degrees);
    int getLeftEncoder();
    int getRightEncoder();

    void stopAll();

    static Base* getInstance();
};

#endif
