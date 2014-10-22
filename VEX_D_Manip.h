#include "VEX_D_Channels.h"
#include "VEX_D_Encoders.h"

bool shift = true;
bool isHalfSpeed = false;
bool lastToggle = true;
bool temp = false;

void toggleConveyorSpeed()
{
	if(conveyorBrake)
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
void setConveyorMotors(int power)
{
	if(!isHalfSpeed)
	{
		motor[left_conveyor] = power;
		motor[right_conveyor] = power;
	}
	else
	{
		motor[left_conveyor] = power / 3;
		motor[right_conveyor] = power / 3;
	}
}
void set6BarMotors(int power)
{
	motor[left_6Bar_A] = power;
	motor[left_6Bar_B] = power;
	motor[right_6Bar_A] = power;
	motor[right_6Bar_B] = power;
}

void teleConveyor()
{
	if(intake)
	{
		setConveyorMotors(-127);
	}
	else if(outtake)
	{
		setConveyorMotors(127);
	}
	else
	{
		setConveyorMotors(0);
	}
}
void tele6Bar()
{
	if(raise6Bar)
	{
		set6BarMotors(127);
	}
	else if(drop6Bar)
	{
		set6BarMotors(-127);
	}
	else
	{
		set6BarMotors(0);
	}
}

void autonConveyor(int power, int duration)
{
	setConveyorMotors(power);
	wait1Msec(duration);
	setConveyorMotors(0);
}

void auton6Bar(int power, int duration)
{
	set6BarMotors(power);
	wait1Msec(duration);
	set6BarMotors(0);
}

void updateManip()
{
	toggleConveyorSpeed();
	teleConveyor();
	tele6Bar();
}
