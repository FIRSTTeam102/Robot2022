#include "commands/SwerveDrive/ToggleDriveMode.h"

ToggleDriveMode::ToggleDriveMode(SwerveDrive* pSwerveDrive) : mpSwerveDrive{pSwerveDrive} {
	SetName("ToggleDriveMode");
	AddRequirements(pSwerveDrive);
}

// Called just before this Command runs the first time
void ToggleDriveMode::Initialize() {
	mpSwerveDrive->changeOrientation();
}

bool ToggleDriveMode::RunsWhenDisabled() {
	return true;
}