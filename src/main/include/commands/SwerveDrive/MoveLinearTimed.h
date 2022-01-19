// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/SwerveDrive.h"

class MoveLinearTimed
	: public frc2::CommandHelper<frc2::CommandBase, MoveLinearTimed> {
	public:
		MoveLinearTimed(double speed, int ticks, SwerveDrive* pSwerveDrive);

		void Initialize() override;

		void Execute() override;

		void End(bool interrupted) override;

		bool IsFinished() override;

	private:
		SwerveDrive* mpSwerveDrive;
		double mSpeed;
		int mTicks;
		int mCounter;
};
