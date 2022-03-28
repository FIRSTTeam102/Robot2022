#pragma once

#include <frc/Timer.h>
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/SwerveDrive.h"

class AutonomousLikeAController : public frc2::CommandHelper<frc2::CommandBase, AutonomousLikeAController> {
	public:
		AutonomousLikeAController(SwerveDrive* pSwerveDrive, double leftX, double leftY, double rightX, units::second_t time);
		void Initialize() override;
		void Execute() override;
		void End(bool interrupted) override;
		bool IsFinished() override;

	private:
		SwerveDrive* mpSwerveDrive;
		double mLeftX;
		double mLeftY;
		double mRightX;
		frc::Timer mTimer;
		units::second_t mTime;
};
