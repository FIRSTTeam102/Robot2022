#pragma once

#include <frc/DoubleSolenoid.h>
#include <frc2/command/CommandHelper.h>
#include <frc2/command/InstantCommand.h>

#include "subsystems/Intake.h"

class SetArm : public frc2::CommandHelper<frc2::InstantCommand, SetArm> {
	public:
		SetArm(Intake* pIntake, frc::DoubleSolenoid::Value state);

		void Initialize() override;

	private:
		Intake* mpIntake;
		frc::DoubleSolenoid::Value mState;
};
