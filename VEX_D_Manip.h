#include "VEX_D_Channels.h"
#include "VEX_D_Encoders.h"

int current6BarPosition = 0;
int delta6BarPosition = 0;

void setConveyorMotors(int power)
{
	motor[conveyor] = power;
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
	if(abs(convey) > DEADZONE)
	{
		setConveyorMotors(convey);
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

void move6BarToPosition(int targetPosition)
{
	current6BarPosition = SensorValue[left_6Bar_encoder];
	delta6BarPosition = targetPosition - current6BarPosition;

	if(delta6BarPosition > 0)
	{
		set6BarMotors(127);
		while(SensorValue[left_6Bar_encoder] < (current6BarPosition + delta6BarPosition))
		{
			//wait for completion
		}
	}
	else
	{
		set6BarMotors(-127);
		while(SensorValue[left_6Bar_encoder] > (current6BarPosition + delta6BarPosition))
		{
			//wait for completion
		}
	}
	set6BarMotors(0);
}

void updateManip()
{
	teleConveyor();
	tele6Bar();
}
