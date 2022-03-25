#include "commands/Intake/BallOut.h"
#include "Utilities.h"

BallOut::BallOut(Intake* pIntake, Indexer* pIndexer): mpIntake{pIntake}, mpIndexer{pIndexer} {
	// Use addRequirements() here to declare subsystem dependencies.
	AddRequirements({pIntake, pIndexer});
}

// Called when the command is initially scheduled.
void BallOut::Initialize() {
	if (!mpIntake->mLock) {
		mpIntake->lowerIntakeArm();
		mpIntake->startReverseRollers();
		mpIndexer->indexDown();
	}
}

// Called repeatedly when this Command is scheduled to run
void BallOut::Execute() {}

// Called once the command ends or is interrupted.
void BallOut::End(bool interrupted) {
	if (!mpIntake->mLock) {
		mpIntake->raiseIntakeArm();
		mpIntake->stopRollers();
		mpIndexer->stopIndexer();
	}
}

// Returns true when the command should end.
bool BallOut::IsFinished() {
	return mpIntake->mLock; // true if it should just quit
}
