#include "RobotContainer.h"

RobotContainer* RobotContainer::mpRobotContainer = NULL;

RobotContainer::RobotContainer() {
	// Default subsystem commands
	mSwerveDrive.SetDefaultCommand(std::move(mRunSwerveDrive));

	// Button bindings
	configureButtonBindings();
	frc::DriverStation::SilenceJoystickConnectionWarning(true);

	// Data logging
	frc::DataLogManager::Start();
	frc::DriverStation::StartDataLog(frc::DataLogManager::GetLog(), false);

	// Auto
	mAutoMode.SetDefaultOption("2 ball", new MainAutonomous(&mIndexer, &mIntake, &mLimelight, &mShooter, &mShooterHood, &mSwerveDrive));
	mAutoMode.AddOption("1 ball", new OneBallAuto(&mIndexer, &mShooter, &mShooterHood, &mLimelight, &mSwerveDrive));
	mAutoMode.AddOption("None", new frc2::PrintCommand("No auto"));
	frc::Shuffleboard::GetTab("Drive")
		.Add("Auto mode", mAutoMode)
		.WithWidget(frc::BuiltInWidgets::kComboBoxChooser);

	// Camera
	mCamera1 = frc::CameraServer::StartAutomaticCapture("Intake", 0);
	mCamera1.SetFPS(15);
	mCamera1.SetResolution(320, 240);
	/* mCamera2 = frc::CameraServer::StartAutomaticCapture("Climb", 1);
	mCamera2.SetFPS(15);
	mCamera2.SetResolution(320, 240); */
	mCameraServer = frc::CameraServer::AddSwitchedCamera("Camera");
	mCameraServer.SetFPS(15);
	mCameraServer.SetResolution(320, 240);
	mCameraServer.SetSource(mCamera1);
	frc::Shuffleboard::GetTab("Drive")
		.AddCamera("Camera", "Camera", std::vector<std::string>{mCameraServer.GetListenAddress()})
		// .Add("Camera", mCamera1)
		.WithWidget(frc::BuiltInWidgets::kCameraStream)
		.WithSize(5, 4);

	frc::ShuffleboardTab& demoTab = frc::Shuffleboard::GetTab("Demo");
	mDemoShooterSpeed = demoTab.Add("Demo Shooter Speed", 2000.0).GetEntry();
}

void RobotContainer::configureButtonBindings() {
	mUserButton.WhenPressed([&] {
		printf("user button pressed\n");
		mLimelight.toggleLight();
	}, {});

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

	mOperatorRT.WhenHeld(&mLimelightShooterContinous);

	// mOperatorUpDPad.WhenPressed(&mIncrementHood);
	// mOperatorDownDPad.WhenPressed(&mDecrementHood);
	// mOperatorRightDPad.WhenPressed(&mToggleCamera);

	mOperatorButtonLMenu.ToggleWhenPressed(&mMidClimbCommand);
	mOperatorButtonRMenu.ToggleWhenPressed(&mHighClimbCommand);

	/****** Demo ******/
	mDemoButtonA.WhenPressed(&mDemoSpeed);
	mDemoButtonB.WhenPressed(&mDemoUpperAngle);
	mDemoButtonY.WhenPressed(&mDemoLowerAngle);
	mDemoButtonX.WhenPressed(&mStopShooterCommand);

	mDemoLT.WhenHeld(&mBallInCommand);
	mDemoRT.WhenHeld(&mIndexUpCommand);
	mDemoButtonRB.WhenHeld(&mIndexDownCommand);
	// mDemoButtonLB.ToggleWhenPressed(&mMidClimbCommand);
	// mDemoButtonRB.ToggleWhenPressed(&mHighClimbCommand);

	mDemoButtonLMenu.WhenPressed(&mToggleDriveMode);
	mDemoButtonRMenu.WhenPressed(&mResetGyro);
}

frc2::Command* RobotContainer::getAutonomousCommand() {
	// The selected command will be run in autonomous
	return mAutoMode.GetSelected();
}

void RobotContainer::setInitialStates() {
	// Called when the robot starts, makes sure everything is set as retracted/stopped
	mShooter.stopShooter();
	mClimber.midArmsDown();
	mClimber.highArmsDown();
	mIntake.raiseIntakeArm();
	mLimelight.setLight(true);
}