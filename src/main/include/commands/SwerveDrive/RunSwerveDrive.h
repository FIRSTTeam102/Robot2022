#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/SwerveDrive.h"

class RunSwerveDrive : public frc2::CommandHelper<frc2::CommandBase, RunSwerveDrive> {
	public:
		explicit RunSwerveDrive(SwerveDrive *pSwerveDrive);

		void Initialize() override;
		void Execute() override;
		bool IsFinished() override;
		void End(bool interrupted) override;

	private:
		SwerveDrive *mpSwerveDrive;
};
