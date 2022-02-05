#include "commands/Intake/ArmControl.h"

ArmControl::ArmControl(Intake* pIntake, Indexer* pIndexer) : mpIntake{pIntake}, mpIndexer{pIndexer} {
	SetName("ArmControl");
	AddRequirements(pIntake);
	AddRequirements(pIndexer);
}

// Called just before this Command runs the first time
void ArmControl::Initialize() {
	mpIntake->startRollers();
	mpIntake->lowerIntakeArm();
	// mpIndexer->indexUp();
	Lights::GetInstance()->setMode(Lights::Mode::kIntake);
}

// Called repeatedly when this Command is scheduled to run
void ArmControl::Execute() {
	if (mpIndexer->getSwitch()) mpIndexer->stopIndexer();
}

// Make this return true when this Command no longer needs to run execute()
bool ArmControl::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ArmControl::End(bool interrupted) {
	mpIntake->stopRollers();
	mpIntake->raiseIntakeArm();
	// mpIndexer->stopIndexer();
	Lights::GetInstance()->setMode(Lights::Mode::kDefault);
}