// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Intake/ArmToggle.h"

ArmToggle::ArmToggle(Intake* pIntake): mpIntake{pIntake} {
	// Use addRequirements() here to declare subsystem dependencies.
	AddRequirements(pIntake);
}

// Called when the command is initially scheduled.
void ArmToggle::Initialize() {
	if (mpIntake->getArmState() == frc::DoubleSolenoid::Value::kForward) mpIntake->raiseIntakeArm();
	else mpIntake->lowerIntakeArm();
}

// Called repeatedly when this Command is scheduled to run
void ArmToggle::Execute() {}

// Called once the command ends or is interrupted.
void ArmToggle::End(bool interrupted) {}

// Returns true when the command should end.
bool ArmToggle::IsFinished() {
	return true;
}
