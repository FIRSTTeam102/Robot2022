#include "RobotContainer.h"

RobotContainer* RobotContainer::mRobotContainer = NULL;

RobotContainer::RobotContainer() {
	mSwerveDrive.SetDefaultCommand(std::move(mRunSwerveDrive));

	ConfigureButtonBindings();

	mAutoMode.SetDefaultOption("2 ball", new MainAutonomous(&mIndexer, &mIntake, &mLimelight, &mShooter, &mShooterHood, &mSwerveDrive));
	mAutoMode.AddOption("1 ball", new OneBallAuto(&mIndexer, &mShooter, &mShooterHood, &mLimelight, &mSwerveDrive));
	mAutoMode.AddOption("None", new frc2::PrintCommand("No auto"));
	frc::Shuffleboard::GetTab("Drive")
		.Add("Auto mode", mAutoMode)
		.WithWidget(frc::BuiltInWidgets::kComboBoxChooser)
		.WithPosition(0, 0);

	// mCamera = frc::CameraServer::GetInstance()->StartAutomaticCapture(0);
	mCamera = frc::CameraServer::StartAutomaticCapture();
	mCamera.SetFPS(30);
	mCamera.SetResolution(640, 480);
	frc::CameraServer::GetServer().SetSource(mCamera);
	frc::Shuffleboard::GetTab("Drive")
		.Add("Camera", mCamera)
		.WithWidget(frc::BuiltInWidgets::kCameraStream)
		.WithSize(7, 5)
		.WithPosition(3, 0);

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
	mDriverButtonA.WhenPressed(&mToggleDriveMode);
	mDriverButtonB.WhenPressed(&mResetGyro);

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

	mOperatorRT.WhenHeld(&mLimelightShooter);

	mOperatorUpDPad.WhenPressed(&mIncrementHood);
	mOperatorDownDPad.WhenPressed(&mDecrementHood);

	mOperatorButtonLMenu.ToggleWhenPressed(&mMidClimbCommand);
	mOperatorButtonRMenu.ToggleWhenPressed(&mHighClimbCommand);
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
	// The selected command will be run in autonomous
	return mAutoMode.GetSelected();
}

void RobotContainer::RobotInit() {
	// Set initial solenoid states
	mClimber.midArmsDown();
	mClimber.highArmsDown();
	mIntake.raiseIntakeArm();
}