#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

class StartFlywheel : public frc2::CommandHelper<frc2::CommandBase, StartFlywheel> {
public:
	explicit StartFlywheel();

	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End(bool interrupted) override;

private:
};
