#include "VEX_D_Macros.h"

static int DEADZONE = 15;

void setLeftDriveMotors(int power)
{
	motor[left_back_drive] = power;
	motor[left_front_drive] = power;
}
void setRightDriveMotors(int power)
{
	motor[right_back_drive] = power;
	motor[right_front_drive] = power;
}

void teleDrive()
{
	if(abs(leftDrive) > DEADZONE)
	{
		setLeftDriveMotors(leftDrive);
	}
	else
	{
		setLeftDriveMotors(0);
	}

	if(abs(rightDrive) > DEADZONE)
	{
		setRightDriveMotors(rightDrive);
	}
	else
	{
		setRightDriveMotors(0);
	}
}

void autonDrive(int leftPower, int rightPower, int duration)
{
	setLeftDriveMotors(leftPower);
	setRightDriveMotors(rightPower);
	wait1Msec(duration);
	setLeftDriveMotors(0);
	setRightDriveMotors(0);
}

void updateDrive()
{
	teleDrive();
}
