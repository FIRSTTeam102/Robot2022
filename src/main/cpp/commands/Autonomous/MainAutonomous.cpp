#include "commands/Autonomous/MainAutonomous.h"

MainAutonomous::MainAutonomous(Indexer* pIndexer, Intake* pIntake, Limelight* pLM, Shooter* pShooter, SwerveDrive* pSwerveDrive) : mpIndexer{pIndexer}, mpIntake{pIntake}, mpLM{pLM}, mpShooter{pShooter}, mpSwerve{pSwerveDrive} {
	AddCommands(
		SetArm(mpIntake, frc::DoubleSolenoid::Value::kForward),
		frc2::WaitCommand(0.6_s),
		SetRollers(mpIntake, MotorDirection::kForward),
		SetAnglesCommand(mpSwerve, 0.0),
		frc2::WaitCommand(0.3_s),
		SetSpeedsTimed(mpSwerve, 0.65, 0.7),
		frc2::WaitCommand(0.4_s),
		TurnDegreesGyro(mpSwerve, 0.85, 171),
		SetRollers(mpIntake, MotorDirection::kOff),
		// LM stuff when ready
		// SetArm(mpIntake, frc::DoubleSolenoid::Value::kReverse),
		MoveLinearTimed(mpSwerve, 0.65, 0.3),
		StartShooter(mpShooter, ShooterConstants::kMedSpeed),
		frc2::WaitCommand(0.4_s),
		SetIndexer(mpIndexer, MotorDirection::kForward),
		SetRollers(mpIntake, MotorDirection::kForward),
		frc2::WaitUntilCommand([&] { return mpIndexer->getSwitch(); }),
		frc2::WaitCommand(3.5_s),
		SetIndexer(mpIndexer, MotorDirection::kOff),
		StopShooter(mpShooter),
		SetRollers(mpIntake, MotorDirection::kOff)
	);
}