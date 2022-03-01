#pragma once

#include <frc/DigitalInput.h>
#include <frc/DoubleSolenoid.h>
#include <frc/DriverStation.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/shuffleboard/ShuffleboardLayout.h>
#include <frc/shuffleboard/ShuffleboardTab.h>
#include <frc/Timer.h>
#include <frc2/command/SubsystemBase.h>

#include "Constants.h"
#include "commands/RumbleController.h"

class Climber : public frc2::SubsystemBase {
	public:
		Climber(frc::XboxController* pController);
		void Periodic() override;
		void armsUp();
		void armsDown();
		void toggleArms();

	private:
		frc::DoubleSolenoid mClimberSolenoidRight{frc::PneumaticsModuleType::REVPH, ClimberConstants::kClimberSolenoidRightUp, ClimberConstants::kClimberSolenoidRightDown};
		frc::DoubleSolenoid mClimberSolenoidLeft{frc::PneumaticsModuleType::REVPH, ClimberConstants::kClimberSolenoidLeftUp, ClimberConstants::kClimberSolenoidLeftDown};

		frc::DigitalInput mLineSensorLeft{ClimberConstants::kLineSensorLeft};
		frc::DigitalInput mLineSensorRight{ClimberConstants::kLineSensorRight};

		frc::XboxController* mpController;
		bool mLeftRumbling = false;
		bool mRightRumbling = false;
};