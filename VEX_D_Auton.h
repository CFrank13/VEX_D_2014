#include "VEX_D_Drive.h"
#include "VEX_D_Manip.h"


//stack 1 cube (use this function if all else fails)
void cheatTubing()
{
	auton6Bar(65, 500);
	autonDrive(-127, -127, 2200);
}

//stack 1 skyrise piece (red or blue)
void uniStack(bool red)
{
	//first skyrise piece
	autonDrive(-110, -110, 110); //back up
	autonConveyor(-80, 1200); //get conveyor to position
	wait1Msec(300);
	if(red)
	{
		autonDrive(110, 110, 185); //drive into piece
	}
	else
	{
		autonDrive(110, 110, 240);
	}
	autonDrive(-50, -50, 50); //add slack
	wait1Msec(300);
	move6BarToPosition(125); //pick up piece
	wait1Msec(300);
	autonDrive(-50, -50, 155); //back up
	wait1Msec(300);
	if(red)
	{
		autonDrive(-50, 50, 180); //turn to the stack slot
	}
	else
	{
		autonDrive(50, -50, 195);
	}
	wait1Msec(300);
	//if(!red)
	//{
		autonDrive(30, 30, 45); //move up slightly
	//}
	//auton6Bar(-50, 200); //correct the angle
	wait1Msec(300);
	autonConveyor(-60, 1100); //drop piece
	wait1Msec(300);
	auton6Bar(-50, 300); //correct the angle
	wait1Msec(300);
	autonDrive(-90, -90, 100); //back up
	wait1Msec(500);
}

//stack 1 skyrise piece and picks up a second piece (only red)
void diStack()
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
	autonDrive(-60, 60, 175); //turn left to the stack slot
	wait1Msec(500);
	autonDrive(-25, -30, 20); //back up slightly
	wait1Msec(500);
	move6BarToPosition(35);
	autonConveyor(-50, 950); //drop piece
	wait1Msec(500);
	autonDrive(-60, -60, 100); //back up
	wait1Msec(500);

	//second skyrise piece
	move6BarToPosition(60); //lower 6bar to reset to new cycle
	wait1Msec(500);
	autonDrive(50, -50, 105); //turn right to the skyrise loading dock
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

void skillsChallenge()
{
	move6BarToPosition(40); //raise 6bar to knock cube onto stack and prevent drag
	wait1Msec(500);
	autonDrive(60, 60, 100); //move forward to allow room for turn
	wait1Msec(500);
	autonDrive(-60, 60, 150);	//turn to lign up with skyrise piece
	wait1Msec(500);
	autonDrive(60, 60, 150); //move forward to make room for 180
	wait1Msec(500);
	autonDrive(-60, 60, 550); //180 turn
	wait1Msec(500);
	autonConveyor(-70, 1600); //convey to pickup height
	wait1Msec(500);
	autonDrive(80, 80, 150); //drive into piece
	wait1Msec(500);
	autonDrive(-50, -50, 40); //add some slack for clean pickup
	wait1Msec(500);
	move6BarToPosition(160); //pick up SR piece #1
	wait1Msec(500);
	autonDrive(-60, -60, 115); //back up
	wait1Msec(500);
	autonDrive(-50, 50, 115); //turn to the skyrise slot
	wait1Msec(500);
	autonConveyor(70, 800); //stack SR piece #1
	wait1Msec(500);
	autonDrive(-50, -50, 115); //back up after stack
	wait1Msec(500);
}
