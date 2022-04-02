#include "commands/SwerveDrive/MoveLinearTimed.h"

MoveLinearTimed::MoveLinearTimed(SwerveDrive* pSwerveDrive, double speed, units::second_t time, double angle) :
mpSwerveDrive{pSwerveDrive}, mSpeed{speed}, mAngle{angle}, mTime{time} {
	AddRequirements(pSwerveDrive);
}

void MoveLinearTimed::Initialize() {
	mTimer.Start();
	mpSwerveDrive->setAutoState(true);
	mpSwerveDrive->resetGyro();
}

void MoveLinearTimed::Execute() {
	double targetAngle = mAngle - mpSwerveDrive->getGyroAngle();
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
