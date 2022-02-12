#include "commands/SwerveDrive/RunSwerveDrive.h"

RunSwerveDrive::RunSwerveDrive(SwerveDrive *pSwerveDrive) : mpSwerveDrive{pSwerveDrive} {
	SetName("RunSwerveDrive");
	AddRequirements(mpSwerveDrive);
}

// Called just before this Command runs the first time
void RunSwerveDrive::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void RunSwerveDrive::Execute() {
	// mpSwerveDrive->controllerSwerve();
}

// Make this return true when this Command no longer needs to run execute()
bool RunSwerveDrive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void RunSwerveDrive::End(bool interrupted) {
}