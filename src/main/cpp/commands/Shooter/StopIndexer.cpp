
#include "commands/Shooter/StopIndexer.h"

StopIndexer::StopIndexer() {
	SetName("StopIndexer");
}

// Called just before this Command runs the first time
void StopIndexer::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void StopIndexer::Execute() {
}

// Make this return true when this Command no longer needs to run execute()
bool StopIndexer::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void StopIndexer::End(bool interrupted) {
}