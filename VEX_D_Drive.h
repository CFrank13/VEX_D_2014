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

void drive()
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

void updateDrive()
{
	drive();
}
