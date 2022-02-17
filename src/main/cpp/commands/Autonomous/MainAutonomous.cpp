#include "commands/Autonomous/MainAutonomous.h"

MainAutonomous::MainAutonomous(Indexer* pIndexer, Intake* pIntake, Limelight* pLM, Shooter* pShooter, SwerveDrive* pSwerveDrive) : mpIndexer{pIndexer}, mpIntake{pIntake}, mpLM{pLM}, mpShooter{pShooter}, mpSwerve{pSwerveDrive} {
	AddCommands(
		SetArm(mpIntake, frc::DoubleSolenoid::Value::kForward),
		SetRollers(mpIntake, MotorDirection::kForward),
		MoveLinearTimed(mpSwerve, 0.8, 0.5), 
		TurnDegreesGyro(mpSwerve, 0.7, 180),
		// LM stuff when ready
		SetArm(mpIntake, frc::DoubleSolenoid::Value::kReverse),
		SetRollers(mpIntake, MotorDirection::kOff)
	);
}
