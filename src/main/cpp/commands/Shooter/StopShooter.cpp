#include "commands/Shooter/StopShooter.h"

StopShooter::StopShooter(Shooter* pShooter): mpShooter{pShooter} {
	SetName("StopShooter");
	AddRequirements(pShooter);
}

// Called just before this Command runs the first time
void StopShooter::Initialize() {
	mpShooter->stopShooter();
	mpShooter->mShuffleboardReady.SetBoolean(false);
}

// Called repeatedly when this Command is scheduled to run
void StopShooter::Execute() {
}

// Make this return true when this Command no longer needs to run execute()
bool StopShooter::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void StopShooter::End(bool interrupted) {
}
