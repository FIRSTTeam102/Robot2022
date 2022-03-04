#pragma once

#include <frc/XboxController.h>
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "commands/RumbleController.h"
#include "subsystems/Shooter.h"
#include "subsystems/Limelight.h"

class StartShooter : public frc2::CommandHelper<frc2::CommandBase, StartShooter> {
	public:
		explicit StartShooter(Shooter* pShooter, double speed , bool useRpm = false);
		explicit StartShooter(Shooter* pShooter, Limelight* pLimelight, bool useRpm = false);

		void Initialize() override;
		void Execute() override;
		bool IsFinished() override;
		void End(bool interrupted) override;


	private:
		Shooter* mpShooter;
		Limelight* mpLimelight;
		double mSpeed;
		double mTargetSpeed;
		RumbleController* mpRumbleControllerCommand;
		double mRamp;
		bool mUseRpm;
};
