#include "commands/SwerveDrive/ToggleDriveMode.h"

ToggleDriveMode::ToggleDriveMode(SwerveDrive* pSwerveDrive) : mpSwerveDrive{pSwerveDrive} {
	SetName("ToggleDriveMode");
	AddRequirements(pSwerveDrive);
}

// Called just before this Command runs the first time
void ToggleDriveMode::Initialize() {
	mpSwerveDrive->changeOrientation();
}

// Called repeatedly when this Command is scheduled to run
void ToggleDriveMode::Execute() {
}

// Make this return true when this Command no longer needs to run execute()
bool ToggleDriveMode::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ToggleDriveMode::End(bool interrupted) {
}