#include "commands/Climber/Climb.h"

Climb::Climb(Climber *pClimber) : mpClimber{pClimber} {
	SetName("Climb");
	AddRequirements(mpClimber);
}

// Called just before this Command runs the first time
void Climb::Initialize() {
	mpClimber->armUp();
}

// Called repeatedly when this Command is scheduled to run
void Climb::Execute() {
}

// Make this return true when this Command no longer needs to run execute()
bool Climb::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Climb::End(bool interrupted) {
	mpClimber->armDown();
}