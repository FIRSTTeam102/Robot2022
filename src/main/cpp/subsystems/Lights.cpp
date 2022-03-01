#include "subsystems/Lights.h"

Lights* Lights::mpLightsInstance = NULL;

#ifdef ARDUINO
Lights::Lights() : mArduino{9600, frc::SerialPort::kUSB1}
#else
Lights::Lights()
#endif
{
	SetName("Lights");
	SetSubsystem("Lights");

#ifdef ARDUINO
	mArduino.EnableTermination();
	mArduino.Reset();
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