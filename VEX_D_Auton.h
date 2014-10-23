#include "VEX_D_Drive.h"
#include "VEX_D_Manip.h"

//stack 1 cube
void basicAuton_Stack()
{
	auton6Bar(65, 500);
	autonDrive(-127, -127, 2500);
}
