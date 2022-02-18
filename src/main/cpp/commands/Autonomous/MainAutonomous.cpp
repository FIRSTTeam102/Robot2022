#include "commands/Autonomous/MainAutonomous.h"

MainAutonomous::MainAutonomous(Indexer* pIndexer, Intake* pIntake, Limelight* pLM, Shooter* pShooter, SwerveDrive* pSwerveDrive, frc::XboxController* pController) : mpIndexer{pIndexer}, mpIntake{pIntake}, mpLM{pLM}, mpShooter{pShooter}, mpSwerve{pSwerveDrive}, mpController{pController} {
	AddCommands(
		SetArm(mpIntake, frc::DoubleSolenoid::Value::kForward),
		SetRollers(mpIntake, MotorDirection::kForward),
		MoveLinearTimed(mpSwerve, 0.8, 0.8), 
		TurnDegreesGyro(mpSwerve, 0.7, 180),
		// LM stuff when ready
		// SetArm(mpIntake, frc::DoubleSolenoid::Value::kReverse),
		StartShooter(mpShooter, ShooterConstants::kMedSpeed, new RumbleController(mpController)),
		SetIndexer(mpIndexer, MotorDirection::kForward),
		// frc2::WaitUntilCommand([this] { return mpIndexer->getSwitch(); }),
		frc2::WaitCommand(2.0_s),
		SetIndexer(mpIndexer, MotorDirection::kOff),
		StopShooter(mpShooter),
		SetRollers(mpIntake, MotorDirection::kOff)
	);
}
