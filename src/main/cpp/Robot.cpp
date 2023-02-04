#include "Robot.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/CommandScheduler.h>
void Robot::RobotInit() {
	mContainer->setInitialStates();
	Lights::setAlliance();

	mCompressor.EnableDigital();

	mShuffleboardPressure = frc::Shuffleboard::GetTab("Test").Add("Low Pressure", false).GetEntry();
}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want to run during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {
	frc2::CommandScheduler::GetInstance().Run();

	mShuffleboardPressure.SetBoolean(mCompressor.GetPressureSwitchValue());
}

/**
 * This function is called once each time the robot enters Disabled mode. You
 * can use it to reset any subsystem information you want to clear when the
 * robot is disabled.
 */
void Robot::DisabledInit() {
	Lights::setMode(Lights::kDisabled);

	mContainer->setDriverRumble(0);
	mContainer->setOperatorRumble(0);
}

void Robot::DisabledPeriodic() {
	double voltage = frc::RobotController::GetBatteryVoltage().value();

	if (voltage < 10.5) {
		for (int i = 0; i < 10; i++) {
			printf("REPLACE BATTERY | REPLACE BATTERY\n");

			throw std::runtime_error{"INTENTIONAL CRASH | REPLACE BATTERY"};
		}
	}
}

/**
 * This autonomous runs the autonomous command selected by your {@link
 * RobotContainer} class.
 */
void Robot::AutonomousInit() {
	mAutonomousCommand = mContainer->getAutonomousCommand();

	if (mAutonomousCommand != nullptr) {
		mAutonomousCommand->Schedule();
	}

	Lights::setMode(Lights::kAuto);
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

	Lights::setMode(Lights::kTeleop);
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
