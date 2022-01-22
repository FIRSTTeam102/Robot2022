#include "subsystems/Shooter.h"
#include <frc/smartdashboard/SmartDashboard.h>

Shooter::Shooter() : mShooterMotor{ShooterConstants::kShooterMotor}, mHoodActuator{ShooterConstants::kHoodActuator} {
    SetName("Shooter");
    SetSubsystem("Shooter");

	// Actuator setup
	mHoodActuator.SetBounds(2.0, 1.8, 1.5, 1.2, 1.0);
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

void Shooter::setHoodAngle(double degrees) {
	double servoSetting;

	if (degrees < ShooterConstants::kHoodMinAngle) {
		servoSetting = -1.0;
	} else if ( degrees > ShooterConstants::kHoodMaxAngle ) {
		servoSetting = 1.0;
	} else {
		servoSetting = degreesToServo(degrees);
	}

	mHoodActuator.SetSpeed(servoSetting);
}

