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

void Intake::setIntakeArm(frc::DoubleSolenoid::Value state) {
	mArmSolenoid.Set(state);
}

frc::DoubleSolenoid::Value Intake::getArmState() {
	return mArmSolenoid.Get();
}

void Intake::startRollers() {
	// printf("Rollers should be moving\n");
	mRollerMotor.Set(ControlMode::PercentOutput, IntakeConstants::kRollerSpeed);
	mState = MotorDirection::kForward;
}

void Intake::startReverseRollers() {
	mRollerMotor.Set(ControlMode::PercentOutput, -IntakeConstants::kRollerSpeed);
	mState = MotorDirection::kReverse;
}

void Intake::stopRollers() {
	mRollerMotor.Set(ControlMode::PercentOutput, 0);
	mState = MotorDirection::kOff;
}

void Intake::toggleRollerDirection() {
	if (mState == MotorDirection::kForward)
		startReverseRollers();
	else if (mState == MotorDirection::kReverse)
		startRollers();
}

void Intake::Periodic() {
	// Put code here to be run every loop
}