#include "commands/ShooterHood/IncrementHoodAngle.h"

IncrementHoodAngle::IncrementHoodAngle(double degreeChange, ShooterHood* pShooterHood): mDegreeChange{degreeChange}, mpShooterHood{pShooterHood} {
	// Use addRequirements() here to declare subsystem dependencies.
	AddRequirements(pShooterHood);
}

// Called when the command is initially scheduled.
void IncrementHoodAngle::Initialize() {
	mpShooterHood->incrementAngle(mDegreeChange);
}

// Called repeatedly when this Command is scheduled to run
void IncrementHoodAngle::Execute() {}

// Called once the command ends or is interrupted.
void IncrementHoodAngle::End(bool interrupted) {}

// Returns true when the command should end.
bool IncrementHoodAngle::IsFinished() {
	return mpShooterHood->isAtTarget();
}
