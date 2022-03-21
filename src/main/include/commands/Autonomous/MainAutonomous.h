#pragma once

#include <frc/DoubleSolenoid.h>
#include <frc/XboxController.h>
#include <frc2/command/CommandHelper.h>
#include <frc2/command/FunctionalCommand.h>
#include <frc2/command/SequentialCommandGroup.h>
#include <frc2/command/ParallelDeadlineGroup.h>
#include <frc2/command/PrintCommand.h>
#include <frc2/command/WaitCommand.h>
#include <frc2/command/WaitUntilCommand.h>

#include "Utilities.h"
#include "commands/Indexer/SetIndexer.h"
#include "commands/Intake/SetArm.h"
#include "commands/Intake/SetRollers.h"
#include "commands/Limelight/AimbotParallel.h"
#include "commands/Limelight/YawToTarget.h"
#include "commands/RumbleController.h"
#include "commands/Shooter/StartShooter.h"
#include "commands/Shooter/StopShooter.h"
#include "commands/SwerveDrive/MoveLinearTimed.h"
#include "commands/SwerveDrive/MoveVectorTimed.h"
#include "commands/SwerveDrive/SetAnglesCommand.h"
#include "commands/SwerveDrive/SetSpeedsTimed.h"
#include "commands/SwerveDrive/TurnDegreesGyro.h"
#include "subsystems/Indexer.h"
#include "subsystems/Intake.h"
#include "subsystems/Limelight.h"
#include "subsystems/Shooter.h"
#include "subsystems/ShooterHood.h"
#include "subsystems/SwerveDrive.h"

class MainAutonomous : public frc2::CommandHelper<frc2::SequentialCommandGroup, MainAutonomous> {
	public:
		MainAutonomous(Indexer* pIndexer, Intake* pIntake, Limelight* pLM, Shooter* pShooter, ShooterHood* pShooterHood, SwerveDrive* pSwerveDrive);

	private:
		Indexer* mpIndexer;
		Intake* mpIntake;
		Limelight* mpLM;
		Shooter* mpShooter;
		ShooterHood* mpShooterHood;
		SwerveDrive* mpSwerve;
};
