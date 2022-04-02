#pragma once

#include <frc/DigitalOutput.h>
#include <frc/DriverStation.h>

#include <bitset>

class Lights {
	public:
		enum Mode { // max of 8 modes
			kDisabled = 0,
			kTeleop = 1,
			kAuto = 2,
			kIntake = 4,
			kLimelight = 5,
			kShooting = 6,
			kClimb = 7
		};

		static void setAlliance();
		static void setMode(Mode mode);
		static void setDefault();

	private:
		Lights();

		static Lights* mpLightsInstance;
		static Lights* GetInstance() {
			if (mpLightsInstance == NULL) mpLightsInstance = new Lights();
			return mpLightsInstance;
		};

		frc::DigitalOutput mMode0{6};
		frc::DigitalOutput mMode1{7};
		frc::DigitalOutput mMode2{8};
		frc::DigitalOutput mAlliance{9};
};
