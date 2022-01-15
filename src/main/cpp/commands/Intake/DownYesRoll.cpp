#include "commands/Intake/DownYesRoll.h"

DownYesRoll::DownYesRoll(Intake* pIntake) : mpIntake{pIntake} {
	SetName("DownYesRoll");
	AddRequirements(pIntake);
}

// Called just before this Command runs the first time
void DownYesRoll::Initialize() {
	mpIntake->startRollers();
	counter = 0;
}

// Called repeatedly when this Command is scheduled to run
void DownYesRoll::Execute() {
	mpIntake->lowerIntakeArm();
}

// Make this return true when this Command no longer needs to run execute()
bool DownYesRoll::IsFinished() {
	return counter >= 25;
}

// Called once after isFinished returns true
void DownYesRoll::End(bool interrupted) {
	mpIntake->stopIntakeArm();
}