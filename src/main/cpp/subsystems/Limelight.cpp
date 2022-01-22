#include "subsystems/Limelight.h"

#include <frc/smartdashboard/SmartDashboard.h>

Limelight::Limelight() : m_LimelightHasTarget(false) {
	SetName("Limelight");
	SetSubsystem("Limelight");
	Kp = -0.1f;
	min_command = 0.05f;
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
	if (d >= 250.0) {
		rpm = 3101;
	} else if (d >= 240.0) {
		rpm = 3090;
	} else if (d >= 230.0) {
		rpm = 3080;
	} else if (d >= 220.0) {
		rpm = 3069;
	} else if (d >= 210.0) {
		rpm = 3059;
	} else if (d >= 200.0) {
		rpm = 3050;
	} else if (d >= 190.0) {
		rpm = 3041;
	} else if (d >= 180.0) {
		rpm = 3032;
	} else if (d >= 170.0) {
		rpm = 3024;
	} else if (d >= 160.0) {
		rpm = 3016;
	} else if (d >= 150.0) {
		rpm = 3009;
	} else if (d >= 140.0) {
		rpm = 3002;
	} else if (d >= 130.0) {
		rpm = 2996;
	} else if (d >= 120.0) {
		rpm = 2990;
	} else if (d >= 110.0) {
		rpm = 2985;
	} else if (d >= 100.0) {
		rpm = 2980;
	} else if (d >= 90.0) {
		rpm = 2975;
	} else {
		rpm = 2965;
	}
}

double Limelight::getServoAngle() {
	if (d >= 250.0) {
		hoodangle = 72.39;
	} else if (d >= 240.0) {
		hoodangle = 73.05;
	} else if (d >= 230.0) {
		hoodangle = 73.72;
	} else if (d >= 220.0) {
		hoodangle = 74.40;
	} else if (d >= 210.0) {
		hoodangle = 75.07;
	} else if (d >= 200.0) {
		hoodangle = 75.75;
	} else if (d >= 190.0) {
		hoodangle = 76.44;
	} else if (d >= 180.0) {
		hoodangle = 77.13;
	} else if (d >= 170.0) {
		hoodangle = 77.82;
	} else if (d >= 160.0) {
		hoodangle = 78.52;
	} else if (d >= 150.0) {
		hoodangle = 79.22;
	} else if (d >= 140.0) {
		hoodangle = 79.92;
	} else if (d >= 130.0) {
		hoodangle = 80.63;
	} else if (d >= 120.0) {
		hoodangle = 81.34;
	} else if (d >= 110.0) {
		hoodangle = 82.05;
	} else if (d >= 100.0) {
		hoodangle = 82.76;
	} else if (d >= 90.0) {
		hoodangle = 83.48;
	} else {
		hoodangle = 85.28;
	}
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
		heading_error = -tx;
		steering_adjust = 0.0f;
		if (tx > 1.0) {
			// steering_adjust = 0.25;
			steering_adjust = Kp * heading_error - min_command;
		} else if (tx < 1.0) {
			// steering_adjust = -0.25;
			steering_adjust = -Kp * heading_error + min_command;
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