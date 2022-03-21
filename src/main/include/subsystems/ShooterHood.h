#pragma once

#include <frc/drive/Vector2d.h>
#include <frc/Servo.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/shuffleboard/ShuffleboardLayout.h>
#include <frc/shuffleboard/ShuffleboardTab.h>
#include <frc2/command/SubsystemBase.h>
#include <networktables/NetworkTableEntry.h>

#include <algorithm>
#include <cmath>

namespace ShooterHoodConstants {
	const int kActuator = 0;

	const double kMinAngle = 60;
	const double kMaxAngle = 85;
	const double kAngleOffset = 13.818;

	const double kInnerR = 12.239;
	const double kOuterR = 18.734;
	const double kOuterY = 12.989;

	const double kMaxLength = 14.336;
	const double kMinLength = 8.946;

	const double kActuatorUpperBound = 0.95;
	const double kActuatorLowerBound = -0.95;
}

class ShooterHood : public frc2::SubsystemBase {
	private:
		frc::Servo mHoodActuator;
		
		double mTargetSetting;
		double mDegrees;

		double degreesToLinearLength(double degrees);
		double linearLengthToSetting(double length);

		nt::NetworkTableEntry mShuffleboardTargetAngle;
		nt::NetworkTableEntry mShuffleboardTargetBool;

	public:
		ShooterHood();

		void setAngle(double degrees);
		void incrementAngle(double degreeChange);
		double getAngle() {
			return mDegrees;
		}

		double getTargetSetting() {
			return mTargetSetting;
		}
		double getSetting() {
			return mHoodActuator.GetSpeed();
		}

		bool isAtTarget() {
			if ( getSetting() < 0 ) return ( getSetting() <= mTargetSetting );
			else return ( getSetting() >= mTargetSetting );
		}

		void Periodic() override;
};
