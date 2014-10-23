
//TODO: get real height values
static int FLOOR_C = 360;
static int LOW_C = 540;
static int MEDIUM_C = 1080;
static int HIGH_C = 1260;

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
