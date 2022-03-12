#include "commands/Limelight/AimbotParallel.h"

AimbotParallel::AimbotParallel(Limelight *pLimelight, Shooter *pShooter, ShooterHood *pShooterHood) {
	SetName("AimbotParallel");
	
	AddCommands(StartShooter(pShooter, pLimelight, true), SetHoodAngle(pShooterHood, pLimelight));
	// AddCommands(frc2::SequentialCommandGroup(StartShooter(pShooter, pLimelight, true), RumbleController(RobotContainer::GetInstance()->GetDriverController())), SetHoodAngle(pShooterHood, pLimelight));
}

// void AimbotParallel::Initialize() {
// 	Lights::GetInstance()->setMode(Lights::Mode::kLimelight);
// }

// void AimbotParallel::End(bool interrupted) {
// 	Lights::GetInstance()->setDefault();
// }