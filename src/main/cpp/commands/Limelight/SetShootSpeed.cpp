#include "commands/Limelight/SetShootSpeed.h"

SetShootSpeed::SetShootSpeed() {
	SetName("SetShootSpeed");
}

// Called just before this Command runs the first time
void SetShootSpeed::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void SetShootSpeed::Execute() {
}

// Make this return true when this Command no longer needs to run execute()
bool SetShootSpeed::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void SetShootSpeed::End(bool interrupted) {
}