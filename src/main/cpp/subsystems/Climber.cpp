#include "subsystems/Climber.h"

Climber::Climber() : mClimberSolenoidRight{frc::PneumaticsModuleType::REVPH, ClimberConstants::kClimberSolenoidRightUp, ClimberConstants::kClimberSolenoidRightDown}, mClimberSolenoidLeft{frc::PneumaticsModuleType::REVPH, ClimberConstants::kClimberSolenoidLeftUp, ClimberConstants::kClimberSolenoidLeftDown} {
	SetName("Climber");
	SetSubsystem("Climber");
}

void Climber::armsUp() {
	mClimberSolenoidRight.Set(frc::DoubleSolenoid::kForward);
	mClimberSolenoidLeft.Set(frc::DoubleSolenoid::kForward);
	printf("Climber arms raising\n");
}

void Climber::armsDown() {
	mClimberSolenoidRight.Set(frc::DoubleSolenoid::kReverse);
	mClimberSolenoidLeft.Set(frc::DoubleSolenoid::kReverse);
	printf("Climber arms descending\n");
}

void Climber::toggleArms() {
	mClimberSolenoidRight.Toggle();
	mClimberSolenoidLeft.Toggle();
	printf("Climber arms toggled\n");
}

void Climber::Periodic() {
	// Put code here to be run every loop
}