#include "commands/ToggleCamera.h"

ToggleCamera::ToggleCamera(cs::MjpegServer* pServer, cs::UsbCamera* pCamera1, cs::UsbCamera* pCamera2) :
mpServer{pServer}, mpCamera1{pCamera1}, mpCamera2{pCamera2} {}

void ToggleCamera::Initialize() {
	// printf("Current camera %s\n", mpServer->GetSource().GetName().c_str());
	if (mpServer->GetSource().GetName() == mpCamera1->GetName()) {
		mpServer->SetSource(*mpCamera2);
	} else {
		mpServer->SetSource(*mpCamera1);
	}
	// printf("New camera %s\n", mpServer->GetSource().GetName().c_str());
}