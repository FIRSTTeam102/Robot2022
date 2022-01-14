#include "commands/Limelight/YawToTarget.h"

YawToTarget::YawToTarget() {
	SetName("YawToTarget");
}

// Called just before this Command runs the first time
void YawToTarget::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void YawToTarget::Execute() {
}

// Make this return true when this Command no longer needs to run execute()
bool YawToTarget::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void YawToTarget::End(bool interrupted) {
}
