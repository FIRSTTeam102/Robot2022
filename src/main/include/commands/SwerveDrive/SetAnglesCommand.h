#pragma once

#include <frc2/command/InstantCommand.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/SwerveDrive.h"

class SetAnglesCommand : public frc2::CommandHelper<frc2::InstantCommand, SetAnglesCommand> {
	public:
		SetAnglesCommand(SwerveDrive* pSwerveDrive, double angle);

		void Initialize() override;

	private:
		SwerveDrive* mpSwerveDrive;
		double mAngle;
};
