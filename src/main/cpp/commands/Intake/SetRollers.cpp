#include "commands/Intake/SetRollers.h"

SetRollers::SetRollers(Intake* pIntake, MotorDirection targetState) : mpIntake{pIntake}, mTargetState{targetState} {
	AddRequirements(pIntake);
}

// Called when the command is initially scheduled.
void SetRollers::Initialize() {
	switch (mTargetState) {
		case kOff:
			mpIntake->stopRollers();
			break;
		case kForward:
			mpIntake->startRollers();
			break;
		case kReverse:
			mpIntake->startReverseRollers();
	}
}
