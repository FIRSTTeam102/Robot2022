#include "Robot.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/CommandScheduler.h>

void Robot::RobotInit() {
	mContainer->RobotInit();
}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want to run during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() { frc2::CommandScheduler::GetInstance().Run(); }

/**
 * This function is called once each time the robot enters Disabled mode. You
 * can use it to reset any subsystem information you want to clear when the
 * robot is disabled.
 */
void Robot::DisabledInit() {
	Lights::GetInstance()->setMode(Lights::Mode::kDisabled);

	mContainer->GetDriverController()->SetRumble(frc::GenericHID::kLeftRumble, 0);
	mContainer->GetDriverController()->SetRumble(frc::GenericHID::kRightRumble, 0);
	mContainer->GetOperatorController()->SetRumble(frc::GenericHID::kLeftRumble, 0);
	mContainer->GetOperatorController()->SetRumble(frc::GenericHID::kRightRumble, 0);
}

void Robot::DisabledPeriodic() {}

/**
 * This autonomous runs the autonomous command selected by your {@link
 * RobotContainer} class.
 */
void Robot::AutonomousInit() {
	mAutonomousCommand = mContainer->GetAutonomousCommand();

	if (mAutonomousCommand != nullptr) {
		mAutonomousCommand->Schedule();
	}

	Lights::GetInstance()->setMode(Lights::Mode::kAuto);
}

void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// this line or comment it out.
	if (mAutonomousCommand != nullptr) {
		mAutonomousCommand->Cancel();
		mAutonomousCommand = nullptr;
	}

	Lights::GetInstance()->setMode(Lights::Mode::kTeleop);
}

/**
 * This function is called periodically during operator control.
 */
void Robot::TeleopPeriodic() {}

/**
 * This function is called periodically during test mode.
 */
void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
