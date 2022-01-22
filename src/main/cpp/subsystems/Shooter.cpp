#include "subsystems/Shooter.h"
#include <frc/smartdashboard/SmartDashboard.h>

Shooter::Shooter() : mShooterMotor{ShooterConstants::kShooterMotor}, mHoodServo{ShooterConstants::kHoodServo} {
	SetName("Shooter");
	SetSubsystem("Shooter");
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