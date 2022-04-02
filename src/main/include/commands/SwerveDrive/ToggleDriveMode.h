#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/InstantCommand.h>

#include "subsystems/SwerveDrive.h"

class ToggleDriveMode : public frc2::CommandHelper<frc2::InstantCommand, ToggleDriveMode> {
	public:
		ToggleDriveMode(SwerveDrive* pSwerveDrive);

		void Initialize() override;
		bool RunsWhenDisabled();

	private:
		SwerveDrive* mpSwerveDrive;
};
