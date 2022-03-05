#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/InstantCommand.h>

#include "Constants.h"
#include "subsystems/Indexer.h"

class SetIndexer : public frc2::CommandHelper<frc2::InstantCommand, SetIndexer> {
	public:
		SetIndexer(Indexer* pIndexer, MotorDirection targetState);

		void Initialize() override;
	private:
		Indexer* mpIndexer;
		MotorDirection mTargetState;
};
