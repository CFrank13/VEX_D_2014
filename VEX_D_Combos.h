#include "VEX_D_Drive.h"
#include "VEX_D_Manip.h"
//TODO: measure out real values

//stack cube
void blueAuton1()
{

}

//stack skyrise piece + cube
void blueAuton2()
{
	setFlipperPiston(1); //flip up the flipper

	auton6Bar(127, 100); //raise the 6Bar slightly to be able to pick up a cube

	autonConveyor(127, 1000); //roll up the conveyer, picking up the cube, and putting it to the correct height

	autonDrive(-127, 127, 500); //manuever into position to pick up skyrise piece
	autonDrive(127, 127, 750);

	autonDrive(127, 127, 500); //drive forward to grab skyrise piece

	autonConveyor(127, 100); //move conveyor and 6Bar up slightly to lift piece
	auton6Bar(127, 100);

	autonDrive(-127, -127, 100); //back up a bit

	auton6Bar(-127, 500); //reset 6bar to floor position

	autonConveyor(-127, 500); //lower conveyor to drop off skyrise piece

	autonDrive(127, 127, 500); //move into position to drop off cube

	autonConveyor(-127, 300); //drop cube

	autonDrive(-127, -127, 300); //make sure we are not touching the cube
}

//ram cube pyramid
void blueAuton3()
{

}

//stack cube
void redAuton1()
{

}
//stack skyrise piece + cube
void redAuton2()
{

}
//ram cube pyramid
void redAuton3()
{

}

void blueAuton(int autonNumber)
{
	if(autonNumber == 1)
	{
		blueAuton1();
	}
	else if(autonNumber == 2)
	{
		blueAuton2();
	}
	else if(autonNumber == 3)
	{
		blueAuton3();
	}
}

void redAuton(int autonNumber)
{
	if(autonNumber == 1)
	{
		redAuton1();
	}
	else if(autonNumber == 2)
	{
		redAuton2();
	}
	else if(autonNumber == 3)
	{
		redAuton3();
	}
}
