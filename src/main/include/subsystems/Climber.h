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

namespace ClimberConstants {
	// Ports
	const int kClimberSolenoidRightUp = 0;
	const int kClimberSolenoidRightDown = 1;
	const int kClimberSolenoidLeftUp = 6;
	const int kClimberSolenoidLeftDown = 7;
	// const int kLineSensorLeft = 0;
	// const int kLineSensorRight = 1;
}

class Climber : public frc2::SubsystemBase {
	public:
		Climber();
		// Climber(frc::XboxController* pController);
		void Periodic() override;
		void armsUp();
		void armsDown();
		void toggleArms();

	private:
		frc::DoubleSolenoid mClimberSolenoidRight{frc::PneumaticsModuleType::REVPH, ClimberConstants::kClimberSolenoidRightUp, ClimberConstants::kClimberSolenoidRightDown};
		frc::DoubleSolenoid mClimberSolenoidLeft{frc::PneumaticsModuleType::REVPH, ClimberConstants::kClimberSolenoidLeftUp, ClimberConstants::kClimberSolenoidLeftDown};

		/* frc::DigitalInput mLineSensorLeft{ClimberConstants::kLineSensorLeft};
		frc::DigitalInput mLineSensorRight{ClimberConstants::kLineSensorRight};

		nt::NetworkTableEntry mShuffleboardSensorLeft;
		nt::NetworkTableEntry mShuffleboardSensorRight;

		frc::XboxController* mpController;
		bool mLeftRumbling = false;
		bool mRightRumbling = false; */
};