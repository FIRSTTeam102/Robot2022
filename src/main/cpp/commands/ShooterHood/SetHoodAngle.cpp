#include "commands/ShooterHood/SetHoodAngle.h"

// SetHoodAngle based on hardcoded value
SetHoodAngle::SetHoodAngle(double degrees, ShooterHood* pShooterHood) : mDegrees{degrees}, mpShooterHood{pShooterHood}, mpLimelight{NULL} {
	AddRequirements(pShooterHood);
}

// SetHoodAngle based on distance from target determined by Limelight
SetHoodAngle::SetHoodAngle(ShooterHood* pShooterHood, Limelight* pLimelight) : mDegrees{0}, mpShooterHood{pShooterHood}, mpLimelight{pLimelight} {
	AddRequirements({pShooterHood, pLimelight});
}

// Called when the command is initially scheduled.
void SetHoodAngle::Initialize() {
	if (mpLimelight) mDegrees = mpLimelight->getServoAngle();

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
