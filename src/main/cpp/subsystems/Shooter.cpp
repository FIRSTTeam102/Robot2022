#include "subsystems/Shooter.h"

Shooter::Shooter() : mShooterMotor{ShooterConstants::kShooterMotor} {
	SetName("Shooter");
	SetSubsystem("Shooter");

	// Shooter motor setup
	mShooterMotor.ConfigFactoryDefault(); // resets all settings
	mShooterMotor.SetInverted(true);
	mShooterMotor.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Coast);

	// Sensor
	mShooterMotor.ConfigSelectedFeedbackSensor(TalonFXFeedbackDevice::IntegratedSensor);
	mShooterMotor.SetSensorPhase(true);

	// Peak and nominal outputs
	mShooterMotor.ConfigNominalOutputForward(0, ShooterConstants::kTimeoutMs);
	mShooterMotor.ConfigNominalOutputReverse(0, ShooterConstants::kTimeoutMs);
	mShooterMotor.ConfigPeakOutputForward(1, ShooterConstants::kTimeoutMs);
	mShooterMotor.ConfigPeakOutputReverse(-1, ShooterConstants::kTimeoutMs);

	// Closed loop gains
	mShooterMotor.Config_kD(0, ShooterConstants::kD, ShooterConstants::kTimeoutMs);
	mShooterMotor.Config_kF(0, ShooterConstants::kF, ShooterConstants::kTimeoutMs);
	mShooterMotor.Config_kI(0, ShooterConstants::kI, ShooterConstants::kTimeoutMs);
	mShooterMotor.Config_kP(0, ShooterConstants::kP, ShooterConstants::kTimeoutMs);

	// Shuffleboard
	wpi::StringMap<std::shared_ptr<nt::Value>> boostSliderProperties = {
		std::make_pair("Min", nt::Value::MakeDouble(0.10)),
		std::make_pair("Max", nt::Value::MakeDouble(1.50)),
		std::make_pair("Block increment", nt::Value::MakeDouble(0.1))
	};

	frc::ShuffleboardLayout& layout = frc::Shuffleboard::GetTab("Drive").GetLayout("Shooter", frc::BuiltInLayouts::kList)
		.WithSize(1, 3)
		.WithPosition(10, 0);

	mShuffleboardReady = layout.Add("Ready?", false).GetEntry();
	mShuffleboardTargetRPM = layout.Add("Target RPM", 0.0).GetEntry();
	mShuffleboardActualRPM = layout.Add("Actual RPM", 0.0).GetEntry();
	mShuffleboardActualPercent = layout.Add("Actual %", 0.0).GetEntry();
	mShuffleboardBoost = layout.AddPersistent("Boost", mBoostPercent)
		.WithWidget(frc::BuiltInWidgets::kNumberSlider)
		.WithProperties(boostSliderProperties)
		.GetEntry();
}

void Shooter::setShooter(double speed, bool useBoost) {
	if (useBoost) speed = speed * mBoostPercent;

	mShooterMotor.Set(ControlMode::Velocity, rpmToVelocity(speed));

	mSpeed = speed;
}

void Shooter::stopShooter() {
	mSpeed = 0.0;
	mShooterMotor.Set(ControlMode::PercentOutput, 0.0);
}

void Shooter::setShooterPercent(double speed) {
	mShooterMotor.Set(ControlMode::PercentOutput, speed);
	mSpeed = speed / ShooterConstants::kMaxRpm;
}

void Shooter::Periodic() {
	mShuffleboardTargetRPM.SetDouble(mSpeed);
	mShuffleboardActualRPM.SetDouble(getActualSpeed());
	mShuffleboardActualPercent.SetDouble(getActualPercent());
	mBoostPercent = mShuffleboardBoost.GetDouble(mBoostPercent);
}
