#include "commands/Intake/ArmControl.h"

ArmControl::ArmControl(Intake* pIntake) : mpIntake{pIntake} {
	SetName("ArmControl");
	AddRequirements(pIntake);
}

// Called just before this Command runs the first time
void ArmControl::Initialize() {
	mpIntake->startRollers();
	mpIntake->lowerIntakeArm();
}

// Called repeatedly when this Command is scheduled to run
void ArmControl::Execute() {
}

// Make this return true when this Command no longer needs to run execute()
bool ArmControl::IsFinished() {
}

// Called once after isFinished returns true
void ArmControl::End(bool interrupted) {
	// mpIntake->stopIntakeArm();
	mpIntake->stopRollers();
	mpIntake->raiseIntakeArm();
}