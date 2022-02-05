#include "commands/Intake/BallIn.h"

BallIn::BallIn(Intake* pIntake, Indexer* pIndexer) : mpIntake{pIntake}, mpIndexer{pIndexer} {
	SetName("BallIn");
	AddRequirements(pIntake);
	AddRequirements(pIndexer);
}

// Called just before this Command runs the first time
void BallIn::Initialize() {
	mpIntake->startRollers();
	mpIntake->lowerIntakeArm();
	mpIndexer->indexUp();
}

// Called repeatedly when this Command is scheduled to run
void BallIn::Execute() {
	if (mpIndexer->getSwitch()) mpIndexer->stopIndexer();
}

// Make this return true when this Command no longer needs to run execute()
bool BallIn::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void BallIn::End(bool interrupted) {
	// mpIntake->stopIntakeArm();
	mpIntake->stopRollers();
	mpIntake->raiseIntakeArm();
	mpIndexer->stopIndexer();
}