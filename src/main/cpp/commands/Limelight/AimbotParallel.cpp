#include "commands/Limelight/AimbotParallel.h"

AimbotParallel::AimbotParallel(Limelight *pLimelight, Shooter *pShooter, SwerveDrive *pSwerveDrive) : mpLimelight{pLimelight} {
	SetName("AimbotParallel");
	AddCommands(StartShooter(pShooter, mpLimelight->getShootSpeed(), true), 
		SetHoodAngle(mpLimelight->getServoAngle(), pShooter), 
		YawToTarget(pLimelight, pSwerveDrive));
}