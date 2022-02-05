#include "RobotContainer.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/ParallelRaceGroup.h>

RobotContainer* RobotContainer::mRobotContainer = NULL;

RobotContainer::RobotContainer() : mAutonomousCommand() {
	// SmartDashboard Buttons
	mSwerveDrive.setController(&mDriverController);
	mSwerveDrive.SetDefaultCommand(std::move(mRunSwerveDrive));

	ConfigureButtonBindings();

	mChooser.SetDefaultOption("Autonomous Command", new AutonomousCommand());

	frc::SmartDashboard::PutData("Auto Mode", &mChooser);
}

RobotContainer* RobotContainer::GetInstance() {
	if (mRobotContainer == NULL) {
		mRobotContainer = new RobotContainer();
	}
	return (mRobotContainer);
}

void RobotContainer::ConfigureButtonBindings() {
	mOperatorButtonLB.ToggleWhenPressed(&mBallInCommand);
	mOperatorRT.WhenHeld(&mIndexUpCommand);
	mOperatorDownDPad.WhenHeld(&mIndexDownCommand);
	mOperatorButtonRMenu.WhenPressed(&mArmToggleCommand);
	mOperatorLeftDPad.ToggleWhenPressed(&mBallOutCommand);	
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
	// The selected command will be run in autonomous
	return mChooser.GetSelected();
}
