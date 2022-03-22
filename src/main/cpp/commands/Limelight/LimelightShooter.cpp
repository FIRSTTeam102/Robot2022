#include "commands/Limelight/LimelightShooter.h"

LimelightShooter::LimelightShooter(Limelight *pLimelight, Shooter *pShooter, ShooterHood *pShooterHood) {
	SetName("LimelightShooter");

	AddCommands(StartShooter(pShooter, pLimelight), SetHoodAngle(pShooterHood, pLimelight));
}

// void LimelightShooter::Initialize() {
// 	Lights::GetInstance()->setMode(Lights::Mode::kLimelight);
// }

// void LimelightShooter::End(bool interrupted) {
// 	Lights::GetInstance()->setDefault();
// }