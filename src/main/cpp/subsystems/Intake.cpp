#include "subsystems/Intake.h"

#include <frc/smartdashboard/SmartDashboard.h>

#include "Constants.h"
#include "RobotContainer.h"

Intake::Intake() : mRollerMotor{IntakeConstants::kRollerMotor}, mArmSolenoid{frc::PneumaticsModuleType::REVPH, IntakeConstants::kArmSolenoid} {
	SetName("Intake");
	SetSubsystem("Intake");
}

// lower the intake arm - start the arm motor
void Intake::lowerIntakeArm() {
	printf("Deploying intake\n");
	mArmSolenoid.Set(true);
	// printf("Is arm down - %d\n", isArmDown());
}
// raise the intake arm -  start the arm motor
void Intake::raiseIntakeArm() {
	printf("Retracting intake\n");
	mArmSolenoid.Set(false);
}
// stopIntakeArm - stop the intake arm motor by shutting it off
// void Intake::stopIntakeArm() {
// Not doable with pneumatics
// }
// startRollers - start the intake arms rollers, to capture power cells
void Intake::startRollers() {
	printf("Rollers should be moving\n");
	mRollerMotor.Set(ControlMode::PercentOutput, -IntakeConstants::kRollerSpeed);
}
// startReversRollers - start the intake arm rollers in reverse - this is to
//   spit out power cells in the event the power cell intake needs to be
//   cleared
void Intake::startReverseRollers() {
	mRollerMotor.Set(ControlMode::PercentOutput, IntakeConstants::kRollerSpeed);
}
// stopRollers - stop the intake arm roller motors from running
void Intake::stopRollers() {
	mRollerMotor.Set(ControlMode::PercentOutput, 0);
}

void Intake::Periodic() {
	// Put code here to be run every loop
}