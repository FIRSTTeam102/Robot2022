#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

class FlipDrive : public frc2::CommandHelper<frc2::CommandBase, FlipDrive> {
public:
	explicit FlipDrive();

	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End(bool interrupted) override;
	bool RunsWhenDisabled() const override;

private:
};
