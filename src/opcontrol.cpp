/** @file opcontrol.c
 * @brief File for operator control code
 *
 * This file should contain the user operatorControl() function and any functions related to it.
 *
 * Any copyright is dedicated to the Public Domain.
 * http://creativecommons.org/publicdomain/zero/1.0/
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"
#include "auto.h"
//#include "stdio.h"

/*
 * Runs the user operator control code. This function will be started in its own task with the
 * default priority and stack size whenever the robot is enabled via the Field Management System
 * or the VEX Competition Switch in the operator control mode. If the robot is disabled or
 * communications is lost, the operator control task will be stopped by the kernel. Re-enabling
 * the robot will restart the task, not resume it from where it left off.
 *
 * If no VEX Competition Switch or Field Management system is plugged in, the VEX Cortex will
 * run the operator control task. Be warned that this will also occur if the VEX Cortex is
 * tethered directly to a computer via the USB A to A cable without any VEX Joystick attached.
 *
 * Code running in this task can take almost any action, as the VEX Joystick is available and
 * the scheduler is operational. However, proper use of delay() or taskDelayUntil() is highly
 * recommended to give other tasks (including system tasks such as updating LCDs) time to run.
 *
 * This task should never exit; it should end with some kind of infinite loop, even if empty.
 */
void operatorControl() {
	int leftJoystickValue, rightJoystickValue;
//	int armSpeed;

	bool slowMode = false;

	//Arm*  arm  = Arm::getInstance();
	Claw* claw = Claw::getInstance();
	Base* base = Base::getInstance();

	char mode = 0;

	mode = 0;//fgetc(stdout);
	delay(3000);
	if (true) {
		autonomous();
		return;
	}
	while (true) {
		// Joystick control
		//mode = getch();
		if (mode == 'a') { // 'a'
		} else if (mode == 'b') {
			base->moveBase(-127, -127);
			delay(1000);
			base->moveBase(-127, -127);
			base->moveBase(0, 0);
		} else if (mode == 's') {
			base->stopAll();
		}
		mode = 0;
		//char test[5] = "test";
		//test[0] = mode;
		//printf(test);
		if (joystickGetDigital(1, 7, JOY_UP)) {
			autonomous();
		}

		leftJoystickValue = -threshold(joystickGetAnalog(1, 3));
		rightJoystickValue = -threshold(joystickGetAnalog(1, 2));

		if (slowMode) {
			leftJoystickValue /= 1.7;
			rightJoystickValue /= 1.7;
		}
		//motorSet(leftMotor, 0);
		//motorSet(rightMotor, 0);
		//motorSet(armMotor, 0);
		//motorSet(clawMotor, 0);
		base->moveBase(leftJoystickValue, rightJoystickValue);

		if (joystickGetDigital(1, 8, JOY_LEFT)) {
			slowMode = !slowMode;
			while (joystickGetDigital(1, 8, JOY_LEFT)) {};
		}

		// Arm control
		//armSpeed = 51;
		//armSpeed = joystickGetDigital(1, 6, JOY_DOWN) - joystickGetDigital(1, 6, JOY_UP);
		//armSpeed *= slowMode ? 2 : 5;
		//arm->moveArm(armSpeed);
		//printf("%i\n", motorGet(armMotor));
		//motorSet(armMotor, 0);

		// Claw control
		claw->setClaw((joystickGetDigital(1, 5, JOY_UP) - joystickGetDigital(1, 5, JOY_DOWN)) * 50);

		delay(10); // Small delay
	}
}
