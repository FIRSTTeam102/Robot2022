#include "commands/Limelight/AimbotParallel.h"

AimbotParallel::AimbotParallel(Limelight *pLimelight, Shooter *pShooter, SwerveDrive *pSwerveDrive) : mpLimelight{pLimelight} {
	SetName("AimbotParallel");
	AddCommands(StartShooter(pShooter, mpLimelight->getShootSpeed()), YawToTarget(pLimelight, pSwerveDrive));
}