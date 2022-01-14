#include "commands/Shooter/StopFlywheel.h"

StopFlywheel::StopFlywheel() {
	SetName("StopFlywheel");
}

// Called just before this Command runs the first time
void StopFlywheel::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void StopFlywheel::Execute() {
}

// Make this return true when this Command no longer needs to run execute()
bool StopFlywheel::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void StopFlywheel::End(bool interrupted) {
}
