#include "commands/SwerveDrive/ResetGyro.h"

ResetGyro::ResetGyro(SwerveDrive* pSwerveDrive) : mpSwerveDrive{pSwerveDrive} {
	// Use addRequirements() here to declare subsystem dependencies.
	AddRequirements(pSwerveDrive);
}

// Called when the command is initially scheduled.
void ResetGyro::Initialize() {
	mpSwerveDrive->resetGyro();
}

// Called repeatedly when this Command is scheduled to run
void ResetGyro::Execute() {}

// Called once the command ends or is interrupted.
void ResetGyro::End(bool interrupted) {}

// Returns true when the command should end.
bool ResetGyro::IsFinished() {
	return true;
}
