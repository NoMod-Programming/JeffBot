/** @file Constants.h
 * @brief Provides constants used throughout the entire code. Contains user-readable motor names
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#include "main.h"
#include "subsystems/Claw.h"
#include "subsystems/Arm.h"
#include "subsystems/Base.h"

const int leftBaseMotor = 2;
const int rightBaseMotor = 7;
const int armMotor = 3;
const int armMotorTwo = 4;
const int clawMotor = 6;

const int armLimitSwitch = 1;

const int armPotentiometer = 2;

const int leftEncoderTopPort = 4;
const int leftEncoderBottomPort = 5;

const int rightEncoderTopPort = 2;
const int rightEncoderBottomPort = 3;

const int gyroPort = 3;

#endif
