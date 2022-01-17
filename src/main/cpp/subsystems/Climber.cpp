#include "subsystems/Climber.h"

#include <frc/smartdashboard/SmartDashboard.h>

#include "Constants.h"

Climber::Climber() : mClimberSolenoid{frc::PneumaticsModuleType::REVPH, ClimberConstants::kClimberSelonoid} {
	SetName("Climber");
	SetSubsystem("Climber");
}

void Climber::armUp() {
	mClimberSolenoid.Set(true);
}
void Climber::armDown() {
	mClimberSolenoid.Set(false);
}
void Climber::armToggle() {
	mClimberSolenoid.Toggle();
}
void Climber::Periodic() {
	// Put code here to be run every loop
}