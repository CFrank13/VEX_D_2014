#include "VEX_D_Auton.h"

//TODO: get real height values
static int FLOOR_C = 0;
static int LOW_C = 100;
static int MEDIUM_C = 200;
static int HIGH_C = 300;

static int FLOOR_6B = 0;
static int LOW_6B = 100;
static int MEDIUM_6B = 200;
static int HIGH_6B = 300;

int deltaConveyorPosition = 0;
int delta6BarPosition = 0;

void moveConveyorToPosition(int position)
{
	deltaConveyorPosition = position - SensorValue[conveyor_encoder];

	if(deltaConveyorPosition > 0)
	{
		setConveyorMotors(127);
		while(SensorValue[conveyor_encoder] < position)
		{
			//wait for completion
		}
	}
	else
	{
		setConveyorMotors(-127);
		while(SensorValue[conveyor_encoder] > position)
		{
			//wait for completion
		}
	}
	setConveyorMotors(0);
}

void move6BarToPosition(int position)
{
	delta6BarPosition = position - SensorValue[left_6Bar_encoder];

	if(delta6BarPosition > 0)
	{
		set6BarMotors(127);
		while(SensorValue[left_6Bar_encoder] < position || SensorValue[right_6Bar_encoder] < position)
		{
			if(SensorValue[left_6Bar_encoder] >= position)
			{
				motor[left_6Bar_A] = 0;
				motor[left_6Bar_B] = 0;
			}
			if(SensorValue[right_6Bar_encoder] >= position)
			{
				motor[right_6Bar_A] = 0;
				motor[right_6Bar_B] = 0;
			}
		}
	}
	else
	{
		setConveyorMotors(-127);
		while(SensorValue[left_6Bar_encoder] > position || SensorValue[right_6Bar_encoder] > position)
		{
			if(SensorValue[left_6Bar_encoder] <= position)
			{
				motor[left_6Bar_A] = 0;
				motor[left_6Bar_B] = 0;
			}
			if(SensorValue[right_6Bar_encoder] <= position)
			{
				motor[right_6Bar_A] = 0;
				motor[right_6Bar_B] = 0;
			}
		}
	}
}

void presetHeight_Floor()
{
	if(goFloor)
	{
		move6BarToPosition(FLOOR_6B);
		moveConveyorToPosition(FLOOR_C);
	}
}

void presetHeight_Low()
{
	if(goLow)
	{
		move6BarToPosition(LOW_6B);
		moveConveyorToPosition(LOW_C);
	}
}

void presetHeight_Medium()
{
	if(goMedium)
	{
		move6BarToPosition(MEDIUM_6B);
		moveConveyorToPosition(MEDIUM_C);
	}
}

void presetHeight_High()
{
	if(goHigh)
	{
		move6BarToPosition(HIGH_6B);
		moveConveyorToPosition(HIGH_C);
	}
}

void updateCombos()
{
	presetHeight_Floor();
	presetHeight_Low();
	presetHeight_Medium();
	presetHeight_High();
}
