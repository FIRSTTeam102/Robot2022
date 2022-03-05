#include "RobotContainer.h"


RobotContainer* RobotContainer::mRobotContainer = NULL;

RobotContainer::RobotContainer() : mAutonomousCommand() {
	mSwerveDrive.setController(&mDriverController);
	mSwerveDrive.SetDefaultCommand(std::move(mRunSwerveDrive));

	ConfigureButtonBindings();

	mChooser.SetDefaultOption("Autonomous Command", new AutonomousCommand());

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
	mDriverButtonA.WhenPressed(&mSlowShooterCommand);
	mDriverButtonB.WhenPressed(&mMedShooterCommand);
	mDriverButtonY.WhenPressed(&mFastShooterCommand);
	mDriverButtonX.WhenPressed(&mStopShooterCommand);
	mDriverButtonLB.ToggleWhenPressed(&mBallInCommand);
	mDriverButtonRB.WhenHeld(&mYawToTarget);
	mDriverButtonLMenu.WhenPressed(&mActuatorUp);
	mDriverButtonRMenu.WhenPressed(&mActuatorDown);
	mDriverLT.WhenHeld(&mAimbotParallel);
	mDriverRT.WhenHeld(&mIndexUpCommand);
	mDriverButtonLS.WhenPressed(&mFlipOrientation);	
	//RS
	mDriverUpDPad.WhenPressed(&mArmToggleCommand);
	mDriverRightDPad.ToggleWhenPressed(&mClimbCommand);
	mDriverDownDPad.WhenHeld(&mIndexDownCommand);
	mDriverLeftDPad.ToggleWhenPressed(&mBallOutCommand);
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