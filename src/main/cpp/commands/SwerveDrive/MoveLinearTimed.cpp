#include "commands/SwerveDrive/MoveLinearTimed.h"

MoveLinearTimed::MoveLinearTimed(double speed, int time, SwerveDrive* pSwerveDrive) : mSpeed{speed}, mTicks{time * 40}, mpSwerveDrive{pSwerveDrive} {
	// Use addRequirements() here to declare subsystem dependencies.
	AddRequirements(pSwerveDrive);
	mCounter = 0;
}

// Called when the command is initially scheduled.
void MoveLinearTimed::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void MoveLinearTimed::Execute() {
	mpSwerveDrive->autoDrive(90, mSpeed);
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
