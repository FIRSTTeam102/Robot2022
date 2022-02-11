// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Shooter/SetHoodAngle.h"

SetHoodAngle::SetHoodAngle(double degrees, Shooter* pShooter): mDegrees{degrees}, mpShooter{pShooter} {
	// Use addRequirements() here to declare subsystem dependencies.
	AddRequirements(pShooter);
}

// Called when the command is initially scheduled.
void SetHoodAngle::Initialize() {
	double length = mpShooter->degreesToLinearLength(mDegrees);
	mSetting = mpShooter->linearLengthToSetting(length);

	mpShooter->setActuator(mSetting); 
	printf("Setting Hood Angle... "); // for testing
}

// Called repeatedly when this Command is scheduled to run
void SetHoodAngle::Execute() {

}

// Called once the command ends or is interrupted.
void SetHoodAngle::End(bool interrupted) {
	printf("Hood Angle Set");
	if (interrupted) printf("Process interrupted");
}

// Returns true when the command should end.
bool SetHoodAngle::IsFinished() {
	// use less than comparison if less than 0 because negatives are funny ig
	if ( mSetting < 0 ) return ( mSetting <= mpShooter->getHoodSetting() );
	else return ( mSetting >= mpShooter->getHoodSetting() );
}
