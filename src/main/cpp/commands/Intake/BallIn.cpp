#include "commands/Intake/BallIn.h"

BallIn::BallIn(Intake* pIntake, Indexer* pIndexer) : mpIntake{pIntake}, mpIndexer{pIndexer} {
	SetName("BallIn");
	AddRequirements(pIntake);
}

// Called just before this Command runs the first time
void BallIn::Initialize() {
	mpIntake->mLock = true;
	mpIntake->startRollers();
	mpIntake->lowerIntakeArm();
	mpIndexer->indexUp();
	Lights::GetInstance()->setMode(Lights::Mode::kIntake);
}

// Called repeatedly when this Command is scheduled to run
void BallIn::Execute() {
	if (mpIndexer->getSwitch()) {
		printf("switch true\n");
		mpIndexer->stopIndexer();
	}
}

// Make this return true when this Command no longer needs to run execute()
bool BallIn::IsFinished() {
	return false; // gets interrupted by button release
}

// Called once after isFinished returns true
void BallIn::End(bool interrupted) {
	mpIntake->mLock = false;
	mpIntake->stopRollers();
	mpIntake->raiseIntakeArm();
	mpIndexer->stopIndexer();
	Lights::GetInstance()->setDefault();
}