#pragma once

#include <frc/TimedRobot.h>
#include <frc2/command/Command.h>
#include <frc/Compressor.h>

#include "RobotContainer.h"
#include "subsystems/Lights.h"

class Robot : public frc::TimedRobot {
	public:
		void RobotInit() override;
		void RobotPeriodic() override;
		void DisabledInit() override;
		void DisabledPeriodic() override;
		void AutonomousInit() override;
		void AutonomousPeriodic() override;
		void TeleopInit() override;
		void TeleopPeriodic() override;
		void TestPeriodic() override;

	private:
		// Have it null by default so that if testing teleop it
		// doesn't have undefined behavior and potentially crash.
		frc::Compressor mCompressor{frc::PneumaticsModuleType::REVPH};

		frc2::Command* mAutonomousCommand = nullptr;

		RobotContainer* mContainer = RobotContainer::GetInstance();
};
