#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

class SetShootSpeed : public frc2::CommandHelper<frc2::CommandBase, SetShootSpeed> {
public:
	explicit SetShootSpeed();

	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End(bool interrupted) override;

private:
};
