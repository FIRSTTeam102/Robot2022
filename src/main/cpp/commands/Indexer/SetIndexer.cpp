#include "commands/Indexer/SetIndexer.h"

SetIndexer::SetIndexer(Indexer* pIndexer, MotorDirection targetState) : mpIndexer{pIndexer}, mTargetState{targetState} {
	// Use addRequirements() here to declare subsystem dependencies.
	AddRequirements(pIndexer);
}

// Called when the command is initially scheduled.
void SetIndexer::Initialize() {
	if (!mTargetState)
		mpIndexer->stopIndexer();
	else if (mTargetState == MotorDirection::kForward)
		mpIndexer->indexUp();
	else
		mpIndexer->indexDown();
}
