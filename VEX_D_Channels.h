
//Drive
int leftDrive = 0;
int rightDrive = 0;

//Conveyer
int intake = 0;
int outtake = 0;
int conveyorBrake = 0;

//Lift
int raise6Bar = 0;
int drop6Bar = 0;

//Preset Heights
int goFloor = 0;
int goLow = 0;
int goMedium = 0;
int goHigh = 0;

void updateChannels()
{
	leftDrive = vexRT[Ch3];
	rightDrive = vexRT[Ch2];

	intake = vexRT[Btn5U];
	outtake = vexRT[Btn5D];
	conveyorBrake = vexRT[Btn7L];

	raise6Bar = vexRT[Btn6U];
	drop6Bar = vexRT[Btn6D];

	goFloor = vexRT[Btn5DXmtr2];
	goLow = vexRT[Btn5UXmtr2];
	goMedium = vexRT[Btn6DXmtr2];
	goHigh = vexRT[Btn6UXmtr2];

}
