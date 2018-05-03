#include "main.h"

Base* Base::instance = 0;

Base::Base() {
  leftSetpoint  = 0;
  rightSetpoint = 0;

  leftEncoder = encoderInit(leftEncoderTopPort, leftEncoderBottomPort, false);
  rightEncoder = encoderInit(rightEncoderTopPort ,rightEncoderBottomPort, true);

  leftMotor = new PIDController(leftBaseMotor, 0.5, 0.0001, 0.97, 0.64);
  rightMotor = new PIDController(rightBaseMotor, 0.7, 0.01, 0.65, 1);

  gyro = gyroInit(gyroPort, 196);
}

void Base::moveBase(int leftSpeed, int rightSpeed) {
  leftSpeed = threshold(leftSpeed);
  if (abs(leftSpeed) > 0) {
    leftMotor->setSetpoint(getLeftEncoder() + leftSpeed);
  }
  rightSpeed = threshold(rightSpeed);
  if (abs(rightSpeed) > 0) {
    rightMotor->setSetpoint(getRightEncoder() + rightSpeed);
  }
  leftMotor->sensorValue(getLeftEncoder());
  rightMotor->sensorValue(getRightEncoder());
  leftMotor->loop();
  rightMotor->loop();
}

void Base::moveBaseTo(int leftSetpoint, int rightSetpoint) {
  encoderReset(leftEncoder);
  encoderReset(rightEncoder);
  leftMotor->setSetpoint(leftSetpoint);
  rightMotor->setSetpoint(rightSetpoint);
  int left = getLeftEncoder();
  int right = getRightEncoder();
  while (abs(left) < abs(leftSetpoint) || abs(right) < abs(rightSetpoint)) {
    leftMotor->loop();
    rightMotor->loop();
    left = getLeftEncoder();
    right = getRightEncoder();
    leftMotor->sensorValue(left);
    rightMotor->sensorValue(right);
  }
}

void Base::turnDegrees(int degrees) {
  gyroReset(gyro);
  leftMotor->setSetpoint(degrees * 10);
  rightMotor->setSetpoint(degrees * 10);
  int left;
  int right;
  while (abs(gyroGet(gyro)) < abs(degrees)) {
    leftMotor->loop();
    rightMotor->loop();
    left = gyroGet(gyro) * 10;
    right = gyroGet(gyro) * 10;
    leftMotor->sensorValue(left);
    rightMotor->sensorValue(right);
    printf("Gyro value: %d\n", gyroGet(gyro));
  }
  printf("DONE!");
}

void Base::stopAll() {
  leftSetpoint = encoderGet(leftEncoder);
  rightSetpoint = encoderGet(rightEncoder);
}

int Base::getLeftEncoder() {
  return encoderGet(leftEncoder);
}

int Base::getRightEncoder() {
  return encoderGet(rightEncoder);
}

Base* Base::getInstance()
{
    if (instance == 0)
    {
        instance = new Base();
    }

    return instance;
}
