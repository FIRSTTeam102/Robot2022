#include "commands/Intake/ArmToggle.h"

ArmToggle::ArmToggle(Intake* pIntake) : mpIntake{pIntake} {
	AddRequirements(pIntake);
}

// Called when the command is initially scheduled.
void ArmToggle::Initialize() {
	mpIntake->toggleIntakeArm();
}
