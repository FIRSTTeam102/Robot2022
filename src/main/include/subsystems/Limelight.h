#pragma once

#include <frc/DriverStation.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/shuffleboard/ShuffleboardLayout.h>
#include <frc/shuffleboard/ShuffleboardTab.h>
#include <frc2/command/SubsystemBase.h>
#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableEntry.h>
#include <networktables/NetworkTableInstance.h>

namespace LimelightConstants {
	const double h = 60; // Height of limelight to target
	const double ay = 29.8; // Angle of limelight to target
	const double kDistanceError = 23; // Distance error, from edge to center of target
	const double kP = 0.0485185; // tx multiplier
	const double kMinCommand = 0.65; // Yaw calculation deritive term

	const double kMaxDistance = 150; // Maximum distance that shooter can shoot from in inches, used by Shuffleboard
}

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
		double tv;

		float steering_adjust = 0.0f;

		bool lightOn = true;

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
		void setLight(bool on) {
			lightOn = on;
			// https://docs.limelightvision.io/en/latest/networktables_api.html#camera-controls
			// 0: use pipeline default
			// 1: force off
			// 3: force on
			table->PutNumber("ledMode", on ? 0 : 1);
		}
		void toggleLight() {
			lightOn = !lightOn;
			setLight(lightOn);
		}

		std::shared_ptr<nt::NetworkTable> table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");

		void Periodic();
		bool Check();
};
