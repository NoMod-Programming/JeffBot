#ifndef _SUBSYSTEMS_ARM_H_
#define _SUBSYSTEMS_ARM_H_

#include "main.h"
#include "PIDController.h"

class Arm {
  private:
    static Arm* instance;
    Arm();
    int armValue = 0;
    PIDController* armController;

    int  getArmPotentiometer();
  public:
    void moveArm(int speed);
    static Arm* getInstance();
};

#endif
