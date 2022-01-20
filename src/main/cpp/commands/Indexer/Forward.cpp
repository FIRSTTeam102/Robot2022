#include "commands/Indexer/Forward.h"

Forward::Forward(Indexer* pIndexer): mpIndexer{pIndexer} {
	SetName("Forward");
	AddRequirements(pIndexer);
}

// Called just before this Command runs the first time
void Forward::Initialize() {
	mpIndexer->indexUp();
}

// Called repeatedly when this Command is scheduled to run
void Forward::Execute() {
}

// Make this return true when this Command no longer needs to run execute()
bool Forward::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Forward::End(bool interrupted) {
	mpIndexer->stopIndexer();
}