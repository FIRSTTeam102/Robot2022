#include "commands/Autonomous/MainAutonomous.h"

MainAutonomous::MainAutonomous(Indexer* pIndexer, Intake* pIntake, Limelight* pLM, Shooter* pShooter, ShooterHood* pShooterHood, SwerveDrive* pSwerveDrive) : mpIndexer{pIndexer}, mpIntake{pIntake}, mpLM{pLM}, mpShooter{pShooter}, mpShooterHood{pShooterHood}, mpSwerve{pSwerveDrive} {
	AddCommands(
		SetArm(mpIntake, frc::DoubleSolenoid::Value::kForward),
		frc2::WaitCommand(0.3_s),
		SetRollers(mpIntake, MotorDirection::kForward),
		SetAnglesCommand(mpSwerve, 0.0),
		frc2::WaitCommand(0.3_s),
		SetSpeedsTimed(mpSwerve, 0.65, 0.9),
		frc2::WaitCommand(0.4_s),
		TurnDegreesGyro(mpSwerve, 0.85, 167),
		SetRollers(mpIntake, MotorDirection::kOff),
		// LM stuff when ready
		// SetArm(mpIntake, frc::DoubleSolenoid::Value::kReverse),
		MoveLinearTimed(mpSwerve, 0.65, 1.0),
		frc2::ParallelDeadlineGroup(frc2::WaitCommand(1.0_s), YawToTarget(mpLM, mpSwerve)),
		// frc2::ParallelDeadlineGroup(frc2::WaitCommand(1.0_s), YawToTarget(mpLM, mpSwerve)),
		frc2::ParallelDeadlineGroup(frc2::WaitCommand(1.0_s), AimbotParallel(mpLM, mpShooter, mpShooterHood)),
		// frc2::PrintCommand("Done spinning up"),
		frc2::WaitCommand(0.4_s),
		SetIndexer(mpIndexer, MotorDirection::kForward),
		SetRollers(mpIntake, MotorDirection::kForward),
		// frc2::WaitUntilCommand([&] { return mpIndexer->getSwitch(); }),
		frc2::WaitCommand(3.0_s),
		SetIndexer(mpIndexer, MotorDirection::kOff),
		StopShooter(mpShooter),
		SetRollers(mpIntake, MotorDirection::kOff),
		SetAnglesCommand(mpSwerve, 0.0),
		frc2::WaitCommand(0.3_s),
		SetSpeedsTimed(mpSwerve, -0.7, 1.3)
	);
}
