#include "commands/SwerveDrive/TurnDegreesGyro.h"

TurnDegreesGyro::TurnDegreesGyro(SwerveDrive* pSwerveDrive, double speed, double degrees): mpSwerveDrive{pSwerveDrive}, mSpeed{speed}, mTargetDegs{degrees} {
	AddRequirements(pSwerveDrive);
}

// Called when the command is initially scheduled.
void TurnDegreesGyro::Initialize() {
	mZeroAngle = mpSwerveDrive->getGyroAngle(); // get the angle we started at and use it as 0
	mpSwerveDrive->setAutoState(true);
}

// Called repeatedly when this Command is scheduled to run
void TurnDegreesGyro::Execute() {
	mpSwerveDrive->vectorSwerve(0, 0, ( (mTargetDegs >= 0) ? mSpeed : -mSpeed ), mZeroAngle);
	printf("[%s] gyro angle: %f, target angle: %f\n", GetName(), mpSwerveDrive->getGyroAngle(mZeroAngle), mTargetDegs);
}

// Called once the command ends or is interrupted.
void TurnDegreesGyro::End(bool interrupted) {
	mpSwerveDrive->stopDrive();
	mpSwerveDrive->setAutoState(false);
	printf("[%s] stopping...\n", GetName());
	if (interrupted) {
		printf("[%s] INTERRUPTED\n", GetName());
	}
}

// Returns true when the command should end.
bool TurnDegreesGyro::IsFinished() {
	if (mTargetDegs >= 0) {
		return (mpSwerveDrive->getGyroAngle(mZeroAngle) >= mTargetDegs);
	} else {
		return (mpSwerveDrive->getGyroAngle(mZeroAngle) <= mTargetDegs);
	}
}
