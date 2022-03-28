#pragma once

#include <frc/Timer.h>
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include <cmath>

#include "subsystems/SwerveDrive.h"

class MoveVectorTimed : public frc2::CommandHelper<frc2::CommandBase, MoveVectorTimed> {
	public:
		MoveVectorTimed(SwerveDrive* pSwerveDrive, double x, double y, units::second_t time);
		void Initialize() override;
		void Execute() override;
		void End(bool interrupted) override;
		bool IsFinished() override;

	private:
		SwerveDrive* mpSwerveDrive;
		double mX;
		double mY;
		frc::Timer mTimer;
		units::second_t mTime;
};
