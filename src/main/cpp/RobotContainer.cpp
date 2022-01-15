#include "RobotContainer.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/ParallelRaceGroup.h>

RobotContainer* RobotContainer::mRobotContainer = NULL;

RobotContainer::RobotContainer() : mAutonomousCommand() {
	// SmartDashboard Buttons
	frc::SmartDashboard::PutData("RunSwerveDrive", new RunSwerveDrive());
	frc::SmartDashboard::PutData("FlipDrive", new FlipDrive());
	frc::SmartDashboard::PutData("DownYesRoll", new DownYesRoll());
	frc::SmartDashboard::PutData("UpNoRoll", new UpNoRoll());
	frc::SmartDashboard::PutData("Forward", new Forward());
	frc::SmartDashboard::PutData("Backward", new Backward());
	frc::SmartDashboard::PutData("Shoot Sequential", new ShootSequential());
	frc::SmartDashboard::PutData("StartFlywheel", new StartFlywheel());
	frc::SmartDashboard::PutData("StopIndexer", new StopIndexer());
	frc::SmartDashboard::PutData("ExtendRetract", new ExtendRetract());
	frc::SmartDashboard::PutData("StopFlywheel", new StopFlywheel());
	frc::SmartDashboard::PutData("Climb", new Climb());
	frc::SmartDashboard::PutData("Aimbot Sequential", new AimbotSequential());
	frc::SmartDashboard::PutData("SetShootSpeed", new SetShootSpeed());
	frc::SmartDashboard::PutData("YawToTarget", new YawToTarget());

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
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
	// The selected command will be run in autonomous
	return mChooser.GetSelected();
}
