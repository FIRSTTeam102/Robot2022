#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

class YawToTarget : public frc2::CommandHelper<frc2::CommandBase, YawToTarget> {
public:
	explicit YawToTarget();

	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End(bool interrupted) override;

private:
};
