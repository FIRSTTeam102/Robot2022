#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Lights.h"
#include "subsystems/Limelight.h"
#include "subsystems/SwerveDrive.h"

class YawToTarget : public frc2::CommandHelper<frc2::CommandBase, YawToTarget> {
	public:
		explicit YawToTarget(Limelight *pLimelight, SwerveDrive *pSwerveDrive);

		void Initialize() override;
		void Execute() override;
		bool IsFinished() override;
		void End(bool interrupted) override;

	private:
		Limelight *mpLimelight;
		SwerveDrive *mpSwerveDrive;
};
