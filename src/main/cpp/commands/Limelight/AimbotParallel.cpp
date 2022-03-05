#include "commands/Limelight/AimbotParallel.h"

AimbotParallel::AimbotParallel(Limelight *pLimelight, Shooter *pShooter) {
	SetName("AimbotParallel");
	
	AddCommands(StartShooter(pShooter, pLimelight, true), SetHoodAngle(pShooter, pLimelight));
}