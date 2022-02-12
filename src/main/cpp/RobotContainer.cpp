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
	mDriverButtonA.WhenPressed(&mSlowShooterCommand);
	mDriverButtonB.WhenPressed(&mMedShooterCommand);
	mDriverButtonY.WhenPressed(&mFastShooterCommand);
	mDriverButtonX.WhenPressed(&mStopShooterCommand);
	
	mOperatorButtonLMenu.WhenPressed(&mActuatorUp);
	mOperatorButtonRMenu.WhenPressed(&mActuatorDown);

	mDriverButtonLB.ToggleWhenPressed(&mBallInCommand);

	mDriverRT.WhenHeld(&mIndexUpCommand);

	mDriverDownDPad.WhenHeld(&mIndexDownCommand);
	mDriverLeftDPad.ToggleWhenPressed(&mBallOutCommand);	
	mDriverRightDPad.ToggleWhenPressed(&mClimbCommand);

	mDriverButtonRMenu.WhenPressed(&mArmToggleCommand);
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
	// The selected command will be run in autonomous
	return mChooser.GetSelected();
}
