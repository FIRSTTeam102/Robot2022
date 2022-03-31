#include "commands/Intake/BallOut.h"

#include "Utilities.h"

BallOut::BallOut(Intake* pIntake, Indexer* pIndexer, Shooter* pShooter) :
mpIntake{pIntake}, mpIndexer{pIndexer}, mpShooter{pShooter} {
	AddRequirements({pIntake, pIndexer});
}

void BallOut::Initialize() {
	if (!mpIntake->mLock) {
		mpIntake->lowerIntakeArm();
		mpIntake->startReverseRollers();
		mpIndexer->indexDown();
		mpShooter->enableReverse();
		mpShooter->setShooterPercent(-0.2);
	}
}

void BallOut::Execute() {}

void BallOut::End(bool interrupted) {
	if (!mpIntake->mLock) {
		mpIntake->raiseIntakeArm();
		mpIntake->stopRollers();
		mpIndexer->stopIndexer();
	}
	mpShooter->disableReverse();
	mpShooter->stopShooter();
}

bool BallOut::IsFinished() {
	return mpIntake->mLock; // true if it should just quit
}
