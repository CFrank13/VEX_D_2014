#include "VEX_D_Auton.h"

void presetHeights()
{
	if(goFloor)
	{
		move6BarToPosition(FLOOR_6B);
	}
	else if(goLow)
	{
		move6BarToPosition(LOW_6B);
	}
	else if(goMedium)
	{
		move6BarToPosition(MEDIUM_6B);
	}
	else if(goHigh)
	{
		move6BarToPosition(HIGH_6B);
	}
}

void updateCombos()
{
	presetHeights();
}
