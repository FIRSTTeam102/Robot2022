#include "commands/Autonomous/MainAutonomous.h"

MainAutonomous::MainAutonomous(Indexer* pIndexer, Intake* pIntake, Limelight* pLM, Shooter* pShooter, SwerveDrive* pSwerveDrive) : mpIndexer{pIndexer}, mpIntake{pIntake}, mpLM{pLM}, mpShooter{pShooter}, mpSwerve{pSwerveDrive} {
	AddCommands(
		SetArm(mpIntake, frc::DoubleSolenoid::Value::kForward),
		SetRollers(mpIntake, MotorDirection::kForward),
		frc2::WaitCommand(0.6_s),
		SetAnglesCommand(mpSwerve, 0.0),
		frc2::WaitCommand(0.5_s),
		SetSpeedsTimed(mpSwerve, 0.65, 1.3),
		frc2::WaitCommand(0.2_s),
		TurnDegreesGyro(mpSwerve, 0.75, 170),
		// LM stuff when ready
		// SetArm(mpIntake, frc::DoubleSolenoid::Value::kReverse),
		StartShooter(mpShooter, ShooterConstants::kMedSpeed),
		SetIndexer(mpIndexer, MotorDirection::kForward),
		frc2::WaitUntilCommand([&] { return mpIndexer->getSwitch(); }),
		frc2::WaitCommand(2.0_s),
		SetIndexer(mpIndexer, MotorDirection::kOff),
		StopShooter(mpShooter),
		SetRollers(mpIntake, MotorDirection::kOff)
	);
}
