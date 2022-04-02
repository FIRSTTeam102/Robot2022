#include "subsystems/ShooterHood.h"

#include "commands/ShooterHood/SetHoodAngle.h"

#define M_DEGTORAD 57.2958

ShooterHood::ShooterHood() : mHoodActuator{ShooterHoodConstants::kActuator} {
	SetName("ShooterHood");
	SetSubsystem("ShooterHood");

	// Actuator setup
	mHoodActuator.SetBounds(2.0, 1.8, 1.5, 1.2, 1.0);

	// Shuffleboard
	frc::ShuffleboardLayout& layout = frc::Shuffleboard::GetTab("Drive").GetLayout("Shooter hood", frc::BuiltInLayouts::kList);

	mShuffleboardTargetAngle = layout.Add("Target angle", 0.0).WithWidget(frc::BuiltInWidgets::kNumberSlider).GetEntry();
	mShuffleboardTargetBool = layout.Add("At target?", false).GetEntry();

	frc::ShuffleboardLayout& testLayout = frc::Shuffleboard::GetTab("Test").GetLayout("Shooter hood", frc::BuiltInLayouts::kList);
	mShuffleboardTestAngle = testLayout.Add("Test angle", 0.0).GetEntry();
	frc::SmartDashboard::PutData("Set test angle", new SetHoodAngle(this, &mShuffleboardTestAngle)); // shuffleboard doesn't seem to like commands
	// testLayout.Add("Set test angle", new SetHoodAngle(this, &mShuffleboardTestAngle)).WithWidget(frc::BuiltInWidgets::kCommand);
}

void ShooterHood::Periodic() {
	mShuffleboardTargetBool.SetBoolean(isAtTarget());

	// setAngle(mShuffleboardTargetAngle.GetDouble(mDegrees));
}

// Converts an angle to required length for linear actuator to make shooter hood reach that angle
double ShooterHood::degreesToLinearLength(double degrees) {
	degrees = 90 - degrees - ShooterHoodConstants::kAngleOffset;
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

	if (degrees == mDegrees) return;

	printf("Setting hood angle to %Fdeg, %F length, %F setting\n", mDegrees, length, mTargetSetting);
	mShuffleboardTargetAngle.SetDouble(mDegrees);
}

void ShooterHood::incrementAngle(double degreeChange) {
	// Clamping is taken care of in setAngle
	// Passing a negative number will decrement
	setAngle(mDegrees + degreeChange);
}