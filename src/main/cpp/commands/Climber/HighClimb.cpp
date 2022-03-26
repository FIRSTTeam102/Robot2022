#include "commands/Climber/HighClimb.h"

HighClimb::HighClimb(Climber *pClimber) : mpClimber{pClimber} {
	SetName("HighClimb");
	// AddRequirements(pClimber); // conflicts with MidClimb
}

// Called just before this Command runs the first time
void HighClimb::Initialize() {
	mpClimber->highArmsUp();
	Lights::GetInstance()->setMode(Lights::Mode::kClimb);
}

// Called repeatedly when this Command is scheduled to run
void HighClimb::Execute() {
}

// Make this return true when this Command no longer needs to run execute()
bool HighClimb::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void HighClimb::End(bool interrupted) {
	mpClimber->highArmsDown();
	Lights::GetInstance()->setDefault();
}