#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Shooter.h"

class StartShooter : public frc2::CommandHelper<frc2::CommandBase, StartShooter> {
	public:
		explicit StartShooter(Shooter* pShooter, double speed, bool useRpm = false);

		void Initialize() override;
		void Execute() override;
		bool IsFinished() override;
		void End(bool interrupted) override;

	private:
		Shooter* mpShooter;
		double mSpeed;
		double mTargetSpeed;
		double mRamp;
		bool mUseRpm;
};
