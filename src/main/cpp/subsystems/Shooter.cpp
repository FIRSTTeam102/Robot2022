#include "subsystems/Shooter.h"

Shooter::Shooter() : mShooterMotor{ShooterConstants::kShooterMotor} {
	SetName("Shooter");
	SetSubsystem("Shooter");

	// Shooter motor setup
	mShooterMotor.SetInverted(true);
	mShooterMotor.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Coast);
}

void Shooter::Periodic() {
	frc::ShuffleboardLayout& layout = frc::Shuffleboard::GetTab("Teleop").GetLayout("Shooter", frc::BuiltInLayouts::kList);

	layout.Add("Target percent", mSpeed);
	layout.Add("Actual percent", mShooterMotor.GetMotorOutputPercent());
}

void Shooter::setShooter(double speed) {
	mSpeed = speed;
	mShooterMotor.Set(ControlMode::PercentOutput, mSpeed);
	mIsRunning = true;
}

void Shooter::stopShooter() {
	mSpeed = 0.0;
	mShooterMotor.Set(ControlMode::PercentOutput, 0.0);
	mIsRunning = false;
}