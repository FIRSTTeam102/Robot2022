#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Climber.h"
#include "subsystems/Lights.h"

class MidClimb : public frc2::CommandHelper<frc2::CommandBase, MidClimb> {
	public:
		explicit MidClimb(Climber *pClimber);
		void Initialize() override;
		void Execute() override;
		bool IsFinished() override;
		void End(bool interrupted) override;

	private:
		Climber *mpClimber;
};
