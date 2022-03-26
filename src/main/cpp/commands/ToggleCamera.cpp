#include "commands/ToggleCamera.h"

ToggleCamera::ToggleCamera(cs::UsbCamera* pCamera1, cs::UsbCamera* pCamera2) : mpCamera1{pCamera1}, mpCamera2{pCamera2} {}

void ToggleCamera::Initialize() {
	cs::VideoSink server = frc::CameraServer::GetServer();

	// printf("Current camera %s\n", server.GetSource().GetName().c_str());
	if (server.GetSource().GetName() == mpCamera1->GetName()) {
		server.SetSource(*mpCamera2);
	} else {
		server.SetSource(*mpCamera1);
	}
	// printf("New camera %s\n", server.GetSource().GetName().c_str());
}

bool ToggleCamera::RunsWhenDisabled() {
	return false;
}