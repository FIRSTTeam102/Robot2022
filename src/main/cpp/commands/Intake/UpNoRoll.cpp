#include "commands/Intake/UpNoRoll.h"

UpNoRoll::UpNoRoll(Intake* pIntake) : mpIntake{pIntake} {
	SetName("UpNoRoll");
	AddRequirements(pIntake);
}

// Called just before this Command runs the first time
void UpNoRoll::Initialize() {
	mpIntake->stopRollers();
	counter = 0;
}

// Called repeatedly when this Command is scheduled to run
void UpNoRoll::Execute() {
	mpIntake->raiseIntakeArm();
	counter++;
}

// Make this return true when this Command no longer needs to run execute()
bool UpNoRoll::IsFinished() {
	return counter >= 25;
}

// Called once after isFinished returns true
void UpNoRoll::End(bool interrupted) {
	// mpIntake->stopIntakeArm();
}