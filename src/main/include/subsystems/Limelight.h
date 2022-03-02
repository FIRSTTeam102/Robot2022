#pragma once

#include <frc2/command/SubsystemBase.h>
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"

#include "Constants.h"

class Limelight : public frc2::SubsystemBase {
	private:
		bool m_LimelightHasTarget;

		static constexpr double h = 61; // Height of limelight to target
		static constexpr double ay = 31.4; // Angle of limelight to target
		double ad; // Angle of robot to target in degrees
		double ar; // Angle of robot to target in radians
		static constexpr double de = 20; // Distance error
		double d; //Distance of robot to targte

		double rpm; // RPM of the shooter
		double hoodAngle;  // Angle of the hood

		double tx;
		double ty;
		double ta;
		bool tv;

		float steering_adjust = 0.0f;

		float Kp;
		float min_command;

	public:
		Limelight();

		double calculateShootAngle();
		double convertShootAngletoRadians();
		double calculateShootDistance();
		double getShootSpeed();
		double getServoAngle();
		bool LimelightHasTarget() { return m_LimelightHasTarget; }
		bool isClose() { return (ty < 9); }
		float getRotation() { return steering_adjust; }

		std::shared_ptr<nt::NetworkTable> table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");

		void Periodic();
		bool Check();
};
