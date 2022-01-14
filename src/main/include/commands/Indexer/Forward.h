#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

class Forward : public frc2::CommandHelper<frc2::CommandBase, Forward> {
public:
	explicit Forward();

	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End(bool interrupted) override;
	bool RunsWhenDisabled() const override;

private:
};
