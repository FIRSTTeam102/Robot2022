#include "subsystems/ShooterHood.h"

#define M_DEGTORAD 57.2958

ShooterHood::ShooterHood() : mHoodActuator{ShooterHoodConstants::kActuator} {
	SetName("ShooterHood");
	SetSubsystem("ShooterHood");

	// Actuator setup
	mHoodActuator.SetBounds(2.0, 1.8, 1.5, 1.2, 1.0);

	// Shuffleboard
	frc::ShuffleboardLayout& layout = frc::Shuffleboard::GetTab("Teleop").GetLayout("Shooter hood", frc::BuiltInLayouts::kList);

	mShuffleboardTargetAngle = layout.Add("Target angle", 0.0).GetEntry();
	mShuffleboardTargetBool = layout.Add("At target?", false).GetEntry();
}

void ShooterHood::Periodic() {
	mShuffleboardTargetAngle.SetDouble(mDegrees);
	mShuffleboardTargetBool.SetBoolean(isAtTarget());
}

// Converts an angle to required length for linear actuator to make shooter hood reach that angle
double ShooterHood::degreesToLinearLength(double degrees) {
	double outerAngle = asin(ShooterHoodConstants::kOuterY / ShooterHoodConstants::kOuterR) * M_DEGTORAD;

	frc::Vector2d innerVector{(ShooterHoodConstants::kInnerR * cos(degrees / M_DEGTORAD)), (ShooterHoodConstants::kInnerR * sin(degrees / M_DEGTORAD))};
	frc::Vector2d outerVector{(ShooterHoodConstants::kOuterR * cos(outerAngle / M_DEGTORAD)), ShooterHoodConstants::kOuterY};

	frc::Vector2d actuatorVector{outerVector.x - innerVector.x, outerVector.y - innerVector.y};

	return actuatorVector.Magnitude();
}

// Converts length of linear actuator to a setting within the bounds of kActuatorUpperBound and kActuatorLowerBound
double ShooterHood::linearLengthToSetting(double length) {
	double result = ( ( 2 / ( ShooterHoodConstants::kMaxLength - ShooterHoodConstants::kMinLength ) ) * ( length - ShooterHoodConstants::kMaxLength ) ) + 1;

	return std::clamp(result, ShooterHoodConstants::kActuatorLowerBound, ShooterHoodConstants::kActuatorUpperBound);
}

void ShooterHood::setAngle(double degrees) {
	mDegrees = std::clamp(degrees, ShooterHoodConstants::kMinAngle, ShooterHoodConstants::kMaxAngle);
	double length = degreesToLinearLength(degrees);

	mTargetSetting = linearLengthToSetting(length);

	mHoodActuator.SetSpeed(mTargetSetting);

	printf("Setting hood angle to %Fdeg, %F length, %F setting\n", mDegrees, length, mTargetSetting);
}

void ShooterHood::incrementAngle(double degreeChange) {
	// Clamping is taken care of in setAngle
	// Passing a negative number will deincrement
	setAngle(mDegrees + degreeChange);
}