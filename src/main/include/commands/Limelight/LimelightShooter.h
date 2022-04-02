#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc2/command/ParallelCommandGroup.h>

#include "commands/Shooter/StartShooter.h"
#include "commands/ShooterHood/SetHoodAngle.h"
#include "subsystems/Lights.h"
#include "subsystems/Limelight.h"
#include "subsystems/Shooter.h"
#include "subsystems/ShooterHood.h"

class LimelightShooter : public frc2::CommandHelper<frc2::ParallelCommandGroup, LimelightShooter> {
	public:
		explicit LimelightShooter(Limelight *pLimelight, Shooter *pShooter, ShooterHood *pShooterHood);
		void Initialize();
		void End(bool interrupted);
};
