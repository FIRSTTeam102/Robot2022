#include "subsystems/Shooter.h"
#include <frc/smartdashboard/SmartDashboard.h>


Shooter::Shooter() : mShooterMotor{ShooterConstants::kShooterMotor}, mHoodActuator{ShooterConstants::kHoodActuator} {
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

	// Actuator setup
	mHoodActuator.SetBounds(2.0, 1.8, 1.5, 1.2, 1.0);
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

// Converts an angle to required length for linear actuator to make shooter hood reach that angle
double Shooter::degreesToLinearLength(double degrees) {
	printf("Input Degrees: %f\n", degrees);
	degrees = 90 - degrees - ShooterConstants::kHoodAngleOffset;
	printf("Target Degrees: %f\n", degrees);
	double outerAngle = asin(ShooterConstants::kOuterY / ShooterConstants::kOuterR) * 57.2958;

	frc::Vector2d innerVector{(ShooterConstants::kInnerR * cos(degrees / 57.2958)), (ShooterConstants::kInnerR * sin(degrees / 57.2958))};
	frc::Vector2d outerVector{(ShooterConstants::kOuterR * cos(outerAngle / 57.2958)), ShooterConstants::kOuterY};

	frc::Vector2d actuatorVector{outerVector.x - innerVector.x, outerVector.y - innerVector.y};

	return actuatorVector.Magnitude();
}

// Converts length of linear actuator to a setting within the bounds of kActuatorUpperBound and kActuatorLowerBound
double Shooter::linearLengthToSetting(double length) {
	double result = ( ( 2 / ( ShooterConstants::kMaxLength - ShooterConstants::kMinLength ) ) * ( length - ShooterConstants::kMaxLength ) ) + 1;

	if ( result > ShooterConstants::kActuatorUpperBound ) return ShooterConstants::kActuatorUpperBound;
	else if ( result < ShooterConstants::kActuatorLowerBound ) return ShooterConstants::kActuatorLowerBound;
	else return result;
}

void Shooter::setActuator(double setting) {
	mHoodActuator.SetSpeed(setting);
}
