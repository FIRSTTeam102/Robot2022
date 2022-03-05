#include "commands/Indexer/SetIndexer.h"

SetIndexer::SetIndexer(Indexer* pIndexer, MotorDirection targetState) : mpIndexer{pIndexer}, mTargetState{targetState} {
	// Use addRequirements() here to declare subsystem dependencies.
	AddRequirements(pIndexer);
}

// Called when the command is initially scheduled.
void SetIndexer::Initialize() {
	switch (mTargetState) {
		case kOff:
			mpIndexer->stopIndexer();
			break;
		case kForward:
			mpIndexer->indexUp();
			break;
		case kReverse:
			mpIndexer->indexDown();
			break;
	}
}
