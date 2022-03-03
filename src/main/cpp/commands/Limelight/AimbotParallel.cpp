#include "commands/Limelight/AimbotParallel.h"
#include <frc2/command/ScheduleCommand.h>

AimbotParallel::AimbotParallel(Limelight *pLimelight, Shooter *pShooter, SwerveDrive *pSwerveDrive) : mpLimelight{pLimelight} {
	SetName("AimbotParallel");
	
	
	AddCommands(StartShooter(pShooter, pLimelight, SpeedSettings::LMDET,true),
		SetHoodAngle(HoodSettings::LMDET, pShooter, pLimelight), 
		YawToTarget(pLimelight, pSwerveDrive));
	
		
}