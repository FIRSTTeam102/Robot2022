#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <networktables/NetworkTableEntry.h>

// #include "commands/RumbleController.h"
#include "subsystems/Shooter.h"
#include "subsystems/Limelight.h"

class StartShooter : public frc2::CommandHelper<frc2::CommandBase, StartShooter> {
	public:
		explicit StartShooter(Shooter* pShooter, double speed);
		explicit StartShooter(Shooter* pShooter, Limelight* pLimelight);
		explicit StartShooter(Shooter* pShooter, nt::NetworkTableEntry* pNTEntry);

		void Initialize() override;
		void Execute() override;
		bool IsFinished() override;
		void End(bool interrupted) override;

	private:
		Shooter* mpShooter;
		Limelight* mpLimelight;
		nt::NetworkTableEntry* mpNTEntry;
		double mSpeed;
		double mTargetSpeed;
		double mRamp;
};
