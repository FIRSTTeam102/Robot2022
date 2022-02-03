#include "commands/SwerveDrive/TurnDegreesGyro.h"

TurnDegreesGyro::TurnDegreesGyro(SwerveDrive* pSwerveDrive, double speed, double degrees): mpSwerveDrive{pSwerveDrive}, mSpeed{speed}, mTargetDegs{degrees} {
	// Use addRequirements() here to declare subsystem dependencies.
	AddRequirements(pSwerveDrive);
}

// Called when the command is initially scheduled.
void TurnDegreesGyro::Initialize() {
	mpSwerveDrive->resetGyro();
	mpSwerveDrive->setAutoState(true);
}

// Called repeatedly when this Command is scheduled to run
void TurnDegreesGyro::Execute() {
	mpSwerveDrive->vectorSwerve(0, 0, ( (mTargetDegs >= 0) ? mSpeed : -mSpeed ));
}

// Called once the command ends or is interrupted.
void TurnDegreesGyro::End(bool interrupted) {
	mpSwerveDrive->stopDrive();
	mpSwerveDrive->setAutoState(false);
}

// Returns true when the command should end.
bool TurnDegreesGyro::IsFinished() {
	if (mTargetDegs >= 0) {
		return (mpSwerveDrive->getGyroAngle() >= mTargetDegs);
	} else {
		return (mpSwerveDrive->getGyroAngle() <= mTargetDegs);
	}
}
