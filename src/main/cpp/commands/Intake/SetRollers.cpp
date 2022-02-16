#include "commands/Intake/SetRollers.h"

SetRollers::SetRollers(Intake* pIntake, MotorDirection targetState) : mpIntake{pIntake}, mTargetState{targetState} {
	// Use addRequirements() here to declare subsystem dependencies.
	AddRequirements(pIntake);
}

// Called when the command is initially scheduled.
void SetRollers::Initialize() {
	if (!mTargetState)
		mpIntake->stopRollers();
	else if (mTargetState == MotorDirection::kForward)
		mpIntake->startRollers();
	else
		mpIntake->startReverseRollers();
}
