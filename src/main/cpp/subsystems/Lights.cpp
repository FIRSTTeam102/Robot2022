#include "subsystems/Lights.h"

Lights* Lights::mpLightsInstance = NULL;

Lights::Lights() : mArduino{9600, frc::SerialPort::kUSB} {
	SetName("Lights");
	SetSubsystem("Lights");

	mArduino.EnableTermination();
	mArduino.Reset();
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
	char* buffer = (char*)mode;

	mArduino.Write(buffer, 64);
	printf("Set light mode to: %s\n", buffer);
}