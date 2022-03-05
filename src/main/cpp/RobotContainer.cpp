#include "RobotContainer.h"

RobotContainer* RobotContainer::mRobotContainer = NULL;

RobotContainer::RobotContainer() {
	mSwerveDrive.setController(&mDriverController);
	mSwerveDrive.SetDefaultCommand(std::move(mRunSwerveDrive));

	ConfigureButtonBindings();

	mChooser.SetDefaultOption("Autonomous Command", new MainAutonomous(&mIndexer, &mIntake, &mLimelight, &mShooter, &mShooterHood, &mSwerveDrive));

	frc::SmartDashboard::PutData("Auto Mode", &mChooser);

	frc::DriverStation::SilenceJoystickConnectionWarning(true);
}

RobotContainer* RobotContainer::GetInstance() {
	if (mRobotContainer == NULL) {
		mRobotContainer = new RobotContainer();
	}
	return (mRobotContainer);
}

void RobotContainer::ConfigureButtonBindings() {
	/****** Driver ******/
	mDriverButtonA.WhenPressed(&mFlipMode);
	// mDriverButtonRMenu.WhenPressed(&mResetGyro);

	mDriverLT.WhenHeld(&mYawToTarget);

	mDriverRT.WhenHeld(&mIndexUpCommand);
	mDriverButtonRB.WhenHeld(&mIndexDownCommand);
	
	/****** Operator ******/
	mOperatorButtonA.WhenPressed(&mTarmacLower);
	mOperatorButtonB.WhenPressed(&mTarmacUpper);
	// mOperatorButtonY.WhenPressed(&mFastShooterCommand);
	mOperatorButtonX.WhenPressed(&mStopShooterCommand);

	mOperatorLT.WhenHeld(&mBallInCommand);
	mOperatorButtonLB.WhenHeld(&mBallOutCommand);

	mOperatorRT.WhenPressed(&mLimelightShooter);

	mOperatorUpDPad.WhenPressed(&mIncrementHood);
	mOperatorDownDPad.WhenPressed(&mDecrementHood);

	mOperatorButtonLMenu.ToggleWhenPressed(&mClimbCommand);
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
	// The selected command will be run in autonomous
	return mChooser.GetSelected();
}

void RobotContainer::RobotInit() {
	// Set initial solenoid states
	mClimber.armsDown();
	mIntake.raiseIntakeArm();
}