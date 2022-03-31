#include "RobotContainer.h"

RobotContainer* RobotContainer::mpRobotContainer = NULL;

RobotContainer::RobotContainer() {
	mSwerveDrive.SetDefaultCommand(std::move(mRunSwerveDrive));

	configureButtonBindings();
	frc::DriverStation::SilenceJoystickConnectionWarning(true);

	// Auto
	mAutoMode.SetDefaultOption("2 ball", new MainAutonomous(&mIndexer, &mIntake, &mLimelight, &mShooter, &mShooterHood, &mSwerveDrive));
	mAutoMode.AddOption("1 ball", new OneBallAuto(&mIndexer, &mShooter, &mShooterHood, &mLimelight, &mSwerveDrive));
	mAutoMode.AddOption("None", new frc2::PrintCommand("No auto"));
	frc::Shuffleboard::GetTab("Drive")
		.Add("Auto mode", mAutoMode)
		.WithWidget(frc::BuiltInWidgets::kComboBoxChooser);

	// Camera 🥴
	mCamera1 = frc::CameraServer::StartAutomaticCapture("Intake", 0);
	mCamera1.SetFPS(30);
	mCamera1.SetResolution(320, 240);
	mCamera2 = frc::CameraServer::StartAutomaticCapture("Climb", 1);
	mCamera2.SetFPS(30);
	mCamera2.SetResolution(320, 240);
	mCameraServer = frc::CameraServer::AddSwitchedCamera("Camera");
	mCameraServer.SetFPS(30);
	mCameraServer.SetResolution(320, 240);
	mCameraServer.SetSource(mCamera1);
	frc::Shuffleboard::GetTab("Drive")
		.AddCamera("Camera", "Camera", std::vector<std::string>{mCameraServer.GetListenAddress()})
		.WithWidget(frc::BuiltInWidgets::kCameraStream)
		.WithSize(5, 4);
}

void RobotContainer::configureButtonBindings() {
	/****** Driver ******/
	mDriverButtonA.WhenPressed(&mToggleDriveMode);
	mDriverButtonB.WhenPressed(&mResetGyro);

	mDriverLT.WhenHeld(&mYawToTarget);

	mDriverRT.WhenHeld(&mIndexUpCommand);
	mDriverButtonRB.WhenHeld(&mIndexDownCommand);

	mDriverButtonRMenu.WhenPressed(&mShuffleboardShooter);

	/****** Operator ******/
	mOperatorButtonA.WhenPressed(&mTarmacLower);
	mOperatorButtonB.WhenPressed(&mTarmacUpper);
	// mOperatorButtonY.WhenPressed(&mFastShooterCommand);
	mOperatorButtonX.WhenPressed(&mStopShooterCommand);

	mOperatorLT.WhenHeld(&mBallInCommand);
	mOperatorButtonLB.WhenHeld(&mBallOutCommand);

	mOperatorRT.WhenHeld(&mLimelightShooterContinous);

	// mOperatorUpDPad.WhenPressed(&mIncrementHood);
	// mOperatorDownDPad.WhenPressed(&mDecrementHood);
	mOperatorRightDPad.WhenPressed(&mToggleCamera);

	mOperatorButtonLMenu.ToggleWhenPressed(&mMidClimbCommand);
	mOperatorButtonRMenu.ToggleWhenPressed(&mHighClimbCommand);
}

frc2::Command* RobotContainer::getAutonomousCommand() {
	// The selected command will be run in autonomous
	return mAutoMode.GetSelected();
}

void RobotContainer::setInitialStates() {
	mShooter.stopShooter();
	mClimber.midArmsDown();
	mClimber.highArmsDown();
	mIntake.raiseIntakeArm();
}