#include "main.h"
#include "PIDController.h"

PIDController::PIDController(int motorChannel, float kP, float kI, float kD, float multiplier) {
  this->motorChannel = motorChannel;
  this->kP = kP;
  this->kI = kI;
  this->kD = kD;
  this->multiplier = multiplier;
  //this->controllers.push_back(this);
}

void PIDController::setKp(float kP) {
  this->kP = kP;
}

void PIDController::setKi(float kI) {
  this->kI = kI;
}

void PIDController::setKd(float kD) {
  this->kD = kD;
}

void PIDController::setSetpoint(int setpoint) {
  this->setpoint = setpoint;
  integral = 0;
}

void PIDController::sensorValue(int value) {
  this->currSensorValue = value;
}

void PIDController::loop() {
    int error, derivative, output;
    error = setpoint - currSensorValue;
    integral += error * 1;
    derivative  = (error - previousError) / 1;
    output = kP * error + kI * integral + kD * derivative;
    output = (output > 127) ? 127 : ((output < -127) ? -127 : output);
    motorSet(motorChannel, output * multiplier);
    previousError = error;
}
