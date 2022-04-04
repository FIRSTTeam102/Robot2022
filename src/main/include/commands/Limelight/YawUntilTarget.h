#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Limelight.h"
#include "subsystems/SwerveDrive.h"

class YawUntilTarget : public frc2::CommandHelper<frc2::CommandBase, YawUntilTarget> {
	public:
		YawUntilTarget(Limelight* pLimelight, SwerveDrive* pSwerveDrive, double speed);
		void Initialize() override;
		void Execute() override;
		void End(bool interrupted) override;
		bool IsFinished() override;
	
	private:
		Limelight* mpLimelight;
		SwerveDrive* mpSwerve;

		double mSpeed;
		double mZeroAngle;
};
