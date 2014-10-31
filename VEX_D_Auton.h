#include "VEX_D_Drive.h"
#include "VEX_D_Manip.h"

//stack 1 cube (use this function if all else fails)
void basicStack()
{
	auton6Bar(65, 500);
	autonDrive(-127, -127, 2500);
}
