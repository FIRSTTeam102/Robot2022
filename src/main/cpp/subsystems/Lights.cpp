#include "subsystems/Lights.h"

Lights* Lights::mpLightsInstance = NULL;

Lights::Lights() {}

// Example usage: Lights::setMode(LightsMode::kOff);
void Lights::setMode(Mode _mode) {
	auto i = GetInstance(); // make sure everything is initialized
	i->setAlliance();

	int mode = (int)_mode;

	std::bitset<3> binary(mode); // 3 binary outputs allows 2^3 different modes (8)
	i->mMode0.Set(binary.test(2)); // 1st output pin needs to be the leftmost (last) bitset value
	i->mMode1.Set(binary.test(1));
	i->mMode2.Set(binary.test(0)); // 3rd output pin needs to be the rightmost (first) bitset value

	printf("Set light mode to: %d (%d%d%d)\n", mode, i->mMode0.Get(), i->mMode1.Get(), i->mMode2.Get());
}

// Example usage: Lights::setDefault();
void Lights::setDefault() {
	if (frc::DriverStation::IsAutonomous()) {
		setMode(Mode::kAuto);
	} else if (frc::DriverStation::IsTeleop()) {
		setMode(Mode::kTeleop);
	} else {
		setMode(Mode::kDisabled);
	}
}

void Lights::setAlliance() {
	auto i = GetInstance();

	switch (frc::DriverStation::GetAlliance()) {
		case frc::DriverStation::Alliance::kRed:
			i->mAlliance.Set(1); // red
			break;

		default:
			i->mAlliance.Set(0); // blue
	}
}