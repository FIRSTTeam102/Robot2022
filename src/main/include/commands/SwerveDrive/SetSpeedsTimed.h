#pragma once

#include <frc/Timer.h>
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/SwerveDrive.h"

class SetSpeedsTimed : public frc2::CommandHelper<frc2::CommandBase, SetSpeedsTimed> {
	public:
		SetSpeedsTimed(SwerveDrive* pSwerveDrive, double speed, units::second_t time);
		void Initialize() override;
		void Execute() override;
		void End(bool interrupted) override;
		bool IsFinished() override;

	private:
		SwerveDrive* mpSwerveDrive;
		double mSpeed;
		frc::Timer mTimer;
		units::second_t mTime;
};
