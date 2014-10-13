#pragma config(Sensor, dgtl12, flipper_piston, sensorDigitalOut)
#pragma config(Motor,  port1,           left_back_drive, tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           left_6bar_B,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           right_front_drive, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           left_conveyor, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           left_front_drive, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           right_conveyor, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           left_6bar_A,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           right_6bar_A,  tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           right_6bar_B,  tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          right_back_drive, tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)
#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c" //Main competition background code...do not modify!
#include "VEX_D_Combos.h"

void pre_auton()
{

}

task autonomous()
{

}

task usercontrol()
{
	while(true)
	{
		updateOI();
		updateDrive();
		updateManip();
		updateCombos();
	}

}