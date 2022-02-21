#include "commands/Autonomous/MainAutonomous.h"

MainAutonomous::MainAutonomous(Indexer* pIndexer, Intake* pIntake, Limelight* pLM, Shooter* pShooter, SwerveDrive* pSwerveDrive) : mpIndexer{pIndexer}, mpIntake{pIntake}, mpLM{pLM}, mpShooter{pShooter}, mpSwerve{pSwerveDrive} {
	AddCommands(
		SetArm(mpIntake, frc::DoubleSolenoid::Value::kForward),
		SetRollers(mpIntake, MotorDirection::kForward),
		MoveLinearTimed(mpSwerve, 0.65, 0.8), 
		TurnDegreesGyro(mpSwerve, 0.75, 180),
		// LM stuff when ready
		// SetArm(mpIntake, frc::DoubleSolenoid::Value::kReverse),
		StartShooter(mpShooter, ShooterConstants::kMedSpeed),
		SetIndexer(mpIndexer, MotorDirection::kForward),
		frc2::WaitUntilCommand([&] { return !(mpIndexer->getSwitch()); }),
		frc2::WaitCommand(2.0_s),
		SetIndexer(mpIndexer, MotorDirection::kOff),
		StopShooter(mpShooter),
		SetRollers(mpIntake, MotorDirection::kOff)
	);
}