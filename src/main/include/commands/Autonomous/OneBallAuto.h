#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/ParallelDeadlineGroup.h>
#include <frc2/command/SequentialCommandGroup.h>
#include <frc2/command/WaitCommand.h>

#include "Utilities.h"
#include "commands/Indexer/SetIndexer.h"
#include "commands/Limelight/LimelightShooter.h"
#include "commands/Limelight/YawToTarget.h"
#include "commands/Shooter/StopShooter.h"
#include "commands/SwerveDrive/MoveLinearTimed.h"
#include "commands/SwerveDrive/SetAnglesCommand.h"
#include "commands/SwerveDrive/SetSpeedsTimed.h"
#include "subsystems/Indexer.h"
#include "subsystems/Limelight.h"
#include "subsystems/Shooter.h"
#include "subsystems/ShooterHood.h"
#include "subsystems/SwerveDrive.h"

class OneBallAuto : public frc2::CommandHelper<frc2::SequentialCommandGroup, OneBallAuto> {
	public:
		OneBallAuto(Indexer* pIndexer, Shooter* pShooter, ShooterHood* pShooterHood, Limelight* pLM, SwerveDrive* pSwerve);
};
