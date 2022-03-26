#include "subsystems/Lights.h"

Lights* Lights::mpLightsInstance = NULL;

Lights::Lights() {
	SetName("Lights");
	SetSubsystem("Lights");

	switch (frc::DriverStation::GetAlliance()) {
		case frc::DriverStation::Alliance::kRed:
			mAlliance.Set(1); // red
			break;

		default:
			mAlliance.Set(0); // blue
	}
}

Lights* Lights::GetInstance() {
	if (mpLightsInstance == NULL) mpLightsInstance = new Lights();
	return mpLightsInstance;
}

void Lights::Periodic() {
	// Put code here to be run every loop
}

// Example usage: Lights::GetInstance()->setMode(LightsMode::kOff);
void Lights::setMode(Mode _mode) {
	int mode = (int)_mode;

	std::bitset<3> binary(mode); // 3 binary outputs allows 2^3 different modes (8)
	mMode0.Set(binary.test(2)); // 1st output pin needs to be the leftmost (last) bitset value
	mMode1.Set(binary.test(1));
	mMode2.Set(binary.test(0)); // 3rd output pin needs to be the rightmost (first) bitset value

	printf("Set light mode to: %d (%d%d%d)\n", mode, mMode0.Get(), mMode1.Get(), mMode2.Get());
}

// Example usage: Lights::GetInstance()->setDefault();
void Lights::setDefault() {
	if (frc::DriverStation::IsAutonomous()) {
		setMode(Mode::kAuto);
	} else if (frc::DriverStation::IsTeleop()) {
		setMode(Mode::kTeleop);
	} else if (frc::DriverStation::IsDisabled()) {
		setMode(Mode::kDisabled);
	} else {
		setMode(Mode::kOff);
	}
}