#include "subsystems/Climber.h"

Climber::Climber() : mClimberSolenoidRight{frc::PneumaticsModuleType::REVPH, ClimberConstants::kClimberSolenoidRight}, mClimberSolenoidLeft{frc::PneumaticsModuleType::REVPH, ClimberConstants::kClimberSolenoidLeft} {
	SetName("Climber");
	SetSubsystem("Climber");
}

void Climber::armsUp() {
	mClimberSolenoidRight.Set(true);
	mClimberSolenoidLeft.Set(true);
	printf("arms have ascended \n");
}

void Climber::armsDown() {
	mClimberSolenoidRight.Set(false);
	mClimberSolenoidLeft.Set(false);
	printf("arms have descended \n");
}

void Climber::toggleArms() {
	mClimberSolenoidRight.Toggle();
	mClimberSolenoidLeft.Toggle();
	printf("Arms have been toggled \n");
}

void Climber::Periodic() {
	// Put code here to be run every loop
}