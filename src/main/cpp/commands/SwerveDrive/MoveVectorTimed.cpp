#include "commands/SwerveDrive/MoveVectorTimed.h"

MoveVectorTimed::MoveVectorTimed(SwerveDrive* pSwerveDrive, double x, double y, double time) : 
	mpSwerveDrive{pSwerveDrive}, mX{x}, mY{y}, mTicks{(int) (time * 50.0)}
{
	// Use addRequirements() here to declare subsystem dependencies.
	AddRequirements(pSwerveDrive);
	mCounter = 0;
}

// Called when the command is initially scheduled.
void MoveVectorTimed::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void MoveVectorTimed::Execute() {
	mpSwerveDrive->vectorSwerve(mX, mY, 0);
}

// Called once the command ends or is interrupted.
void MoveVectorTimed::End(bool interrupted) {}

// Returns true when the command should end.
bool MoveVectorTimed::IsFinished() {
	return false;
}
