#include "VEX_D_Drive.h"
#include "VEX_D_Manip.h"

//stack 1 cube (use this function if all else fails)
void basicStack()
{
	auton6Bar(65, 500);
	autonDrive(-127, -127, 2500);
}

//stack 3 skyrise pieces with cube (red side)
void triStack()
{
//	(repeat 3 times)
//	{
//		set conveyor to skyrise height
//		maneuver until we face the skyrise piece (drive forward slightly, turn to the right)
//		drive forward into skyrise piece
//		raise conveyor to pick up piece
//		maneuver into position to stack piece (back up slightly, turn to the left, drive forward)
//		lower conveyor
//		back up
//	}
//	flip conveyor over to stack cube
}
