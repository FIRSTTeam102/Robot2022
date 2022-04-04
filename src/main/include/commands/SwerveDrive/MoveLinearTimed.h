#pragma once

#include <frc/Timer.h>
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/SwerveDrive.h"

class MoveLinearTimed : public frc2::CommandHelper<frc2::CommandBase, MoveLinearTimed> {
	public:
		MoveLinearTimed(SwerveDrive* pSwerveDrive, double speed, units::second_t time, double angle = 0.0);
		void Initialize() override;
		void Execute() override;
		void End(bool interrupted) override;
		bool IsFinished() override;

	private:
		SwerveDrive* mpSwerveDrive;
		double mSpeed;
		double mAngle;
		double mZeroAngle;
		frc::Timer mTimer;
		units::second_t mTime;
};
