#include "commands/Autonomous/MainAutonomous.h"

MainAutonomous::MainAutonomous(Indexer* pIndexer, Intake* pIntake, Limelight* pLM, Shooter* pShooter, ShooterHood* pShooterHood, SwerveDrive* pSwerveDrive) : mpIndexer{pIndexer}, mpIntake{pIntake}, mpLM{pLM}, mpShooter{pShooter}, mpShooterHood{pShooterHood}, mpSwerve{pSwerveDrive} {
	AddCommands(
		/*** go forwards and intake second ball ***/
		SetArm(mpIntake, frc::DoubleSolenoid::kForward),
		frc2::WaitCommand(0.3_s),
		SetRollers(mpIntake, MotorDirection::kForward),
		MoveLinearTimed(mpSwerve, 0.65, 1.5_s),
		frc2::WaitCommand(0.65_s),
		/*** turn around ***/
		TurnDegreesGyro(mpSwerve, 0.95, 20),
		SetRollers(mpIntake, MotorDirection::kOff), // turn off after turning a little
		TurnDegreesGyro(mpSwerve, 0.95, 130),
		frc2::ParallelDeadlineGroup(frc2::WaitCommand(0.5_s), YawToTarget(mpLM, mpSwerve)),
		// YawUntilTarget(mpLM, mpSwerve, 0.7)
		// SetArm(mpIntake, frc::DoubleSolenoid::Value::kReverse),
		/*** go forwards a little ***/
		MoveLinearTimed(mpSwerve, 0.75, 1.1_s),
		/*** align ***/
		frc2::ParallelDeadlineGroup(frc2::WaitCommand(1.2_s), YawToTarget(mpLM, mpSwerve)),
		// frc2::ParallelDeadlineGroup(frc2::WaitCommand(1.0_s), YawToTarget(mpLM, mpSwerve)),
		// frc2::WaitUntilCommand([this] { return mpLM->Check(); }),
		/*** spin up ***/
		frc2::ParallelDeadlineGroup(frc2::WaitCommand(1.3_s), LimelightShooter(mpLM, mpShooter, mpShooterHood)),
		// frc2::PrintCommand("Done spinning up"),
		frc2::WaitCommand(0.7_s),
		/*** shoot ball 1 ***/
		SetIndexer(mpIndexer, MotorDirection::kForward),
		frc2::WaitCommand(0.5_s),
		/*** shoot ball 2 ***/
		SetRollers(mpIntake, MotorDirection::kReverse),
		frc2::WaitCommand(0.1_s),
		SetRollers(mpIntake, MotorDirection::kForward),
		frc2::WaitUntilCommand([&] { return mpIndexer->getSwitch(); }),
		frc2::WaitCommand(2.0_s),
		/*** done shooting ***/
		SetIndexer(mpIndexer, MotorDirection::kOff),
		StopShooter(mpShooter),
		SetRollers(mpIntake, MotorDirection::kOff),
		SetArm(mpIntake, frc::DoubleSolenoid::kReverse),
		/*** go backwards ***/
		MoveLinearTimed(mpSwerve, -1, 0.9_s)
	);
}
