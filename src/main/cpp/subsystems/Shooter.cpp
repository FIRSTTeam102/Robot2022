#include "subsystems/Shooter.h"
#include <frc/smartdashboard/SmartDashboard.h>

Shooter::Shooter() : mShooterMotor{ShooterConstants::kShooterMotor}, mHoodServo{ShooterConstants::kHoodServo} {
    SetName("Shooter");
    SetSubsystem("Shooter");
}

void Shooter::Periodic() {
    // Put code here to be run every loop
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

double Shooter::getSpeed() {
	return mSpeed;
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