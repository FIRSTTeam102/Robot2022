#include "commands/Intake/UpNoRoll.h"

UpNoRoll::UpNoRoll() {
	SetName("UpNoRoll");
}

// Called just before this Command runs the first time
void UpNoRoll::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void UpNoRoll::Execute() {
}

// Make this return true when this Command no longer needs to run execute()
bool UpNoRoll::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void UpNoRoll::End(bool interrupted) {
}