#include "commands/Limelight/AimbotSequential.h"

AimbotSequential::AimbotSequential(Limelight *pLimelight, ShootSequential *pShootSequential, SwerveDrive *pSwerveDrive) {
	SetName("AimbotSequential");
	AddCommands(SetShootSpeed(pShootSequential, pLimelight), YawToTarget(pLimelight, pSwerveDrive));
}