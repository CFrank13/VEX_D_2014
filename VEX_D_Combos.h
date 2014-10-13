#include "VEX_D_Drive.h"
#include "VEX_D_Manip.h"

void comboA()
{
	if(combo1)
	{
		setFlipperPiston(1);

		set6BarMotors(127);
		wait1Msec(100);
		set6BarMotors(0);

		setConveyorMotors(127);
		wait1Msec(1000);
		setConveyorMotors(0);

		setLeftDriveMotors(-127);
		setRightDriveMotors(127);
		wait1Msec(500);
		setLeftDriveMotors(0);
		setRightDriveMotors(0);

		setLeftDriveMotors(127);
		setRightDriveMotors(127);
		wait1Msec(750);
		setLeftDriveMotors(0);
		setRightDriveMotors(0);

		setConveyorMotors(127);
		wait1Msec(100);
		setConveyorMotors(0);

		setLeftDriveMotors(-127);
		setRightDriveMotors(-127);
		wait1Msec(500);
		setLeftDriveMotors(0);
		setRightDriveMotors(0);

		setConveyorMotors(127);
		wait1Msec(100);
		setConveyorMotors(0);

		setLeftDriveMotors(-127);
		setRightDriveMotors(-127);
		wait1Msec(100);
		setLeftDriveMotors(0);
		setRightDriveMotors(0);
	}
}

void updateCombos()
{
	comboA();
}
