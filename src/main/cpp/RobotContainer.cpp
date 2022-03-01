#include "RobotContainer.h"

RobotContainer* RobotContainer::mRobotContainer = NULL;

RobotContainer::RobotContainer() {
	mSwerveDrive.setController(&mDriverController);
	mSwerveDrive.SetDefaultCommand(std::move(mRunSwerveDrive));

	ConfigureButtonBindings();

	mChooser.SetDefaultOption("Autonomous Command", new MainAutonomous(&mIndexer, &mIntake, &mLimelight, &mShooter, &mSwerveDrive));

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
	// mDriverButtonA.WhenPressed(&mResetGyro);
	mDriverButtonLS.WhenPressed(&mFlipOrientation);	

	mDriverButtonA.WhenPressed(&mSlowShooterCommand);
	mDriverButtonB.WhenPressed(&mMedShooterCommand);
	mDriverButtonY.WhenPressed(&mFastShooterCommand);
	mDriverButtonX.WhenPressed(&mStopShooterCommand);

	mDriverButtonLMenu.WhenPressed(&mActuatorUp);
	mDriverButtonRMenu.WhenPressed(&mActuatorDown);

	mDriverButtonLB.ToggleWhenPressed(&mBallInCommand);

	mDriverRT.WhenHeld(&mIndexUpCommand);

	mDriverDownDPad.WhenHeld(&mIndexDownCommand);
	mDriverLeftDPad.ToggleWhenPressed(&mBallOutCommand);
	mDriverRightDPad.ToggleWhenPressed(&mActuatorMid);
	mDriverUpDPad.WhenPressed(&mArmToggleCommand);
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