#include "commands/Limelight/AimbotParallel.h"

AimbotParallel::AimbotParallel(Limelight *pLimelight, Shooter *pShooter, ShooterHood *pShooterHood) {
	SetName("AimbotParallel");
	
	AddCommands(StartShooter(pShooter, pLimelight, true), SetHoodAngle(pShooterHood, pLimelight));
}

void AimbotParallel::Initialize() {
	Lights::GetInstance()->setMode(Lights::kLimelight);
}

void AimbotParallel::End(bool interrupted) {
	Lights::GetInstance()->setMode(Lights::kDefault);
}