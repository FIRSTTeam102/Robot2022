#include "commands/ShooterHood/SetHoodAngle.h"

SetHoodAngle::SetHoodAngle(double degrees, ShooterHood* pShooterHood): mDegrees{degrees}, mpShooterHood{pShooter} {
	// Use addRequirements() here to declare subsystem dependencies.
	AddRequirements(pShooterHood);
}

// Called when the command is initially scheduled.
void SetHoodAngle::Initialize() {
	mpShooterHood->setAngle(mDegrees);
}

// Called repeatedly when this Command is scheduled to run
void SetHoodAngle::Execute() {}

// Called once the command ends or is interrupted.
void SetHoodAngle::End(bool interrupted) {}

// Returns true when the command should end.
bool SetHoodAngle::IsFinished() {
	return mpShooterHood->isAtTarget();
}
