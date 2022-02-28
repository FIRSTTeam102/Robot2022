#include "subsystems/ShooterHood.h"

ShooterHood::ShooterHood() : mHoodActuator{ShooterConstants::kHoodActuator} {
	SetName("ShooterHood");
	SetSubsystem("ShooterHood");

	// Actuator setup
	mHoodActuator.SetBounds(2.0, 1.8, 1.5, 1.2, 1.0);

	// Shuffleboard
	mLayout = frc::Shuffleboard::GetTab("Teleop")
		->GetLayout("Shooter hood", frc::BuiltinLayouts::kList);
}

void ShooterHood::Periodic() {
	mLayout.Add("Target angle", mDegrees);
	mLayout.Add("At target?", isAtTarget());
}

// Converts an angle to required length for linear actuator to make shooter hood reach that angle
double ShooterHood::degreesToLinearLength(double degrees) {
	double outerAngle = asin(ShooterConstants::kOuterY / ShooterConstants::kOuterR) * 57.2958;

	frc::Vector2d innerVector{(ShooterConstants::kInnerR * cos(degrees / 57.2958)), (ShooterConstants::kInnerR * sin(degrees / 57.2958))};
	frc::Vector2d outerVector{(ShooterConstants::kOuterR * cos(outerAngle / 57.2958)), ShooterConstants::kOuterY};

	frc::Vector2d actuatorVector{outerVector.x - innerVector.x, outerVector.y - innerVector.y};

	return actuatorVector.Magnitude();
}

// Converts length of linear actuator to a setting within the bounds of kActuatorUpperBound and kActuatorLowerBound
double ShooterHood::linearLengthToSetting(double length) {
	double result = ( ( 2 / ( ShooterConstants::kMaxLength - ShooterConstants::kMinLength ) ) * ( length - ShooterConstants::kMaxLength ) ) + 1;

	if ( result > ShooterConstants::kActuatorUpperBound ) return ShooterConstants::kActuatorUpperBound;
	else if ( result < ShooterConstants::kActuatorLowerBound ) return ShooterConstants::kActuatorLowerBound;
	else return result;
}

void ShooterHood::setAngle(double degrees) {
	mDegrees = degrees;
	double length = mpShooterHood->degreesToLinearLength(degrees);

	mTargetSetting = mpShooterHood->linearLengthToSetting(length);

	mHoodActuator.SetSpeed(mTargetSetting);

	printf("Setting hood angle to %Fdeg, %F length, %F setting\n", mDegrees, length, mTargetSetting);
}
