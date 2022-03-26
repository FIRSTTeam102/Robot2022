#include "commands/Autonomous/MainAutonomous.h"

MainAutonomous::MainAutonomous(Indexer* pIndexer, Intake* pIntake, Limelight* pLM, Shooter* pShooter, ShooterHood* pShooterHood, SwerveDrive* pSwerveDrive) : mpIndexer{pIndexer}, mpIntake{pIntake}, mpLM{pLM}, mpShooter{pShooter}, mpShooterHood{pShooterHood}, mpSwerve{pSwerveDrive} {
	AddCommands(
		SetArm(mpIntake, frc::DoubleSolenoid::kForward),
		frc2::WaitCommand(0.3_s),
		SetRollers(mpIntake, MotorDirection::kForward),
		MoveLinearTimed(mpSwerve, 0.65, 1.5),
		frc2::WaitCommand(0.65_s),
		SetRollers(mpIntake, MotorDirection::kOff),
		TurnDegreesGyro(mpSwerve, 0.75, 160),
		// YawUntilTarget(mpLM, mpSwerve, 0.7),
		// LM stuff when ready
		// SetArm(mpIntake, frc::DoubleSolenoid::Value::kReverse),
		// MoveLinearTimed(mpSwerve, 0.75, 0.7),
		frc2::ParallelDeadlineGroup(frc2::WaitCommand(1.5_s), YawToTarget(mpLM, mpSwerve)),
		// frc2::ParallelDeadlineGroup(frc2::WaitCommand(1.0_s), YawToTarget(mpLM, mpSwerve)),
		// frc2::WaitUntilCommand([this] { return mpLM->Check(); }),
		frc2::ParallelDeadlineGroup(frc2::WaitCommand(2.0_s), AimbotParallel(mpLM, mpShooter, mpShooterHood)),
		// frc2::PrintCommand("Done spinning up"),
		frc2::WaitCommand(0.4_s),
		SetIndexer(mpIndexer, MotorDirection::kForward),
		frc2::WaitCommand(0.5_s),
		SetRollers(mpIntake, MotorDirection::kReverse),
		frc2::WaitCommand(0.1_s),
		SetRollers(mpIntake, MotorDirection::kForward),
		frc2::WaitUntilCommand([&] { return mpIndexer->getSwitch(); }),
		frc2::WaitCommand(2.0_s),
		SetIndexer(mpIndexer, MotorDirection::kOff),
		StopShooter(mpShooter),
		SetRollers(mpIntake, MotorDirection::kOff),
		SetArm(mpIntake, frc::DoubleSolenoid::kReverse),
		MoveLinearTimed(mpSwerve, -1, 0.9)
	);
}
