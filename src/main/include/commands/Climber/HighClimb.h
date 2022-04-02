#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Climber.h"
#include "subsystems/Lights.h"

class HighClimb : public frc2::CommandHelper<frc2::CommandBase, HighClimb> {
	public:
		explicit HighClimb(Climber *pClimber);
		void Initialize() override;
		void Execute() override;
		bool IsFinished() override;
		void End(bool interrupted) override;

		bool RunsWhenDisabled() { // keep state after re-enabling
			return true;
		}

	private:
		Climber *mpClimber;
};
