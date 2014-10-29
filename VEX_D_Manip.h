#include "VEX_D_Channels.h"
#include "VEX_D_Encoders.h"

int initialLeft6BarPosition = 0;
int initialRight6BarPosition = 0;
int deltaLeft6BarPosition = 0;
int deltaRight6BarPosition = 0;

void setConveyorMotor(int power)
{
	motor[conveyor] = power;
}

void setLeft6BarMotors(int power)
{
	motor[left_6Bar_A] = power;
	motor[left_6Bar_B] = power;
}

void setRight6BarMotors(int power)
{
	motor[right_6Bar_A] = power;
	motor[right_6Bar_B] = power;
}

void set6BarMotors(int power)
{
	setLeft6BarMotors(power);
	setRight6BarMotors(power);
}

void teleConveyor()
{
	if(abs(convey) > DEADZONE)
	{
		setConveyorMotor(convey);
	}
	else
	{
		setConveyorMotor(0);
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

void autonConveyor(int power, int target)
{
	resetConveyorEncoder();
	setConveyorMotor(power);

	while(abs(SensorValue[conveyor_encoder]) < target)
	{
		//wait for completion
	}
	setConveyorMotor(0);
}

void auton6Bar(int power, int duration)
{
	set6BarMotors(power);
	wait1Msec(duration);
	set6BarMotors(0);
}

void move6BarToPosition(int targetPosition)
{
	//save the initial position of our 6Bar
	initialLeft6BarPosition = SensorValue[left_6Bar_encoder];
	initialRight6BarPosition = SensorValue[right_6Bar_encoder];

	//number of degrees we want to move
	deltaLeft6BarPosition = targetPosition - initialLeft6BarPosition;
	deltaRight6BarPosition = targetPosition - initialRight6BarPosition;

	//if we want to move upward...
	if(deltaLeft6BarPosition > 0)
	{
		//move while either the left encoders or the right encoders have not reached their target
		set6BarMotors(127);
		while((SensorValue[left_6Bar_encoder] < (initialLeft6BarPosition + deltaLeft6BarPosition))
			|| (SensorValue[right_6Bar_encoder] < (initialRight6BarPosition + deltaRight6BarPosition)))
		{
			//stop either the left or the right motors once they reach their target (stopped seperately!!)
			if(SensorValue[left_6Bar_encoder] >= (initialLeft6BarPosition + deltaLeft6BarPosition))
			{
				setLeft6BarMotors(0);
			}
			if(SensorValue[right_6Bar_encoder] >= (initialRight6BarPosition + deltaRight6BarPosition))
			{
				setRight6BarMotors(0);
			}
		}
	}
	//if we want want to move downward...
	else
	{
		set6BarMotors(-127);
		while((SensorValue[left_6Bar_encoder] > (initialLeft6BarPosition + deltaLeft6BarPosition))
			|| (SensorValue[right_6Bar_encoder] > (initialRight6BarPosition + deltaRight6BarPosition)))
		{
			if(SensorValue[left_6Bar_encoder] <= (initialLeft6BarPosition + deltaLeft6BarPosition))
			{
				setLeft6BarMotors(0);
			}
			if(SensorValue[right_6Bar_encoder] <= (initialRight6BarPosition + deltaRight6BarPosition))
			{
				setRight6BarMotors(0);
			}
		}
	}
	set6BarMotors(0);
}

void updateManip()
{
	teleConveyor();
	tele6Bar();
}
