#include "commands/SwerveDrive/MoveLinearTimed.h"

MoveLinearTimed::MoveLinearTimed(SwerveDrive* pSwerveDrive, double speed, units::second_t time, double angle) :
mpSwerveDrive{pSwerveDrive}, mSpeed{speed}, mAngle{angle}, mTime{time} {
	AddRequirements(pSwerveDrive);
}

void MoveLinearTimed::Initialize() {
	mTimer.Start();
	mpSwerveDrive->setAutoState(true);
	mZeroAngle = mpSwerveDrive->getGyroAngle(); // get the angle we started at and use it as 0
}

void MoveLinearTimed::Execute() {
	double targetAngle = mAngle - mpSwerveDrive->getGyroAngle(mZeroAngle);
	mpSwerveDrive->autoDrive(targetAngle, mSpeed);
}

void MoveLinearTimed::End(bool interrupted) {
	mTimer.Stop();
	mpSwerveDrive->stopDrive();
	mpSwerveDrive->setAutoState(false);
}

bool MoveLinearTimed::IsFinished() {
	return mTimer.AdvanceIfElapsed(mTime);
}
