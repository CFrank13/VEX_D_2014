#include "VEX_D_Channels.h"
#include "VEX_D_Encoders.h"

bool shift = true;
bool isHalfSpeed = false;
bool lastToggle = true;
bool temp = false;

void toggleStrafeSpeed()
{
	if(strafeSpeedToggle)
	{
		if(shift)
		{
			temp = lastToggle;
			lastToggle = isHalfSpeed;
			isHalfSpeed = temp;
		}
		shift = false;
	}
	else
	{
		shift = true;
	}
}

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
void setStrafeMotor(int power)
{
	if(!isHalfSpeed)
	{
		motor[strafer] = power;
	}
	else
	{
		motor[strafer] = power / 2;
	}
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

void teleStrafe()
{
	if(strafeLeft)
	{
		setStrafeMotor(127);
	}
	else if(strafeRight)
	{
		setStrafeMotor(-127);
	}
	else
	{
		setStrafeMotor(0);
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

	while(SensorValue[left_drive_encoder] < leftTarget || SensorValue[right_drive_encoder] < rightTarget)
	{
		if(SensorValue[left_drive_encoder] >= leftTarget)
		{
			setLeftDriveMotors(0);
		}
		if(SensorValue[right_drive_encoder] >= rightTarget)
		{
			setRightDriveMotors(0);
		}
	}
}

void updateDrive()
{
	toggleStrafeSpeed();
	teleDrive();
	teleStrafe();
}
