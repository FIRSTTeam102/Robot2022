#include "commands/Intake/DownYesRoll.h"

DownYesRoll::DownYesRoll() {
	SetName("DownYesRoll");
}

// Called just before this Command runs the first time
void DownYesRoll::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void DownYesRoll::Execute() {
}

// Make this return true when this Command no longer needs to run execute()
bool DownYesRoll::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DownYesRoll::End(bool interrupted) {
}