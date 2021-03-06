#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/SwerveDrive.h"

class TurnDegreesGyro
	: public frc2::CommandHelper<frc2::CommandBase, TurnDegreesGyro> {
	public:
		TurnDegreesGyro(SwerveDrive* pSwerveDrive, double speed, double degrees);

		void Initialize() override;

		void Execute() override;

		void End(bool interrupted) override;

		bool IsFinished() override;
	private:
		SwerveDrive* mpSwerveDrive;
		double mSpeed;
		double mTargetDegs;
};
