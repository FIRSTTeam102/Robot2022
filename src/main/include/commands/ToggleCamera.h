#pragma once

#include <cameraserver/CameraServer.h>
#include <frc2/command/CommandHelper.h>
#include <frc2/command/InstantCommand.h>

class ToggleCamera : public frc2::CommandHelper<frc2::InstantCommand, ToggleCamera> {
	public:
		ToggleCamera(cs::MjpegServer* pServer, cs::UsbCamera* pCamera1, cs::UsbCamera* pCamera2);
		void Initialize() override;
		bool RunsWhenDisabled() {
			return true;
		}

	private:
		cs::MjpegServer* mpServer;
		cs::UsbCamera* mpCamera1;
		cs::UsbCamera* mpCamera2;
};
