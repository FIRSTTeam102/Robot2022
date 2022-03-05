#pragma once

#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/shuffleboard/ShuffleboardLayout.h>
#include <frc/shuffleboard/ShuffleboardTab.h>
#include <frc2/command/SubsystemBase.h>
#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableEntry.h>
#include <networktables/NetworkTableInstance.h>

#include "Constants.h"

class Limelight : public frc2::SubsystemBase {
	private:
		bool m_LimelightHasTarget;

		double ad; // Angle of robot to target in degrees
		double ar; // Angle of robot to target in radians
		double d; // Distance of robot to target

		double rpm; // RPM of the shooter
		double hoodAngle; // Angle of the hood

		double tx;
		double ty;
		double ta;
		bool tv;

		float steering_adjust = 0.0f;

		nt::NetworkTableEntry mShuffleboardDistance;
		nt::NetworkTableEntry mShuffleboardPossibleShot;
		nt::NetworkTableEntry mShuffleboardSuggestedHoodAngle;
		nt::NetworkTableEntry mShuffleboardSuggestedSpeed;
		nt::NetworkTableEntry mShuffleboardTx;
		nt::NetworkTableEntry mShuffleboardTv;

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
