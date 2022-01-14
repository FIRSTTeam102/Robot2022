#pragma once
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

class StopIndexer : public frc2::CommandHelper<frc2::CommandBase, StopIndexer> {
public:
	explicit StopIndexer();

	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End(bool interrupted) override;

private:
};
