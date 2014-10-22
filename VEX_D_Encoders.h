

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
