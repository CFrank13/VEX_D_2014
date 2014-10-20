
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

//Encoders
int leftDriveEncoder = 0;
int rightDriveEncoder = 0;
int left6barEncoder = 0;
int right6barEncoder = 0;
int conveyorEncoder = 0;

void updateOI()
{
	leftDrive = vexRT[Ch3];
	rightDrive = vexRT[Ch2];

	intake = vexRT[Btn5U];
	outtake = vexRT[Btn5D];
	conveyorBrake = vexRT[Btn7L];

	raise6Bar = vexRT[Btn6U];
	drop6Bar = vexRT[Btn6D];

	leftDriveEncoder = SensorValue[left_drive_encoder];
	rightDriveEncoder = SensorValue[right_drive_encoder];
	left6barEncoder = SensorValue[left_6bar_encoder];
	right6barEncoder = SensorValue[right_6bar_encoder];
	conveyorEncoder = SensorValue[conveyor_encoder];
}

void resetDriveEncoders()
{
	SensorValue[left_drive_encoder] = 0;
	SensorValue[right_drive_encoder] = 0;
}

void reset6barEncoders()
{
	SensorValue[left_6bar_encoder] = 0;
	SensorValue[right_6bar_encoder] = 0;
}

void resetConveyorEncoder()
{
	SensorValue[conveyor_encoder] = 0;
}

void resetEncoders()
{
	resetDriveEncoders();
	reset6barEncoders();
	resetConveyorEncoder();
}
