#include "main.h"
#include "subsystems/arm.h"

Arm* Arm::instance = 0;

Arm::Arm() {
  armValue = 0;
}

void Arm::moveArm(int speed) {
  armValue += speed;
  if (armValue >  127) armValue = 127;
  if (armValue < -127) armValue = -127;
  motorSet(armMotor, armValue);
  motorSet(armMotorTwo, -armValue);
}

Arm* Arm::getInstance()
{
    if (instance == 0)
    {
        instance = new Arm();
    }

    return instance;
}
