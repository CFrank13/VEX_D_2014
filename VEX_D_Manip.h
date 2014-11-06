#include "VEX_D_Channels.h"
#include "VEX_D_Encoders.h"

int initial6BarPosition = 0;
int delta6BarPosition = 0;

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

//void autonConveyor(int power, int target)
//{
//	resetConveyorEncoder();
//	setConveyorMotor(power);

//	while(abs(SensorValue[conveyor_encoder]) < target)
//	{
//		//wait for completion
//	}
//	setConveyorMotor(0);
//}

void autonConveyor(int power, int time)
{
	setConveyorMotor(power);
	wait1Msec(time);
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
	initial6BarPosition = SensorValue[left_6Bar_encoder];

	//number of degrees we want to move
	delta6BarPosition = targetPosition - initial6BarPosition;

	//if we want to move upward...
	if(delta6BarPosition > 0)
	{
		//move while the left encoder has not reached their target
		set6BarMotors(127);
		while(SensorValue[left_6Bar_encoder] < (initial6BarPosition + delta6BarPosition))
		{
			//wait for completion
		}
	}
	//if we want want to move downward...
	else
	{
		set6BarMotors(-127);
		while(SensorValue[left_6Bar_encoder] > (initial6BarPosition + delta6BarPosition))
		{

		}
	}
	set6BarMotors(0);
}

void move6BarToPosition(int power, int targetPosition)
{
	//save the initial position of our 6Bar
	initial6BarPosition = SensorValue[left_6Bar_encoder];

	//number of degrees we want to move
	delta6BarPosition = targetPosition - initial6BarPosition;

	//if we want to move upward...
	if(delta6BarPosition > 0)
	{
		//move while the left encoder has not reached their target
		set6BarMotors(power);
		while(SensorValue[left_6Bar_encoder] < (initial6BarPosition + delta6BarPosition))
		{
			//wait for completion
		}
	}
	//if we want want to move downward...
	else
	{
		set6BarMotors(-power);
		while(SensorValue[left_6Bar_encoder] > (initial6BarPosition + delta6BarPosition))
		{

		}
	}
	set6BarMotors(0);
}

void updateManip()
{
	teleConveyor();
	tele6Bar();
}
