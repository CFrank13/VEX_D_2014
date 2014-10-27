
static int FLOOR_6B = 60;
static int LOW_6B = 180;
static int MEDIUM_6B = 360;
static int HIGH_6B = 540;

void resetDriveEncoders()
{
	SensorValue[left_drive_encoder] = 0;
	SensorValue[right_drive_encoder] = 0;
}

void reset6BarEncoders()
{
	SensorValue[left_6Bar_encoder] = 0;
	SensorValue[right_6Bar_encoder] = 0;
}

void resetConveyorEncoder()
{
	SensorValue[conveyor_encoder] = 0;
}

void resetEncoders()
{
	resetDriveEncoders();
	reset6BarEncoders();
	resetConveyorEncoder();
}
