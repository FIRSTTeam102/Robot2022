#include "commands/Shooter/BallPiston/ExtendRetract.h"

ExtendRetract::ExtendRetract() {
	SetName("ExtendRetract");
}

// Called just before this Command runs the first time
void ExtendRetract::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void ExtendRetract::Execute() {
}

// Make this return true when this Command no longer needs to run execute()
bool ExtendRetract::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ExtendRetract::End(bool interrupted) {
}