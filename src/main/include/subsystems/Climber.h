#pragma once

#include <frc/DigitalInput.h>
#include <frc/DoubleSolenoid.h>
#include <frc/DriverStation.h>
#include <frc/Timer.h>
#include <frc2/command/SubsystemBase.h>
/* #include <frc/XboxController.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/shuffleboard/ShuffleboardLayout.h>
#include <frc/shuffleboard/ShuffleboardTab.h>
#include <networktables/NetworkTableEntry.h>
#include <networktables/NetworkTableValue.h>
#include <wpi/StringMap.h>

#include <memory>
#include <utility> */

class Climber : public frc2::SubsystemBase {
	public:
		Climber();
		// Climber(frc::XboxController* pController);
		void Periodic() override;

		void midArmsUp();
		void midArmsDown();
		void midArmsToggle();

		void highArmsUp();
		void highArmsDown();
		void highArmsToggle();

	private:
		frc::DoubleSolenoid mMidSolenoid{frc::PneumaticsModuleType::REVPH, 0, 1};
		frc::DoubleSolenoid mHighSolenoid{frc::PneumaticsModuleType::REVPH, 6, 7};

		/* frc::DigitalInput mLineSensorLeft{0};
		frc::DigitalInput mLineSensorRight{1};

		nt::NetworkTableEntry mShuffleboardSensorLeft;
		nt::NetworkTableEntry mShuffleboardSensorRight;

		frc::XboxController* mpController;
		bool mLeftRumbling = false;
		bool mRightRumbling = false; */
};