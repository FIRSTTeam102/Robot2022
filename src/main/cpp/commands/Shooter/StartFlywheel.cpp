#include "commands/Shooter/StartFlywheel.h"

StartFlywheel::StartFlywheel() {
	SetName("StartFlywheel");
}

// Called just before this Command runs the first time
void StartFlywheel::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void StartFlywheel::Execute() {
}

// Make this return true when this Command no longer needs to run execute()
bool StartFlywheel::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void StartFlywheel::End(bool interrupted) {
}