#pragma once

#include <frc/XboxController.h>
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

class RumbleController : public frc2::CommandHelper<frc2::CommandBase, RumbleController> {
	public:
		explicit RumbleController(frc::XboxController *pController);

		void Initialize() override;
		void Execute() override;
		void End(bool interrupted) override;
		bool IsFinished() override;
	
	private:
		frc::XboxController* mpController;
		int mTicks;
};
