#include "subsystems/Limelight.h"

#include <frc/smartdashboard/SmartDashboard.h>

Limelight::Limelight() : m_LimelightHasTarget(false) {
	SetName("Limelight");
	SetSubsystem("Limelight");
	Kp = 0.02777;
	min_command = 0.20f;
	table->PutNumber("ledMode", 0);
	table->PutNumber("pipeline", 0);
}

double Limelight::calculateShootAngle() {
	ad = ay + ty;
	return ad;
}

double Limelight::convertShootAngletoRadians() {
	ar = ad * 3.131592 / 180;
	return ar;
}

double Limelight::calculateShootDistance() {
	d = (h / tan(ar)) + de;
	return d;
}

double Limelight::getShootSpeed() {
	if (d >= 330.0) {
		rpm = 1610;
	} else if (d >= 330.0) {
		rpm = 1603;
	} else if (d >= 325.0) {
		rpm = 1599;
	} else if (d >= 320.0) {
		rpm = 1595;
	} else if (d >= 315.0) {
		rpm = 1592;
	} else if (d >= 310.0) {
		rpm = 1588;
	} else if (d >= 305.0) {
		rpm = 1585;
	} else if (d >= 300.0) {
		rpm = 1582;
	} else if (d >= 295.0) {
		rpm = 1578;
	} else if (d >= 290.0) {
		rpm = 1575;
	} else if (d >= 285.0) {
		rpm = 1572;
	} else if (d >= 280.0) {
		rpm = 1569;
	} else if (d >= 275.0) {
		rpm = 1566;
	} else if (d >= 270.0) {
		rpm = 1562;
	} else if (d >= 265.0) {
		rpm = 1559;
	} else if (d >= 260.0) {
		rpm = 1556;
	} else if (d >= 255.0) {
		rpm = 1554;
	} else if (d >= 250.0) {
		rpm = 1551;
	} else if (d >= 245.0) {
		rpm = 1548;
	} else if (d >= 240.0) {
		rpm = 1545;
	} else if (d >= 235.0) {
		rpm = 1542;
	} else if (d >= 230.0) {
		rpm = 1540;
	} else if (d >= 225.0) {
		rpm = 1537;
	} else if (d >= 220.0) {
		rpm = 1535;
	} else if (d >= 215.0) {
		rpm = 1532;
	} else if (d >= 210.0) {
		rpm = 1530;
	} else if (d >= 205.0) {
		rpm = 1527;
	} else if (d >= 200.0) {
		rpm = 1525;
	} else if (d >= 195.0) {
		rpm = 1523;
	} else if (d >= 190.0) {
		rpm = 1520;
	} else if (d >= 185.0) {
		rpm = 1518;
	} else if (d >= 180.0) {
		rpm = 1516;
	} else if (d >= 175.0) {
		rpm = 1514;
	} else if (d >= 170.0) {
		rpm = 1512;
	} else if (d >= 165.0) {
		rpm = 1510;
	} else if (d >= 160.0) {
		rpm = 1508;
	} else if (d >= 155.0) {
		rpm = 1506;
	} else if (d >= 150.0) {
		rpm = 1505;
	} else if (d >= 145.0) {
		rpm = 1503;
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
	} else {
		hoodAngle = 85.00;
	}
	printf("Distance %f, Hood Angle %f\n", d, hoodAngle);
	return hoodAngle;
}

bool Limelight::Check() {
	if (-1.0 < tx && tx < 1.0) {
		return true;
	}
	return false;
}

void Limelight::Periodic() {
	printf("Distance %f, Hood Angle %f\n", d, hoodAngle);
	tx = table->GetNumber("tx", 0.0);
	ty = table->GetNumber("ty", 0.0);
	ta = table->GetNumber("ta", 0.0);
	tv = table->GetNumber("tv", 0.0);

	calculateShootAngle();
	convertShootAngletoRadians();
	calculateShootDistance();
	// printf("Angle from target in degrees %f\n", ad);
	// printf("Angle from target in radians %f\n", ar);
	// printf("Distance from target %f\n", d);

	if (m_LimelightHasTarget == true) {
		steering_adjust = 0.0f;
		if (tx < -1.0) { // Target is to the left of the robot, robot is to the right of the target -> robot must turn left
			// steering_adjust = must be negative
			steering_adjust = Kp * tx - min_command;
		} else if (tx > 1.0) { // Target is to the right of the robot, robot is to the left of the target -> turn right
			// steering_adjust = must be positive
			steering_adjust = Kp * tx + min_command;
		}
		// printf("Limelight rotation adjustment %f %f\n", steering_adjust, tx);
	}

	if (tv < 1.0) {
		m_LimelightHasTarget = false;
	} else {
		m_LimelightHasTarget = true;
	}
}