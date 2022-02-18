#include "subsystems/Intake.h"

Intake::Intake() : mRollerMotor{IntakeConstants::kRollerMotor}, mArmSolenoid{frc::PneumaticsModuleType::REVPH, IntakeConstants::kArmSolenoidForward, IntakeConstants::kArmSolenoidBackward} {
	SetName("Intake");
	SetSubsystem("Intake");
}

void Intake::lowerIntakeArm() {
	printf("Deploying intake\n");
	mArmSolenoid.Set(frc::DoubleSolenoid::kForward);
}

void Intake::raiseIntakeArm() {
	printf("Retracting intake\n");
	mArmSolenoid.Set(frc::DoubleSolenoid::kReverse);
}

void Intake::toggleIntakeArm() {
	printf("Toggling intake\n");
	mArmSolenoid.Toggle();
}

frc::DoubleSolenoid::Value Intake::getArmState() {
	return mArmSolenoid.Get();
}

void Intake::startRollers() {
	printf("Rollers should be moving\n");
	mRollerMotor.Set(ControlMode::PercentOutput, IntakeConstants::kRollerSpeed);
}

void Intake::startReverseRollers() {
	mRollerMotor.Set(ControlMode::PercentOutput, -IntakeConstants::kRollerSpeed);
}

void Intake::stopRollers() {
	mRollerMotor.Set(ControlMode::PercentOutput, 0);
}

void Intake::Periodic() {
	// Put code here to be run every loop
}