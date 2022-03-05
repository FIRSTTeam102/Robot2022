#include "subsystems/Limelight.h"

#include <frc/smartdashboard/SmartDashboard.h>

Limelight::Limelight() : m_LimelightHasTarget(false) {
	SetName("Limelight");
	SetSubsystem("Limelight");
	table->PutNumber("ledMode", 0);
	table->PutNumber("pipeline", 0);

	// Shuffleboard
	frc::ShuffleboardLayout& layout = frc::Shuffleboard::GetTab("Teleop").GetLayout("Limelight", frc::BuiltInLayouts::kList);

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
	d = (LimelightConstants::h / tan(ar)) + LimelightConstants::de;
	return d;
}

bool Limelight::Check() {
	if (-1.0 < tx && tx < 1.0) {
		return true;
	}
	return false;
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

	// printf("Angle from target in degrees %f\n", ad);
	// printf("Angle from target in radians %f\n", ar);
	// printf("Distance %f, Hood Angle %f\n", d, hoodAngle);

	if (m_LimelightHasTarget == true) {
		steering_adjust = 0.0f;
		if (tx < -1.0) { // Target is to the left of the robot, robot is to the right of the target -> robot must turn left
			// steering_adjust = must be negative
			steering_adjust = LimelightConstants::kP * tx - LimelightConstants::kMinCommand;
		} else if (tx > 1.0) { // Target is to the right of the robot, robot is to the left of the target -> turn right
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
	/* if (d >= 145.0) {
		rpm = 1595;
	} else if (d >= 165.0) {
		rpm = 1595;
	} else if (d >= 160.0) {
		rpm = 1595;
	} else if (d >= 155.0) {
		rpm = 1595;
	} else if (d >= 150.0) {
		rpm = 1595;
	} else */ if (d >= 145.0) {
		rpm = 1595;
	} else if (d >= 140.0) {
		rpm = 1501;
	} else if (d >= 135.0) {
		rpm = 1500;
	} else if (d >= 130.0) {
		rpm = 1498;
	} else if (d >= 125.0) {
		rpm = 1497;
	} else if (d >= 120.0) {
		rpm = 1495;
	} else if (d >= 115.0) {
		rpm = 1494;
	} else if (d >= 110.0) {
		rpm = 1492;
	} else if (d >= 105.0) {
		rpm = 1491;
	} else if (d >= 100.0) {
		rpm = 1490;
	} else if (d >= 95.0) {
		rpm = 1489;
	} else if (d >= 90.0) {
		rpm = 1488;
	} else if (d >= 85.0) {
		rpm = 1487;
	} else if (d >= 80.0) {
		rpm = 1486;
	} else if (d >= 75.0) {
		rpm = 1485;
	} else if (d >= 70.0) {
		rpm = 1484;
	} else if (d >= 65.0) {
		rpm = 1483;
	} else if (d >= 60.0) {
		rpm = 1482;
	} else if (d >= 55.0) {
		rpm = 1482;
	} else {
		rpm = 1480;
	}
	rpm = rpm * 4;
	return rpm;
}

double Limelight::getServoAngle() {
	if (d >= 155.0) {
		hoodAngle = 67.50;
	} else if (d >= 150.0) {
		hoodAngle = 67.75; //79.22 ***
	} else if (d >= 145.0) {
		hoodAngle = 68.00; //79.57 ***
	} else if (d >= 140.0) {
		hoodAngle = 68.25; //79.92 ***
	} else if (d >= 135.0) {
		hoodAngle = 69.00; //80.27 ***
	} else if (d >= 130.0) {
		hoodAngle = 69.50; //80.63 ***
	} else if (d >= 125.0) {
		hoodAngle = 70.00; //80.98 ***
	} else if (d >= 120.0) {
		hoodAngle = 70.50; //81.34 ***
	} else if (d >= 115.0) {
		hoodAngle = 70.75; //81.69 ***
	} else if (d >= 110.0) {
		hoodAngle = 71.25; //82.05 ***
	} else if (d >= 105.0) {
		hoodAngle = 72.50; //82.41 ***
	} else if (d >= 100.0) {
		hoodAngle = 74.00; //82.76 ***
	} else if (d >= 95.0) {
		hoodAngle = 75.50; //83.12 ***
	} else if (d >= 90.0) {
		hoodAngle = 76.50; //83.48 ***
	} else if (d >= 85.0) {
		hoodAngle = 77.00; //83.84 ***
	} else if (d >= 80.0) {
		hoodAngle = 80.00; //84.20 ***
	} else if (d >= 75.0) {
		hoodAngle = 80.00; //84.56 ***
	} else if (d >= 70.0) {
		hoodAngle = 80.00; //84.92 ***
	} else {
		hoodAngle = 85.00;
	}
	printf("Distance %f, Hood Angle %f\n", d, hoodAngle);
	return hoodAngle;
}
