#include "commands/Autonomous/MainAutonomous.h"

MainAutonomous::MainAutonomous(Indexer* pIndexer, Intake* pIntake, Limelight* pLM, Shooter* pShooter, SwerveDrive* pSwerveDrive) : mpIndexer{pIndexer}, mpIntake{pIntake}, mpLM{pLM}, mpShooter{pShooter}, mpSwerve{pSwerveDrive} {
	// Add your commands here, e.g.
	// AddCommands(FooCommand(), BarCommand());
	AddCommands(ArmToggle(mpIntake), SetRollers(mpIntake, MotorDirection::kForward));
	AddCommands(MoveLinearTimed(mpSwerve, 0.8, 1.0), TurnDegreesGyro(mpSwerve, 0.7, 180));
	// LM stuff when ready
}
