#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Climber.h"

class Climb : public frc2::CommandHelper<frc2::CommandBase, Climb> {
	public:
		explicit Climb(Climber *pClimber);

		void Initialize() override;
		void Execute() override;
		bool IsFinished() override;
		void End(bool interrupted) override;

	private:
		Climber *mpClimber;
};
