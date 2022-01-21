#pragma once

#include <frc2/command/SubsystemBase.h>

#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"

class Limelight : public frc2::SubsystemBase {
	private:
		bool m_LimelightHasTarget;

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

		double getShootSpeed();
		bool LimelightHasTarget() { return m_LimelightHasTarget; }
		bool isClose() { return (ty < 9); }

		float rotation;

		std::shared_ptr<nt::NetworkTable> table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");

		void Periodic();
		bool Check();
};
