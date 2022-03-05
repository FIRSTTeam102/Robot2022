#include "commands/Intake/SetArm.h"

SetArm::SetArm(Intake* pIntake, frc::DoubleSolenoid::Value state) : mpIntake{pIntake}, mState{state} {
	AddRequirements(pIntake);
}

// Called when the command is initially scheduled.
void SetArm::Initialize() {
	mpIntake->setIntakeArm(mState);
}
