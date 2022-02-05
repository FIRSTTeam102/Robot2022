#include "subsystems/Limelight.h"

#include <frc/smartdashboard/SmartDashboard.h>

Limelight::Limelight() : m_LimelightHasTarget(false) {
	SetName("Limelight");
	SetSubsystem("Limelight");
	Kp = 0.01851851852f;
	min_command = 0.2f;
	table->PutNumber("ledMode", 0);
	table->PutNumber("pipeline", 0);
}

double Limelight::calculateShootAngle() {
	a = a1 + ty;
	return a;
}

double Limelight::calculateShootDistance() {
	d = h / tan(a);
	return d;
}

double Limelight::getShootSpeed() {
	if (d >= 330.0) {
		rpm = 3220;
	} else if (d >= 330.0) {
		rpm = 3205;
	} else if (d >= 325.0) {
		rpm = 3198;
	} else if (d >= 320.0) {
		rpm = 3191;
	} else if (d >= 315.0) {
		rpm = 3184;
	} else if (d >= 310.0) {
		rpm = 3177;
	} else if (d >= 305.0) {
		rpm = 3170;
	} else if (d >= 300.0) {
		rpm = 3163;
	} else if (d >= 295.0) {
		rpm = 3157;
	} else if (d >= 290.0) {
		rpm = 3150;
	} else if (d >= 285.0) {
		rpm = 3144;
	} else if (d >= 280.0) {
		rpm = 3137;
	} else if (d >= 275.0) {
		rpm = 3131;
	} else if (d >= 270.0) {
		rpm = 3125;
	} else if (d >= 265.0) {
		rpm = 3119;
	} else if (d >= 260.0) {
		rpm = 3113;
	} else if (d >= 255.0) {
		rpm = 3107;
	} else if (d >= 250.0) {
		rpm = 3101;
	} else if (d >= 245.0) {
		rpm = 3096;
	} else if (d >= 240.0) {
		rpm = 3090;
	} else if (d >= 235.0) {
		rpm = 3085;
	} else if (d >= 230.0) {
		rpm = 3080;
	} else if (d >= 225.0) {
		rpm = 3074;
	} else if (d >= 220.0) {
		rpm = 3069;
	} else if (d >= 215.0) {
		rpm = 3064;
	} else if (d >= 210.0) {
		rpm = 3059;
	} else if (d >= 205.0) {
		rpm = 3055;
	} else if (d >= 200.0) {
		rpm = 3050;
	} else if (d >= 195.0) {
		rpm = 3045;
	} else if (d >= 190.0) {
		rpm = 3041;
	} else if (d >= 185.0) {
		rpm = 3037;
	} else if (d >= 180.0) {
		rpm = 3032;
	} else if (d >= 175.0) {
		rpm = 3028;
	} else if (d >= 170.0) {
		rpm = 3024;
	} else if (d >= 165.0) {
		rpm = 3020;
	} else if (d >= 160.0) {
		rpm = 3016;
	} else if (d >= 155.0) {
		rpm = 3013;
	} else if (d >= 150.0) {
		rpm = 3009;
	} else if (d >= 145.0) {
		rpm = 3006;
	} else if (d >= 140.0) {
		rpm = 3002;
	} else if (d >= 135.0) {
		rpm = 2999;
	} else if (d >= 130.0) {
		rpm = 2996;
	} else if (d >= 125.0) {
		rpm = 2993;
	} else if (d >= 120.0) {
		rpm = 2990;
	} else if (d >= 115.0) {
		rpm = 2987;
	} else if (d >= 110.0) {
		rpm = 2985;
	} else if (d >= 105.0) {
		rpm = 2982;
	} else if (d >= 100.0) {
		rpm = 2980;
	} else if (d >= 95.0) {
		rpm = 2977;
	} else if (d >= 90.0) {
		rpm = 2975;
	} else if (d >= 85.0) {
		rpm = 2973;
	} else if (d >= 80.0) {
		rpm = 2971;
	} else if (d >= 75.0) {
		rpm = 2969;
	} else if (d >= 70.0) {
		rpm = 2968;
	} else if (d >= 65.0) {
		rpm = 2966;
	} else if (d >= 60.0) {
		rpm = 2965;
	} else if (d >= 55.0) {
		rpm = 2963;
	} else {
		rpm = 2961;
	}

	// return rpm / ShooterConstants::kMaxRpm; // convert to percent output
	return rpm;
}

double Limelight::getServoAngle() {
	if (d >= 330.0) {
		hoodAngle = 66.65;
	} else if (d >= 325.0) {
		hoodAngle = 67.58;
	} else if (d >= 320.0) {
		hoodAngle = 67.89;
	} else if (d >= 315.0) {
		hoodAngle = 68.20;
	} else if (d >= 310.0) {
		hoodAngle = 68.52;
	} else if (d >= 305.0) {
		hoodAngle = 68.83;
	} else if (d >= 300.0) {
		hoodAngle = 69.15;
	} else if (d >= 295.0) {
		hoodAngle = 69.47;
	} else if (d >= 290.0) {
		hoodAngle = 69.79;
	} else if (d >= 285.0) {
		hoodAngle = 70.11;
	} else if (d >= 280.0) {
		hoodAngle = 70.43;
	} else if (d >= 275.0) {
		hoodAngle = 70.76;
	} else if (d >= 270.0) {
		hoodAngle = 71.08;
	} else if (d >= 265.0) {
		hoodAngle = 71.41;
	} else if (d >= 260.0) {
		hoodAngle = 71.73;
	} else if (d >= 255.0) {
		hoodAngle = 72.06;
	} else if (d >= 250.0) {
		hoodAngle = 72.39;
	} else if (d >= 245.0) {
		hoodAngle = 72.72;
	} else if (d >= 240.0) {
		hoodAngle = 73.05;
	} else if (d >= 235.0) {
		hoodAngle = 73.39;
	} else if (d >= 230.0) {
		hoodAngle = 73.72;
	} else if (d >= 225.0) {
		hoodAngle = 74.06;
	} else if (d >= 220.0) {
		hoodAngle = 74.40;
	} else if (d >= 215.0) {
		hoodAngle = 74.73;
	} else if (d >= 210.0) {
		hoodAngle = 75.07;
	} else if (d >= 205.0) {
		hoodAngle = 75.41;
	} else if (d >= 200.0) {
		hoodAngle = 75.75;
	} else if (d >= 195.0) {
		hoodAngle = 76.10;
	} else if (d >= 190.0) {
		hoodAngle = 76.44;
	} else if (d >= 185.0) {
		hoodAngle = 76.78;
	} else if (d >= 180.0) {
		hoodAngle = 77.13;
	} else if (d >= 175.0) {
		hoodAngle = 77.47;
	} else if (d >= 170.0) {
		hoodAngle = 77.82;
	} else if (d >= 165.0) {
		hoodAngle = 78.17;
	} else if (d >= 160.0) {
		hoodAngle = 78.52;
	} else if (d >= 155.0) {
		hoodAngle = 78.87;
	} else if (d >= 150.0) {
		hoodAngle = 79.22;
	} else if (d >= 145.0) {
		hoodAngle = 79.57;
	} else if (d >= 140.0) {
		hoodAngle = 79.92;
	} else if (d >= 135.0) {
		hoodAngle = 80.27;
	} else if (d >= 130.0) {
		hoodAngle = 80.63;
	} else if (d >= 125.0) {
		hoodAngle = 80.98;
	} else if (d >= 120.0) {
		hoodAngle = 81.34;
	} else if (d >= 115.0) {
		hoodAngle = 81.69;
	} else if (d >= 110.0) {
		hoodAngle = 82.05;
	} else if (d >= 105.0) {
		hoodAngle = 82.41;
	} else if (d >= 100.0) {
		hoodAngle = 82.76;
	} else if (d >= 95.0) {
		hoodAngle = 83.12;
	} else if (d >= 90.0) {
		hoodAngle = 83.48;
	} else if (d >= 85.0) {
		hoodAngle = 83.84;
	} else if (d >= 80.0) {
		hoodAngle = 84.20;
	} else if (d >= 75.0) {
		hoodAngle = 84.56;
	} else if (d >= 70.0) {
		hoodAngle = 84.92;
	} else if (d >= 70.0) {
		hoodAngle = 84.92;
	} else {
		hoodAngle = 85.00;
	}

	return hoodAngle;
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

	if (m_LimelightHasTarget == true) {
		heading_error = tx;
		steering_adjust = 0.0f;
		if (tx < -1.0) { // Target is to the left of the robot, robot is to the right of the target -> robot must turn left
			// steering_adjust = must be negative
			steering_adjust = Kp * heading_error + min_command;
		} else if (tx > 1.0) { // Target is to the right of the robot, robot is to the left of the target -> turn right
			// steering_adjust = must be positive
			steering_adjust = Kp * heading_error - min_command;
		}
		rotation = steering_adjust;
		printf("Limelight rotation adjustment %f\n", rotation);
	}

	if (tv < 1.0) {
		m_LimelightHasTarget = false;
	} else {
		m_LimelightHasTarget = true;
	}
}