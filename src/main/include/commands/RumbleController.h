#pragma once

#include <frc/XboxController.h>
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

class RumbleController : public frc2::CommandHelper<frc2::CommandBase, RumbleController> {
	public:
		explicit RumbleController(frc::XboxController *pController, int ticks = 20, bool left = true, bool right = true);

		void Initialize() override;
		void Execute() override;
		void End(bool interrupted) override;
		bool IsFinished() override;
		bool RunsWhenDisabled() {
			return true;
		};
	
	private:
		frc::XboxController* mpController;
		int mTicks;
		bool mLeft;
		bool mRight;
};
