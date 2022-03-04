#include "subsystems/Shooter.h"

Shooter::Shooter() : mShooterMotor{ShooterConstants::kShooterMotor} {
	SetName("Shooter");
	SetSubsystem("Shooter");

	// Shooter motor setup
	mShooterMotor.SetInverted(true);
	mShooterMotor.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Coast);

	// Shuffleboard
	wpi::StringMap<std::shared_ptr<nt::Value>> numberSliderProperties = {
		std::make_pair("Min", nt::Value::MakeDouble(0.50)),
		std::make_pair("Max", nt::Value::MakeDouble(2.00)),
		std::make_pair("Block increment", nt::Value::MakeDouble(0.1))
	};

	frc::ShuffleboardLayout& layout = frc::Shuffleboard::GetTab("Teleop").GetLayout("Shooter", frc::BuiltInLayouts::kList);

	mShuffleboardSpeedTarget = layout.Add("Target percent", 0.0).GetEntry();
	mShuffleboardSpeedActual = layout.Add("Actual percent", 0.0).GetEntry();
	mShuffleboardBoost = layout.AddPersistent("Boost", mBoostPercent)
		.WithWidget(frc::BuiltInWidgets::kNumberSlider)
		.WithProperties(numberSliderProperties)
		.WithSize(3, 1)
		.GetEntry();
}

void Shooter::Periodic() {
	mShuffleboardSpeedTarget.SetDouble(mSpeed);
	mShuffleboardSpeedActual.SetDouble(mShooterMotor.GetMotorOutputPercent());
	mBoostPercent = mShuffleboardBoost.GetDouble(mBoostPercent);
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