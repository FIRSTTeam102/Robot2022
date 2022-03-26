#include "commands/Limelight/YawUntilTarget.h"

YawUntilTarget::YawUntilTarget(Limelight* pLimelight, SwerveDrive* pSwerveDrive, double speed): mpLimelight{pLimelight}, mpSwerve{pSwerveDrive}, mSpeed{speed} {
	AddRequirements(pLimelight);
	AddRequirements(pSwerveDrive);
}

// Called when the command is initially scheduled.
void YawUntilTarget::Initialize() {
	mpSwerve->resetGyro();
	mpSwerve->vectorSwerve(0.0, 0.0, mSpeed);
}

// Called repeatedly when this Command is scheduled to run
void YawUntilTarget::Execute() {
	mpSwerve->vectorSwerve(0.0, 0.0, mSpeed);
}

// Called once the command ends or is interrupted.
void YawUntilTarget::End(bool interrupted) {
	mpSwerve->stopDrive();
}

// Returns true when the command should end.
bool YawUntilTarget::IsFinished() {
	return mpLimelight->Check();
}
