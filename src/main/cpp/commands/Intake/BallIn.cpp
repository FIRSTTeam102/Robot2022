#include "commands/Intake/BallIn.h"

BallIn::BallIn(Intake* pIntake, Indexer* pIndexer) : mpIntake{pIntake}, mpIndexer{pIndexer} {
	SetName("BallIn");
	AddRequirements(pIntake);
}

// Called just before this Command runs the first time
void BallIn::Initialize() {
	mIndexerAlreadyGotBall = false;
	mpIntake->mLock = true;
	mpIntake->startRollers();
	mpIntake->lowerIntakeArm();
	if (!mpIndexer->getSwitch()) mpIndexer->indexUp();
	Lights::setMode(Lights::kIntake);
}

// Called repeatedly when this Command is scheduled to run
void BallIn::Execute() {
	if (mpIndexer->getSwitch() && !mIndexerAlreadyGotBall) {
		printf("switch true\n");
		mpIndexer->stopIndexer();
		mIndexerAlreadyGotBall = true;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool BallIn::IsFinished() {
	return false; // gets interrupted by button release
}

// Called once after isFinished returns true
void BallIn::End(bool interrupted) {
	mIndexerAlreadyGotBall = true;
	mpIntake->mLock = false;
	mpIntake->stopRollers();
	mpIntake->raiseIntakeArm();
	mpIndexer->stopIndexer();
	Lights::setDefault();
}