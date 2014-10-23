#include "VEX_D_Auton.h"

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
