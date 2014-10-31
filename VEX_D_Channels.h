
static int DEADZONE = 15;

//Drive
int leftDrive = 0;
int rightDrive = 0;

//Strafing
int strafeLeft = 0;
int strafeRight = 0;
int strafeSpeedToggle = 0;

//Lift
int raise6Bar = 0;
int drop6Bar = 0;

//Conveyer
int convey = 0;

//Preset Heights
int goLow = 0;
int goMedium = 0;
int goHigh = 0;

void updateChannels()
{
	leftDrive = vexRT[Ch3];
	rightDrive = vexRT[Ch2];

	strafeLeft = vexRT[Btn6U];
	strafeRight = vexRT[Btn6D];
	strafeSpeedToggle = vexRT[Btn8R];

	raise6Bar = vexRT[Btn5U];
	drop6Bar = vexRT[Btn5D];

	convey = vexRT[Ch3Xmtr2];

	goLow = vexRT[Btn5DXmtr2];
	goMedium = vexRT[Btn5UXmtr2];
	goHigh = vexRT[Btn6UXmtr2];
}
