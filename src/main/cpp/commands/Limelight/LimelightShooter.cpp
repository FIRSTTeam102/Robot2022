#include "commands/Limelight/LimelightShooter.h"

LimelightShooter::LimelightShooter(Limelight *pLimelight, Shooter *pShooter, ShooterHood *pShooterHood) {
	SetName("LimelightShooter");

	AddCommands(StartShooter(pShooter, pLimelight), SetHoodAngle(pShooterHood, pLimelight));
}

void LimelightShooter::Initialize() {
	ParallelCommandGroup::Initialize();
	Lights::setMode(Lights::kLimelight);
}

void LimelightShooter::End(bool interrupted) {
	ParallelCommandGroup::End(interrupted);
	Lights::setDefault();
}