#include "commands/SwerveDrive/TurnDegreesGyro.h"

TurnDegreesGyro::TurnDegreesGyro(SwerveDrive* pSwerveDrive, double speed, double degrees): mpSwerveDrive{pSwerveDrive}, mSpeed{speed}, mTargetDegs{degrees} {
	// Use addRequirements() here to declare subsystem dependencies.
	AddRequirements(pSwerveDrive);
}

// Called when the command is initially scheduled.
void TurnDegreesGyro::Initialize() {
	mpSwerveDrive->resetGyro();
	printf("Gyro reset to %f\n", mpSwerveDrive->getGyroAngle());
	mpSwerveDrive->setAutoState(true);

}

// Called repeatedly when this Command is scheduled to run
void TurnDegreesGyro::Execute() {
	mpSwerveDrive->vectorSwerve(0, 0, ( (mTargetDegs >= 0) ? mSpeed : -mSpeed ));
	printf("Gyro Angle: %f, Target Angle: %f\n", mpSwerveDrive->getGyroAngle(), mTargetDegs);
}

// Called once the command ends or is interrupted.
void TurnDegreesGyro::End(bool interrupted) {
	mpSwerveDrive->stopDrive();
	mpSwerveDrive->setAutoState(false);
	printf("Stopping... \n");
	if (interrupted) {
		printf("INTERRUPTED\n");
	}
}

// Returns true when the command should end.
bool TurnDegreesGyro::IsFinished() {
	if (mTargetDegs >= 0) {
		return (mpSwerveDrive->getGyroAngle() >= mTargetDegs);
	} else {
		return (mpSwerveDrive->getGyroAngle() <= mTargetDegs);
	}
}
