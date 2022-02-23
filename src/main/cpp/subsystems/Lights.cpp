#include "subsystems/Lights.h"

Lights* Lights::mpLightsInstance = NULL;

Lights::Lights() {
	SetName("Lights");
	SetSubsystem("Lights");

#ifdef ARDUINO
	mArduino.EnableTermination();
	mArduino.Reset();

	switch (frc::DriverStation::GetAlliance()) {
		case frc::DriverStation::Alliance::kRed:
			mArduino.Write("r");
			break;

		case frc::DriverStation::Alliance::kBlue:
			mArduino.Write("b");
			break;

		default:
			mArduino.Write("r");
	}
#endif
}

Lights* Lights::GetInstance() {
	if (mpLightsInstance == NULL) mpLightsInstance = new Lights();
	return mpLightsInstance;
}

void Lights::Periodic() {
	// Put code here to be run every loop
}

// Example usage: Lights::GetInstance()->setMode(LightsMode::kOff);
void Lights::setMode(Mode mode) {
	std::string_view buffer = std::to_string(mode);

#ifdef ARDUINO
	mArduino.Write(buffer);
#endif
	printf("Set light mode to: %s\n", buffer.data());
}