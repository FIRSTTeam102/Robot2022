#include "subsystems/Shooter.h"
#include <frc/smartdashboard/SmartDashboard.h>

Shooter::Shooter() : mShooterMotor{ShooterConstants::kShooterMotor}, mHoodActuator{ShooterConstants::kHoodActuator} {
    SetName("Shooter");
    SetSubsystem("Shooter");

	// Actuator setup
	mHoodActuator.SetBounds(2.0, 1.8, 1.5, 1.2, 1.0);

	// Shooter motor setup
	mShooterMotor.SetInverted(true);
	mShooterMotor.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Coast);
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

double Shooter::degreesToLinearLength(double degrees) {
	double outerAngle = asin(ShooterConstants::kOuterY / ShooterConstants::kOuterR) * 57.2958;

	frc::Vector2d innerVector{(ShooterConstants::kInnerR * cos(degrees / 57.2958)), (ShooterConstants::kInnerR * sin(degrees / 57.2958))};
	frc::Vector2d outerVector{(ShooterConstants::kOuterR * cos(outerAngle / 57.2958)), ShooterConstants::kOuterY};

	frc::Vector2d actuatorVector{outerVector.x - innerVector.x, outerVector.y - innerVector.y};

	return actuatorVector.Magnitude();
}

void Shooter::setActuator(double setting) {
	mHoodActuator.SetSpeed(setting);
}
