#include "commands/SwerveDrive/MoveLinearTimed.h"

MoveLinearTimed::MoveLinearTimed(SwerveDrive* pSwerveDrive, double speed, double time, double angle) : mpSwerveDrive{pSwerveDrive}, mSpeed{speed}, mAngle{angle}, mTicks{(int) (time * 50.0)} {
	// Use addRequirements() here to declare subsystem dependencies.
	AddRequirements(pSwerveDrive);
	mCounter = 0;
}

// Called when the command is initially scheduled.
void MoveLinearTimed::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void MoveLinearTimed::Execute() {
	mpSwerveDrive->autoDrive(mAngle, mSpeed);
	mCounter++;
}

// Called once the command ends or is interrupted.
void MoveLinearTimed::End(bool interrupted) {
	mpSwerveDrive->stopDrive();
}

// Returns true when the command should end.
bool MoveLinearTimed::IsFinished() {
	return (mCounter >= mTicks);
}
