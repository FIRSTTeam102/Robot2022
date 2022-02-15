#include "subsystems/Intake.h"

Intake::Intake() : mRollerMotor{IntakeConstants::kRollerMotor}, mArmSolenoid{frc::PneumaticsModuleType::REVPH, IntakeConstants::kArmSolenoidDown, IntakeConstants::kArmSolenoidUp} {
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
	// printf("Rollers should be moving\n");
	mRollerMotor.Set(ControlMode::PercentOutput, IntakeConstants::kRollerSpeed);
	mState = RollerState::Forward;
}

void Intake::startReverseRollers() {
	mRollerMotor.Set(ControlMode::PercentOutput, -IntakeConstants::kRollerSpeed);
	mState = RollerState::Reverse;
}

void Intake::stopRollers() {
	mRollerMotor.Set(ControlMode::PercentOutput, 0);
	mState = RollerState::Off;
}

void Intake::toggleRollerDirection() {
	if ( mState == RollerState::Forward ) startReverseRollers();
	else if ( mState == RollerState::Reverse ) startRollers();
}

Intake::RollerState Intake::getRollerState() {
	return mState;
}

void Intake::Periodic() {
	// Put code here to be run every loop
}