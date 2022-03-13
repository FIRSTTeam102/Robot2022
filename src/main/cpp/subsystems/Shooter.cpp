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
	wpi::StringMap<std::shared_ptr<nt::Value>> numberSliderProperties = {
		std::make_pair("Min", nt::Value::MakeDouble(0.50)),
		std::make_pair("Max", nt::Value::MakeDouble(2.00)),
		std::make_pair("Block increment", nt::Value::MakeDouble(0.1))
	};

	frc::ShuffleboardLayout& layout = frc::Shuffleboard::GetTab("Teleop").GetLayout("Shooter", frc::BuiltInLayouts::kList);

	mShuffleboardReady = layout.Add("Ready?", false).GetEntry();
	mShuffleboardSpeedTarget = layout.Add("Target percent", 0.0).GetEntry();
	mShuffleboardSpeedActual = layout.Add("Actual percent", 0.0).GetEntry();
	mShuffleboardBoost = layout.AddPersistent("Boost", mBoostPercent)
		.WithWidget(frc::BuiltInWidgets::kNumberSlider)
		.WithProperties(numberSliderProperties)
		.WithSize(3, 1)
		.GetEntry();
}

void Shooter::setShooter(double speed, bool useRpm = false) {
	speed = speed * mBoostPercent;

	if (!useRpm) {
		mSpeed = speed;
		mShooterMotor.Set(ControlMode::PercentOutput, mSpeed);
	} else {
		// RPM to velocity
		double velocity = (2048.0 /* encoder ticks per revolution */ * speed) / (600.0 /* 100ms per minute */);
		mShooterMotor.Set(ControlMode::Velocity, velocity);

		// RPM to percent output
		mSpeed = speed / ShooterConstants::kMaxRpm;
	}
	mIsRunning = true;
}

void Shooter::stopShooter() {
	mSpeed = 0.0;
	mShooterMotor.Set(ControlMode::PercentOutput, 0.0);
	mIsRunning = false;
}

double Shooter::getSpeed(bool useRpm = false) {
	return useRpm ? (mSpeed * ShooterConstants::kMaxRpm) : mSpeed;
}

void Shooter::Periodic() {
	mShuffleboardSpeedTarget.SetDouble(mSpeed);
	mShuffleboardSpeedActual.SetDouble(getActualPercent());
	mBoostPercent = mShuffleboardBoost.GetDouble(mBoostPercent);
}
