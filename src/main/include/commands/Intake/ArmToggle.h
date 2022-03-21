#pragma once

#include <frc/DoubleSolenoid.h>
#include <frc2/command/CommandHelper.h>
#include <frc2/command/InstantCommand.h>

#include "subsystems/Intake.h"

class ArmToggle : public frc2::CommandHelper<frc2::InstantCommand, ArmToggle> {
	public:
		ArmToggle(Intake* pIntake);

		void Initialize() override;

	private:
		Intake* mpIntake;
};
