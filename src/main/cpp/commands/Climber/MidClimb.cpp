#include "commands/Climber/MidClimb.h"

MidClimb::MidClimb(Climber *pClimber) : mpClimber{pClimber} {
	SetName("MidClimb");
	// AddRequirements(pClimber); // conflicts with HighClimb
}

// Called just before this Command runs the first time
void MidClimb::Initialize() {
	mpClimber->midArmsUp();
	Lights::GetInstance()->setMode(Lights::Mode::kClimb);
}

// Called repeatedly when this Command is scheduled to run
void MidClimb::Execute() {
}

// Make this return true when this Command no longer needs to run execute()
bool MidClimb::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void MidClimb::End(bool interrupted) {
	mpClimber->midArmsDown();
	Lights::GetInstance()->setDefault();
}