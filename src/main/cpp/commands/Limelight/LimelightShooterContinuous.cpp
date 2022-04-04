#include "commands/Limelight/LimelightShooterContinuous.h"

LimelightShooterContinuous::LimelightShooterContinuous(Limelight *pLimelight, Shooter *pShooter, ShooterHood *pShooterHood) :
mpLimelight{pLimelight}, mpShooter{pShooter}, mpShooterHood{pShooterHood} {
	SetName("LimelightShooterContinuous");
	AddRequirements({pShooter, pShooterHood});
}

void LimelightShooterContinuous::Initialize() {
	Lights::setMode(Lights::kLimelight);
}

void LimelightShooterContinuous::Execute() {
	mpShooterHood->setAngle(mpLimelight->getServoAngle());
	mpShooter->setShooter(mpLimelight->getShootSpeed());
}

void LimelightShooterContinuous::End(bool interrupted) {
	Lights::setDefault();
}

bool LimelightShooterContinuous::IsFinished() {
	return false;
}
