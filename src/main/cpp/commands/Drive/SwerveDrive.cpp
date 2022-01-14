#include "commands/Drive/SwerveDrive.h"

SwerveDrive::SwerveDrive() {
	SetName("SwerveDrive");
}

// Called just before this Command runs the first time
void SwerveDrive::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void SwerveDrive::Execute() {
}

// Make this return true when this Command no longer needs to run execute()
bool SwerveDrive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void SwerveDrive::End(bool interrupted) {
}