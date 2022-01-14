#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

class ExtendRetract : public frc2::CommandHelper<frc2::CommandBase, ExtendRetract> {
public:
	explicit ExtendRetract();

	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End(bool interrupted) override;

private:
};
