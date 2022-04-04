#include "subsystems/Limelight.h"

Limelight::Limelight() : m_LimelightHasTarget(false) {
	SetName("Limelight");
	SetSubsystem("Limelight");
	table->PutNumber("ledMode", 0);
	table->PutNumber("pipeline", 0);

	// Shuffleboard
	frc::ShuffleboardLayout& layout = frc::Shuffleboard::GetTab("Drive").GetLayout("Limelight", frc::BuiltInLayouts::kList);

	mShuffleboardDistance = layout.Add("Distance (in)", 0.0).GetEntry();
	mShuffleboardPossibleShot = layout.Add("Possible shot", false).GetEntry();
	mShuffleboardSuggestedHoodAngle = layout.Add("Calculated hood angle", 0.0).GetEntry();
	mShuffleboardSuggestedSpeed = layout.Add("Calculated speed (RPM)", 0.0).GetEntry();
	mShuffleboardTx = layout.Add("Horizontal degrees (tx)", 0.0).GetEntry();
	mShuffleboardTv = layout.Add("Sees target (tv)", false).GetEntry();
}

double Limelight::calculateShootAngle() {
	ad = LimelightConstants::ay + ty;
	return ad;
}

double Limelight::convertShootAngletoRadians() {
	ar = ad * 3.131592 / 180;
	return ar;
}

double Limelight::calculateShootDistance() {
	d = (LimelightConstants::h / tan(ar)) + LimelightConstants::kDistanceError;
	return d;
}

bool Limelight::Check() {
	// return ( ( -1.0 < tx ) && ( tx < 1.0 ) );
	if (frc::DriverStation::IsAutonomous()) return ((-2.0 < tx) && (tx < 0.0));
	else return ((-3.8 < tx) && (tx < -2.8)) || ((2.8 < tx) && (tx < 3.8));
}

void Limelight::Periodic() {
	tx = table->GetNumber("tx", 0.0);
	ty = table->GetNumber("ty", 0.0);
	ta = table->GetNumber("ta", 0.0);
	tv = table->GetNumber("tv", 0.0);

	calculateShootAngle();
	convertShootAngletoRadians();
	calculateShootDistance();

	mShuffleboardDistance.SetDouble(d);
	mShuffleboardPossibleShot.SetBoolean(tv > 0 && d <= LimelightConstants::kMaxDistance);
	mShuffleboardSuggestedHoodAngle.SetDouble(getServoAngle());
	mShuffleboardSuggestedSpeed.SetDouble(getShootSpeed());
	mShuffleboardTx.SetDouble(tx);
	mShuffleboardTv.SetBoolean(tv > 0);

	if (m_LimelightHasTarget == true) {
		steering_adjust = 0.0f;
		// if (tx < -1.0) { // Target is to the left of the robot, robot is to the right of the target -> robot must turn left
		// 	// steering_adjust = must be negative
		// 	steering_adjust = LimelightConstants::kP * tx - LimelightConstants::kMinCommand;
		// } else if (tx > 1.0) { // Target is to the right of the robot, robot is to the left of the target -> turn right
		// 	// steering_adjust = must be positive
		// 	steering_adjust = LimelightConstants::kP * tx + LimelightConstants::kMinCommand;
		// }
		if (tx < -3.0) { // Target is to the left of the robot, robot is to the right of the target -> robot must turn left
			// steering_adjust = must be negative
			steering_adjust = LimelightConstants::kP * tx - LimelightConstants::kMinCommand;
		} else if (tx > 3.0) { // Target is to the right of the robot, robot is to the left of the target -> turn right
			// steering_adjust = must be positive
			steering_adjust = LimelightConstants::kP * tx + LimelightConstants::kMinCommand;
		}
		// printf("Limelight rotation adjustment %f %f\n", steering_adjust, tx);
	}

	if (tv < 1.0) {
		m_LimelightHasTarget = false;
	} else {
		m_LimelightHasTarget = true;
	}
}

double Limelight::getShootSpeed() {
	rpm = -14 * d + 4455;
	if (d > 90) rpm = 5.92 * d + 2668;
	return rpm;
}

double Limelight::getServoAngle() {
	hoodAngle = -0.16 * d + 92;
	if (d > 160) hoodAngle = -0.01 * d + 68;
	return hoodAngle;
}
