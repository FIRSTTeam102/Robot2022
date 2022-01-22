#pragma once

#include <frc2/command/SubsystemBase.h>
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"

#include "Constants.h"

class Limelight : public frc2::SubsystemBase {
	private:
		bool m_LimelightHasTarget;

		static constexpr double h = 54; // Height between Limelight to the top of the target
		static constexpr double a1 = 25; // a1 is the degrees of the Limelight. a2 is the fov of the limelight
		double a; // Angle needed to see the Target
		double d; // Distance to the target

		double rpm; // RPM of the shooter
		double hoodAngle;  // Angle of the hood

		double tx;
		double ty;
		double ta;
		bool tv;

		float heading_error;
		float steering_adjust = 0.0f;

		float Kp;
		float min_command;

	public:
		Limelight();

		double calculateShootAngle();
		double calculateShootDistance();
		double getShootSpeed();
		double getServoAngle();
		bool LimelightHasTarget() { return m_LimelightHasTarget; }
		bool isClose() { return (ty < 9); }

		float rotation;

		std::shared_ptr<nt::NetworkTable> table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");

		void Periodic();
		bool Check();
};
