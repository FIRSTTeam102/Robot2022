#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/SwerveDrive.h"

class ResetGyro
	: public frc2::CommandHelper<frc2::CommandBase, ResetGyro> {
	public:
		ResetGyro(SwerveDrive* pSwerveDrive);

		void Initialize() override;

		void Execute() override;

		void End(bool interrupted) override;

		bool IsFinished() override;

	private:
		SwerveDrive* mpSwerveDrive;
};
