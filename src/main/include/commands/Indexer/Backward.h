#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Indexer.h"

class Backward : public frc2::CommandHelper<frc2::CommandBase, Backward> {
	public:
		explicit Backward(Indexer* pIndexer);

		void Initialize() override;
		void Execute() override;
		bool IsFinished() override;
		void End(bool interrupted) override;

	private:
		Indexer* mpIndexer;
};
