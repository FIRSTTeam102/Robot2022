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

double Limelight::getShootSpeed() {
	// if (ty >= 23.46)
	// {
	// 	printf("\n");
	// 	return 0.405;
	// }
	// else if (ty >= 19.45)
	// {
	// 	printf("\n");
	// 	return 0.3725;
	// else {
	// 	printf("\n");
	return 0.5;
	// }
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
			steering_adjust = 0.25;
			// steering_adjust = Kp*heading_error - min_command;
		} else if (tx < 1.0) {
			steering_adjust = -0.25;
			// steering_adjust = Kp*heading_error + min_command;
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