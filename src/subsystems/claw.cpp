#include "main.h"

Claw* Claw::instance = 0;

Claw::Claw() {
}

void Claw::setClaw(int speed) {
  motorSet(clawMotor, speed);
}

Claw* Claw::getInstance()
{
    if (instance == 0)
    {
        instance = new Claw();
    }

    return instance;
}
