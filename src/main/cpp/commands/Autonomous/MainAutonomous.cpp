#include "commands/Autonomous/MainAutonomous.h"

MainAutonomous::MainAutonomous(Indexer* pIndexer, Intake* pIntake, Limelight* pLM, Shooter* pShooter, SwerveDrive* pSwerveDrive) : mpIndexer{pIndexer}, mpIntake{pIntake}, mpLM{pLM}, mpShooter{pShooter}, mpSwerve{pSwerveDrive} {
	AddCommands(
		SetArm(mpIntake, frc::DoubleSolenoid::Value::kForward),
		frc2::WaitCommand(0.6_s),
		SetRollers(mpIntake, MotorDirection::kForward),
		SetAnglesCommand(mpSwerve, 0.0),
		frc2::WaitCommand(0.3_s),
		SetSpeedsTimed(mpSwerve, 0.65, 1.5),
		frc2::WaitCommand(0.2_s),
		SetRollers(mpIntake, MotorDirection::kOff),
		TurnDegreesGyro(mpSwerve, 0.85, 180),
		// LM stuff when ready
		// SetArm(mpIntake, frc::DoubleSolenoid::Value::kReverse),
		StartShooter(mpShooter, ShooterConstants::kMedSpeed),
		frc2::WaitCommand(0.2_s),
		SetIndexer(mpIndexer, MotorDirection::kForward),
		SetRollers(mpIntake, MotorDirection::kForward),
		frc2::WaitUntilCommand([&] { return mpIndexer->getSwitch(); }),
		frc2::WaitCommand(2.0_s),
		SetIndexer(mpIndexer, MotorDirection::kOff),
		StopShooter(mpShooter)
	);
}
