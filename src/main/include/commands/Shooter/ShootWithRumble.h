#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>

#include "commands/Shooter/StartShooter.h"
#include "commands/RumbleController.h"

class ShootWithRumble : public frc2::CommandHelper<frc2::SequentialCommandGroup, ShootWithRumble> {
	public:
		explicit ShootWithRumble(Shooter* pShooter, double speed);
		explicit ShootWithRumble(Shooter* pShooter, Limelight* pLimelight);
};
