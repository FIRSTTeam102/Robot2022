#include "commands/SwerveDrive/FlipDrive.h"

FlipDrive::FlipDrive(SwerveDrive* pSwerveDrive) : mpSwerveDrive{pSwerveDrive} {
	SetName("FlipDrive");
	AddRequirements(pSwerveDrive);
}

// Called just before this Command runs the first time
void FlipDrive::Initialize() {
	mpSwerveDrive->changeOrientation();
}

// Called repeatedly when this Command is scheduled to run
void FlipDrive::Execute() {
}

// Make this return true when this Command no longer needs to run execute()
bool FlipDrive::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void FlipDrive::End(bool interrupted) {
}