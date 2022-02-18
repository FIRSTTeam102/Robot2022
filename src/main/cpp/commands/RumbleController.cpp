#include "commands/RumbleController.h"

RumbleController::RumbleController(frc::XboxController* pController, int ticks, bool left, bool right) : mpController{pController}, mTicks{ticks}, mLeft{left}, mRight{right} {}

// Called when the command is initially scheduled.
void RumbleController::Initialize() {
	// printf("RUMBLE RUMBLE\n");
	if (mLeft) mpController->SetRumble(frc::GenericHID::RumbleType::kLeftRumble, 1);
	if (mRight) mpController->SetRumble(frc::GenericHID::RumbleType::kRightRumble, 1);
}

// Called repeatedly when this Command is scheduled to run
void RumbleController::Execute() {
	// printf("RUMBLE TICKS %d\n", mTicks);
	mTicks--;
}

// Called once the command ends or is interrupted.
void RumbleController::End(bool interrupted) {
	// printf("STOP RUMBLE\n");
	if (mLeft) mpController->SetRumble(frc::GenericHID::RumbleType::kLeftRumble, 0);
	if (mRight) mpController->SetRumble(frc::GenericHID::RumbleType::kRightRumble, 0);
}

// Returns true when the command should end.
bool RumbleController::IsFinished() {
	return mTicks < 0;
}
