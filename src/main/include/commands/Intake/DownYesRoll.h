#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Intake.h"

class DownYesRoll : public frc2::CommandHelper<frc2::CommandBase, DownYesRoll> {
	public:
		explicit DownYesRoll(Intake* pIntake);

		void Initialize() override;
		void Execute() override;
		bool IsFinished() override;
		void End(bool interrupted) override;

	private:
		Intake* mpIntake;
		int counter;
};