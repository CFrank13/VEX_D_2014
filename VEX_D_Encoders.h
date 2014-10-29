
static int LOW_6B = 65;
static int MEDIUM_6B = 175;
static int HIGH_6B = 515;

string encoderValueA;
string encoderValueB;

void updateEncoders(tSensors encoderA, tSensors encoderB)
{
	clearLCDLine(0);											// Clear line 1 (0) of the LCD
	clearLCDLine(1);											// Clear line 2 (1) of the LCD

	displayLCDString(0, 0, "Enc A: ");
	stringFormat(encoderValueA, "%d", SensorValue[encoderA],'E'); //Build the value to be displayed
	displayNextLCDString(encoderValueA);

	displayLCDString(1, 0, "Enc B: ");
	stringFormat(encoderValueB, "%d", SensorValue[encoderB],'E'); //Build the value to be displayed
	displayNextLCDString(encoderValueB);
}

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
