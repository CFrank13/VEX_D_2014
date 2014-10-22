#include "VEX_D_Drive.h"
#include "VEX_D_Manip.h"

//stack 1 cube
void basicAuton_Stack()
{
	auton6Bar(65, 500);
	autonDrive(-127, -127, 2500);
}

//stacks 2 cubes
void blueAuton()
{
	//autonDrive(50, 50, 200);		//move foward to off-balance cube
	//auton6Bar(127, 120); 				//raise the 6Bar slightly to be able to pick up a cube
	//autonConveyor(-127, 2000); 	//roll up the conveyer, picking up the cube, and putting it to the correct height
	//autonDrive(50, 50, 720); 		//manuever into position to pick up second cube
	//autonConveyor(-127, 750); 		//pick up second cube
	//autonDrive(65, 0, 250);
	//autonDrive(65, 65, 500); 		//manuever into position to drop cubes
	//autonDrive(-65, 65, 750);
	//auton6Bar(127, 1000); 			//go to max height
	//autonConveyor(-127, 1000); 	//drop cubes
	//autonDrive(-65, -65, 200); 	//back up a bit
}

//stacks 2 cubes
void redAuton()
{
	//autonDrive(50, 50, 200);		//move foward to off-balance cube
	//auton6Bar(127, 120); 				//raise the 6Bar slightly to be able to pick up a cube
	//autonConveyor(-127, 2000); 	//roll up the conveyer, picking up the cube, and putting it to the correct height
	//autonDrive(50, 50, 720); 		//manuever into position to pick up second cube
	//autonConveyor(-127, 750); 		//pick up second cube
	//autonDrive(65, 0, 250);
	//autonDrive(65, 65, 500); 		//manuever into position to drop cubes
	//autonDrive(-65, 65, 750);
	//auton6Bar(127, 1000); 			//go to max height
	//autonConveyor(-127, 1000); 	//drop cubes
	//autonDrive(-65, -65, 200); 	//back up a bit
}
