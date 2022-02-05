#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc2/command/ParallelCommandGroup.h>

#include "commands/Limelight/YawToTarget.h"
#include "commands/Shooter/StartShooter.h"
#include "subsystems/Limelight.h"
#include "subsystems/Shooter.h"
#include "subsystems/SwerveDrive.h"

class AimbotParallel : public frc2::CommandHelper<frc2::ParallelCommandGroup, AimbotParallel> {
	public:
		explicit AimbotParallel(Limelight *pLimelight, Shooter *pShooter, SwerveDrive *pSwerveDrive);

	private:
		Limelight *mpLimelight;
};