#include "commands/SwerveDrive/SetSpeedsTimed.h"

SetSpeedsTimed::SetSpeedsTimed(SwerveDrive* pSwerveDrive, double speed, double time): mpSwerveDrive{pSwerveDrive}, mSpeed{speed}, mTicks{(int) (time * 50.0)} {
	AddRequirements(pSwerveDrive);
}

// Called when the command is initially scheduled.
void SetSpeedsTimed::Initialize() {
	mpSwerveDrive->setAutoState(true);
	mCounter = 0;
}

// Called repeatedly when this Command is scheduled to run
void SetSpeedsTimed::Execute() {
	mpSwerveDrive->setSpeeds(mSpeed);
	mCounter++;
}

// Called once the command ends or is interrupted.
void SetSpeedsTimed::End(bool interrupted) {
	mpSwerveDrive->setAutoState(false);
	mpSwerveDrive->stopDrive();
}

// Returns true when the command should end.
bool SetSpeedsTimed::IsFinished() {
	return (mCounter >= mTicks);
}
