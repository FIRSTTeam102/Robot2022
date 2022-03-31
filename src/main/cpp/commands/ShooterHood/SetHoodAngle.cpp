#include "commands/ShooterHood/SetHoodAngle.h"

// SetHoodAngle based on hardcoded value
SetHoodAngle::SetHoodAngle(double degrees, ShooterHood* pShooterHood) :
mDegrees{degrees}, mpShooterHood{pShooterHood}, mpLimelight{NULL}, mpNTEntry{NULL} {
	SetName("SetHoodAngle");
	AddRequirements(pShooterHood);
}

// SetHoodAngle based on distance from target determined by Limelight
SetHoodAngle::SetHoodAngle(ShooterHood* pShooterHood, Limelight* pLimelight) :
mDegrees{0}, mpShooterHood{pShooterHood}, mpLimelight{pLimelight}, mpNTEntry{NULL} {
	SetName("SetHoodAngle");
	AddRequirements(pShooterHood);
}

SetHoodAngle::SetHoodAngle(ShooterHood* pShooterHood, nt::NetworkTableEntry* pNTEntry) :
mDegrees{0}, mpShooterHood{pShooterHood}, mpLimelight{NULL}, mpNTEntry{pNTEntry} {
	SetName("SetHoodAngle");
	AddRequirements(pShooterHood);
}

// Called when the command is initially scheduled.
void SetHoodAngle::Initialize() {
	if (mpLimelight) mDegrees = mpLimelight->getServoAngle();
	else if (mpNTEntry) mDegrees = mpNTEntry->GetDouble(0.0);

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
