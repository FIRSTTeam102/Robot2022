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
	mDriverButtonLB.WhenHeld(&mIntakeControlCommand);
	mDriverUpDPad.WhenHeld(&mIndexUpCommand);
	mDriverDownDPad.WhenHeld(&mIndexDownCommand);
	mDriverButtonA.WhenPressed(&mSlowShooterCommand);
	mDriverButtonB.WhenPressed(&mMedShooterCommand);
	mDriverButtonY.WhenPressed(&mFastShooterCommand);
	mDriverButtonX.WhenPressed(&mStopShooterCommand);
	mDriverLT.WhenHeld(&mAimbotParallel);
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
	// The selected command will be run in autonomous
	return mChooser.GetSelected();
}
