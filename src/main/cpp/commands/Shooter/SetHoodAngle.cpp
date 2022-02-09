// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Shooter/SetHoodAngle.h"

SetHoodAngle::SetHoodAngle(double setting, Shooter* pShooter): mSetting{setting}, mpShooter{pShooter} {
	// Use addRequirements() here to declare subsystem dependencies.
	AddRequirements(pShooter);
}

// Called when the command is initially scheduled.
void SetHoodAngle::Initialize() {
	mpShooter->setActuator(mSetting);
}

// Called repeatedly when this Command is scheduled to run
void SetHoodAngle::Execute() {}

// Called once the command ends or is interrupted.
void SetHoodAngle::End(bool interrupted) {}

// Returns true when the command should end.
bool SetHoodAngle::IsFinished() {
	return true;
}
