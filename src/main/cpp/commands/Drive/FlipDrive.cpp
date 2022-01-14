#include "commands/Drive/FlipDrive.h"

FlipDrive::FlipDrive() {
	SetName("FlipDrive");
}

// Called just before this Command runs the first time
void FlipDrive::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void FlipDrive::Execute() {
}

// Make this return true when this Command no longer needs to run execute()
bool FlipDrive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void FlipDrive::End(bool interrupted) {
}