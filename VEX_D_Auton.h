#include "VEX_D_Drive.h"
#include "VEX_D_Manip.h"

//stack 1 cube (use this function if all else fails)
void basicStack()
{
	auton6Bar(65, 500);
	autonDrive(-127, -127, 2500);
}

//stack 1 skyrise piece and pick up a second piece
void uniStack(bool isRed)
{
	//first skyrise piece
	autonDrive(-70, -80, 110); //back up
	autonConveyor(-50, 1600); //get conveyor to position
	wait1Msec(500);
	autonDrive(90, 100, 250); //drive into piece
	wait1Msec(500);
	move6BarToPosition(120); //pick up piece
	wait1Msec(500);
	autonDrive(-70, -80, 120); //back up
	wait1Msec(500);
	if(isRed)
	{
		autonDrive(-60, 60, 125); //turn left to the stack slot
	}
	else
	{
		autonDrive(60, -60, 125); //turn right to the stack slot
	}
	wait1Msec(500);
	autonDrive(-25, -30, 20); //back up slightly
	wait1Msec(500);
	autonConveyor(-50, 900); //drop piece
	wait1Msec(500);
	autonDrive(-60, -60, 100); //back up
	wait1Msec(500);

	//second skyrise piece
	move6BarToPosition(60); //lower 6bar to reset to new cycle
	wait1Msec(500);
	if(isRed)
	{
		autonDrive(50, -50, 105); //turn right to the skyrise loading dock
	}
	else
	{
		autonDrive(-50, 50, 105); //turn left to the skyrise loading dock
	}
	wait1Msec(500);
	autonConveyor(50, 800);	//raise conveyor to correct height
	wait1Msec(500);
	autonDrive(70, 80, 400); //drive into skyrise piece
	wait1Msec(500);
	move6BarToPosition(120); //pick up piece
	wait1Msec(500);
	autonDrive(-40, -50, 400); //back up
	wait1Msec(500);
}
