#include "commands/RumbleController.h"

RumbleController::RumbleController(frc::XboxController* pController) : mpController{pController} {}

// Called when the command is initially scheduled.
void RumbleController::Initialize() {
	mTicks = 20;
	// printf("RUMBLE RUMBLE\n");
	mpController->SetRumble(frc::GenericHID::RumbleType::kLeftRumble, 1);
	mpController->SetRumble(frc::GenericHID::RumbleType::kRightRumble, 1);
}

// Called repeatedly when this Command is scheduled to run
void RumbleController::Execute() {
	// printf("RUMBLE TICKS %d\n", mTicks);
	mTicks--;
}

// Called once the command ends or is interrupted.
void RumbleController::End(bool interrupted) {
	// printf("STOP RUMBLE\n");
	mpController->SetRumble(frc::GenericHID::RumbleType::kLeftRumble, 0);
	mpController->SetRumble(frc::GenericHID::RumbleType::kRightRumble, 0);
}

// Returns true when the command should end.
bool RumbleController::IsFinished() {
	return mTicks < 0;
}
