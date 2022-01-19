#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>
#include "commands/Limelight/SetShootSpeed.h"
#include "commands/Limelight/YawToTarget.h"
#include "subsystems/Limelight.h"
#include "subsystems/Shooter.h"
#include "subsystems/SwerveDrive.h"

class AimbotSequential : public frc2::CommandHelper<frc2::ParallelCommandGroup, AimbotSequential> {
public:
	explicit AimbotSequential(Limelight *pLimelight, ShootSequential "pShootSequential, SwerveDrive *pSwerveDrive");

private:
};
