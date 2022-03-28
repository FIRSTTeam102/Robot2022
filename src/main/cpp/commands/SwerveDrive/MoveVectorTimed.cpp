#include "commands/SwerveDrive/MoveVectorTimed.h"

MoveVectorTimed::MoveVectorTimed(SwerveDrive* pSwerveDrive, double x, double y, units::second_t time) :
mpSwerveDrive{pSwerveDrive}, mX{x}, mY{y}, mTime{time} {
	AddRequirements(pSwerveDrive);
}

void MoveVectorTimed::Initialize() {
	mTimer.Start();
	mpSwerveDrive->setAutoState(true);
}

void MoveVectorTimed::Execute() {
	mpSwerveDrive->vectorSwerve(mX, mY, 0);
}

void MoveVectorTimed::End(bool interrupted) {
	mTimer.Stop();
	mpSwerveDrive->stopDrive();
	mpSwerveDrive->setAutoState(false);
}

bool MoveVectorTimed::IsFinished() {
	return mTimer.AdvanceIfElapsed(mTime);
}
