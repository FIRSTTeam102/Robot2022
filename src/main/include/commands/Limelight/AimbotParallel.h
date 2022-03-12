#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc2/command/ParallelCommandGroup.h>
#include <frc2/command/SequentialCommandGroup.h>

// #include "commands/Shooter/ShootWithRumble.h"
#include "commands/Shooter/StartShooter.h"
#include "commands/ShooterHood/SetHoodAngle.h"
#include "subsystems/Lights.h"
#include "subsystems/Limelight.h"
#include "subsystems/Shooter.h"
#include "subsystems/ShooterHood.h"

class AimbotParallel : public frc2::CommandHelper<frc2::ParallelCommandGroup, AimbotParallel> {
	public:
		explicit AimbotParallel(Limelight *pLimelight, Shooter *pShooter, ShooterHood *pShooterHood);
		// void Initialize() override;
		// void End(bool interrupted) override;
};
