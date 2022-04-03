#include "commands/Autonomous/OneBallAuto.h"

OneBallAuto::OneBallAuto(Indexer* pIndexer, Shooter* pShooter, ShooterHood* pShooterHood, Limelight* pLM, SwerveDrive* pSwerve) {
	AddCommands(
		frc2::ParallelDeadlineGroup(frc2::WaitCommand(0.5_s), YawToTarget(pLM, pSwerve)),
		frc2::ParallelDeadlineGroup(frc2::WaitCommand(1.5_s), LimelightShooter(pLM, pShooter, pShooterHood)),
		SetIndexer(pIndexer, MotorDirection::kForward),
		frc2::WaitCommand(1.0_s),
		SetIndexer(pIndexer, MotorDirection::kOff),
		StopShooter(pShooter),
		SetAnglesCommand(pSwerve, 0.0),
		SetSpeedsTimed(pSwerve, -0.6, 1.5_s)
	);
}
