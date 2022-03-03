#include "RobotContainer.h"

RobotContainer* RobotContainer::mRobotContainer = NULL;

RobotContainer::RobotContainer() : mAutonomousCommand() {
	mSwerveDrive.SetDefaultCommand(std::move(mRunSwerveDrive));

	ConfigureButtonBindings();

	mChooser.SetDefaultOption("Default", new AutonomousCommand());
	frc::Shuffleboard::GetTab("Autonomous").Add("Mode", &mChooser);

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
	mDriverButtonA.WhenPressed(&mFlipOrientation);
	// mDriverButtonRMenu.WhenPressed(&mResetGyro);

	// mDriverLT.WhenHeld(); // LM aim

	mDriverRT.WhenHeld(&mIndexUpCommand);
	mDriverButtonRB.WhenHeld(&mIndexDownCommand);
	
	/****** Operator ******/
	mOperatorButtonA.WhenPressed(&mSlowShooterCommand);
	mOperatorButtonB.WhenPressed(&mMedShooterCommand);
	mOperatorButtonY.WhenPressed(&mFastShooterCommand);
	mOperatorButtonX.WhenPressed(&mStopShooterCommand);

	mOperatorLT.WhenHeld(&mBallInCommand);
	mOperatorButtonLB.WhenHeld(&mBallOutCommand);

	// mOperatorRT.WhenPressed(); // LM speed

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