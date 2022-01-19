#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/Shooter.h"
#include "subsystems/Limelight.h"

class SetShootSpeed : public frc2::CommandHelper<frc2::CommandBase, SetShootSpeed> {
public:
	explicit SetShootSpeed(ShootSequential *pShootSequential, Limelight *Limelight);

	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End(bool interrupted) override;

private:
	ShootSequential *mpShootSequential;
	Limelight *mpLimelight;
	float rampUpSpeed;
};
