#include "commands/SwerveDrive/SetSpeedsTimed.h"

SetSpeedsTimed::SetSpeedsTimed(SwerveDrive* pSwerveDrive, double speed, units::second_t time) :
mpSwerveDrive{pSwerveDrive}, mSpeed{speed}, mTime{time} {
	AddRequirements(pSwerveDrive);
}

void SetSpeedsTimed::Initialize() {
	mTimer.Start();
	mpSwerveDrive->setAutoState(true);
}

void SetSpeedsTimed::Execute() {
	mpSwerveDrive->setSpeeds(mSpeed);
}

void SetSpeedsTimed::End(bool interrupted) {
	mTimer.Stop();
	mpSwerveDrive->setAutoState(false);
	mpSwerveDrive->stopDrive();
}

bool SetSpeedsTimed::IsFinished() {
	return mTimer.AdvanceIfElapsed(mTime);
}
