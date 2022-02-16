#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>

#include "Constants.h"
#include "commands/Indexer/SetIndexer.h"
#include "commands/Intake/ArmToggle.h"
#include "commands/Intake/SetRollers.h"
#include "commands/Limelight/YawToTarget.h"
#include "commands/Shooter/StartShooter.h"
#include "commands/Shooter/StopShooter.h"
#include "commands/SwerveDrive/TurnDegreesGyro.h"
#include "commands/SwerveDrive/MoveLinearTimed.h"

#include "subsystems/Indexer.h"
#include "subsystems/Intake.h"
#include "subsystems/Limelight.h"
#include "subsystems/Shooter.h"
#include "subsystems/SwerveDrive.h"

class MainAutonomous : public frc2::CommandHelper<frc2::SequentialCommandGroup, MainAutonomous> {
	public:
		MainAutonomous(Indexer* pIndexer, Intake* pIntake, Limelight* pLM, Shooter* pShooter, SwerveDrive* pSwerveDrive);

	private:
		Indexer* mpIndexer;
		Intake* mpIntake;
		Limelight* mpLM;
		Shooter* mpShooter;
		SwerveDrive* mpSwerve;
};
