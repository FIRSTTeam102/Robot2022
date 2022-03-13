#pragma once

#include <frc/DriverStation.h>
#include <frc/SerialPort.h>
#include <frc2/command/SubsystemBase.h>

#include <string>

#include "Constants.h"

// Prevent errors when no Arduino is attached
// #define ARDUINO

class Lights : public frc2::SubsystemBase {
	public:
		enum Mode {
			kOff = 0,
			kTeleop = 1,
			kDisabled = 2,
			kAuto = 3,
			kIntake = 4,
			kLimelight = 5,
			kShooting = 6,
			kClimb = 7,
			kAlliance = 8,
			kAllianceFire = 9
		};

		static Lights* GetInstance();
		void Periodic() override;
		void setMode(Mode mode);
		void setDefault();

	private:
		Lights();
		static Lights* mpLightsInstance;

#ifdef ARDUINO
		frc::SerialPort mArduino{9600, frc::SerialPort::kUSB1};
#endif
};
