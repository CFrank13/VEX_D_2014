#include "VEX_D_Channels.h"
#include "VEX_D_Encoders.h"

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

//drive by time
void autonDrive(int leftPower, int rightPower, int duration)
{
	setLeftDriveMotors(leftPower);
	setRightDriveMotors(rightPower);
	wait1Msec(duration);
	setLeftDriveMotors(0);
	setRightDriveMotors(0);
}

//drive by degrees
void autonDrive(int leftPower, int rightPower, int leftTarget, int rightTarget)
{
	resetDriveEncoders();

	setLeftDriveMotors(leftPower);
	setRightDriveMotors(rightPower);

	while(leftDriveEncoder < leftTarget || rightDriveEncoder < rightTarget)
	{
		if(leftDriveEncoder >= leftTarget)
		{
			setLeftDriveMotors(0);
		}
		if(rightDriveEncoder >= rightTarget)
		{
			setRightDriveMotors(0);
		}
	}
}

void updateDrive()
{
	teleDrive();
}
