#pragma once

#include <frc/DriverStation.h>
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <networktables/NetworkTableEntry.h>

#include "subsystems/SwerveDrive.h"

class SwerveCalibrator : public frc2::CommandHelper<frc2::CommandBase, SwerveCalibrator> {
	public:
		SwerveCalibrator(SwerveDrive* pSwerveDrive);
		void Initialize() override;
		void Execute() override;
		void End(bool interrupted) override;
		bool IsFinished() override;

	private:
		SwerveDrive* mpSwerveDrive;
};
