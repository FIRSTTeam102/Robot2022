#include "commands/Indexer/Backward.h"

Backward::Backward(Indexer* pIndexer): mpIndexer{pIndexer} {
	SetName("Backward");
	AddRequirements(pIndexer);
}

// Called just before this Command runs the first time
void Backward::Initialize() {
	mpIndexer->indexDown();
}

// Called repeatedly when this Command is scheduled to run
void Backward::Execute() {
}

// Make this return true when this Command no longer needs to run execute()
bool Backward::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Backward::End(bool interrupted) {
	mpIndexer->stopIndexer();
}