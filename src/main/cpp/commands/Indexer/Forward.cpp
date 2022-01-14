#include "commands/Indexer/Forward.h"

Forward::Forward() {
	SetName("Forward");
}

// Called just before this Command runs the first time
void Forward::Initialize() {
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
}