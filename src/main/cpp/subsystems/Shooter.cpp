#include "subsystems/Shooter.h"
#include <frc/smartdashboard/SmartDashboard.h>

Shooter::Shooter() : mShooterMotor{ShooterConstants::kShooterMotor}, mHoodServo{ShooterConstants::kHoodServo} {
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
}

void Shooter::Periodic() {
	// Put code here to be run every loop
}

// useRpm is questionable and needs testing
void Shooter::setShooter(double speed, bool useRpm = false) {
	if (!useRpm) {
		mSpeed = speed;
		mShooterMotor.Set(ControlMode::PercentOutput, mSpeed);
	} else {
		// RPM to velocity
		double velocity = (2048.0 /* encoder ticks per revolution */ * speed) / (600.0 /* 100ms per minute */);
		mShooterMotor.Set(ControlMode::Velocity, velocity);

		// RPM to percent output
		mSpeed = speed / ShooterConstants::kMaxRpm;
		printf("%f\n", speed);
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

bool Shooter::isRunning() {
	return mIsRunning;
}

void Shooter::setServo(double value) {
	mHoodServo.Set(value);
}

void Shooter::setServoAngle(double degrees) {
	mHoodServo.SetAngle(degrees);
}