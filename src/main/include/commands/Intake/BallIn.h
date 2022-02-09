#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Indexer.h"
#include "subsystems/Intake.h"
#include "subsystems/Lights.h"

class BallIn : public frc2::CommandHelper<frc2::CommandBase, BallIn> {
	public:
		explicit BallIn(Intake* pIntake, Indexer* pIndexer);

		void Initialize() override;
		void Execute() override;
		bool IsFinished() override;
		void End(bool interrupted) override;

	private:
		Intake* mpIntake;
		Indexer* mpIndexer;
};