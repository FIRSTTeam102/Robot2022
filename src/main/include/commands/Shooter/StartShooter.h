#pragma once

#include <frc/XboxController.h>
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "commands/RumbleController.h"
#include "subsystems/Shooter.h"
#include "subsystems/Limelight.h"

enum class SpeedSettings { SLOW, MED, FAST, LMDET};

class StartShooter : public frc2::CommandHelper<frc2::CommandBase, StartShooter> {
	public:
		explicit StartShooter(Shooter* pShooter, Limelight* pLimelight,  SpeedSettings speedVal , bool useRpm = false);

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
		SpeedSettings mUseSpeed;
};
