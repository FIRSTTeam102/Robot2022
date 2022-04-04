#include "commands/Limelight/YawUntilTarget.h"

YawUntilTarget::YawUntilTarget(Limelight* pLimelight, SwerveDrive* pSwerveDrive, double speed): mpLimelight{pLimelight}, mpSwerve{pSwerveDrive}, mSpeed{speed} {
	AddRequirements(pSwerveDrive);
}

// Called when the command is initially scheduled.
void YawUntilTarget::Initialize() {
	mZeroAngle = mpSwerve->getGyroAngle(); // get the angle we started at and use it as 0
}

// Called repeatedly when this Command is scheduled to run
void YawUntilTarget::Execute() {
	mpSwerve->vectorSwerve(0.0, 0.0, mSpeed, mZeroAngle);
}

// Called once the command ends or is interrupted.
void YawUntilTarget::End(bool interrupted) {
	mpSwerve->stopDrive();
}

// Returns true when the command should end.
bool YawUntilTarget::IsFinished() {
	return mpLimelight->Check();
}
