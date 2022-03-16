#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/InstantCommand.h>

#include "subsystems/Intake.h"
#include "Utilities.h"

class SetRollers : public frc2::CommandHelper<frc2::InstantCommand, SetRollers> {
	public:
		SetRollers(Intake* pIntake, MotorDirection targetState);

		void Initialize() override;

	private:
		Intake* mpIntake;
		MotorDirection mTargetState;
};
