#include "RobotContainer.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/ParallelRaceGroup.h>

RobotContainer* RobotContainer::mRobotContainer = NULL;

RobotContainer::RobotContainer() : mAutonomousCommand() {
	mSwerveDrive.SetDefaultCommand(std::move(mRunSwerveDrive));
	mSwerveDrive.setController(&mDriverController);

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
	mDriverButtonA.WhenPressed(&mResetGyro);
	mDriverButtonB.WhenPressed(&mFlipOrientation);

	mDriverButtonLB.WhenPressed(&mInvertedQuarterTurn);
	mDriverButtonRB.WhenPressed(&mQuarterTurn);
	mDriverLT.WhenPressed(&mInvertedHalfTurn);
	mDriverRT.WhenPressed(&mHalfTurn);
	mDriverLeftDPad.WhenPressed(&mInvertedFullTurn);
	mDriverRightDPad.WhenPressed(&mFullTurn);
	mDriverUpDPad.WhenPressed(&mFunnyTurn);

	mDriverButtonX.WhenPressed(&mBackward);
	mDriverButtonY.WhenPressed(&mForward);
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
	// The selected command will be run in autonomous
	return mChooser.GetSelected();
}
