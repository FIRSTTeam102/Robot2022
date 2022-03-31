#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "commands/Shooter/StartShooter.h"
#include "commands/ShooterHood/SetHoodAngle.h"
#include "subsystems/Lights.h"
#include "subsystems/Limelight.h"
#include "subsystems/Shooter.h"
#include "subsystems/ShooterHood.h"

class LimelightShooterContinuous : public frc2::CommandHelper<frc2::CommandBase, LimelightShooterContinuous> {
	public:
		LimelightShooterContinuous(Limelight* pLimelight, Shooter* pShooter, ShooterHood* pShooterHood);
		void Initialize() override;
		void Execute() override;
		void End(bool interrupted) override;
		bool IsFinished() override;

	private:
		Limelight* mpLimelight;
		Shooter* mpShooter;
		ShooterHood* mpShooterHood;
};