#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Shooter.h"

class StopShooter : public frc2::CommandHelper<frc2::CommandBase, StopShooter> {
	public:
		explicit StopShooter(Shooter* pShooter);

		void Initialize() override;
		void Execute() override;
		bool IsFinished() override;
		void End(bool interrupted) override;

	private:
		Shooter* mpShooter;
};
