#pragma once

#include <frc/drive/Vector2d.h>
#include <frc/Servo.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/shuffleboard/ShuffleboardLayout.h>
#include <frc/shuffleboard/ShuffleboardTab.h>
#include <frc2/command/SubsystemBase.h>
#include <networktables/NetworkTableEntry.h>

#include <cmath>

#include "Constants.h"

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
