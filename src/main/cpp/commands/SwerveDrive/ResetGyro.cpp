#include "commands/SwerveDrive/ResetGyro.h"

ResetGyro::ResetGyro(SwerveDrive* pSwerveDrive) : mpSwerveDrive{pSwerveDrive} {
	// Use addRequirements() here to declare subsystem dependencies.
	AddRequirements(pSwerveDrive);
}

// Called when the command is initially scheduled.
void ResetGyro::Initialize() {
	mpSwerveDrive->resetGyro();
}

bool ResetGyro::RunsWhenDisabled() {
	return true;
}