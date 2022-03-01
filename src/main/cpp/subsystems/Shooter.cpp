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
	mBoostPercent = layout.AddPersistent("Boost", mBoostPercent)
		.WithWidget(frc::BuiltInWidgets::kNumberSlider)
		.WithProperties(kNumberSliderProperties)
		.WithSize(3, 1)
		.GetEntry()
		.GetDouble();
}

void Shooter::setShooter(double speed) {
	mSpeed = speed;
	mShooterMotor.Set(ControlMode::PercentOutput, mBoostPercent * mSpeed);
	mIsRunning = true;
}

void Shooter::stopShooter() {
	mSpeed = 0.0;
	mShooterMotor.Set(ControlMode::PercentOutput, 0.0);
	mIsRunning = false;
}