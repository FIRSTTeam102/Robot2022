#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Indexer.h"
#include "subsystems/Intake.h"
#include "subsystems/Shooter.h"

class BallOut : public frc2::CommandHelper<frc2::CommandBase, BallOut> {
	public:
		BallOut(Intake* pIntake, Indexer* pIndexer, Shooter* pShooter);
		void Initialize() override;
		void Execute() override;
		void End(bool interrupted) override;
		bool IsFinished() override;

	private:
		Intake* mpIntake;
		Indexer* mpIndexer;
		Shooter* mpShooter;
};
