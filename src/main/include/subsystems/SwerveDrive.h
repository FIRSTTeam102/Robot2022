#pragma once

#include <AHRS.h>
#include <frc/XboxController.h>
#include <frc/drive/Vector2d.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc2/command/SubsystemBase.h>

#include <cmath>

#include "Constants.h"
#include "subsystems/SwerveWheel.h"

class SwerveDrive : public frc2::SubsystemBase {
	public:
		SwerveDrive(frc::XboxController *pController);

		double fixInput(double s, bool square = true) {
			if (square) s = std::copysign(s * s, s);

			if (-SwerveDriveConstants::kDeadzone < s && s < SwerveDriveConstants::kDeadzone)
				return 0.0;
			else
				return s;
		}

		void controllerSwerve();
		void vectorSwerve(double leftX, double leftY, double rightX, double offset = 0.0);

		void autoDrive(double angle, double speed);
		void setAngles(double angle);
		void setSpeeds(double speed);
		void stopDrive();

		void changeOrientation();

		void resetGyro();
		double getGyroAngle() {
			return mGyroAngle;
		}

		void setAutoState(bool state) {
			mAutoState = state;
		}
		bool getAutoState() {
			return mAutoState;
		}

		void Periodic() override;

		// Static values

		// static const double kWheelCircum = SwerveDriveConstants::kWheelDiameter * M_PI;
		// static const double kDriveCircum = SwerveDriveConstants::kDriveDiameter * M_PI;

		// static const double kRotationsPer360 = kDriveCircum / kWheelCircum;
		// static const double kMaxTurnSpeed = SwerveDriveConstants::kMaxMotorSpeed * 0.70711;
	private:
		double pythag(double x, double y);
		double angleCalc(double x, double y);

		double speed;
		bool mIsFieldOriented;
		bool mAutoState;

		frc::XboxController* mpController;
		AHRS mGyro{frc::SPI::Port::kMXP};

		nt::NetworkTableEntry mShuffleboardFieldOriented;

		SwerveWheel mWheelFL;
		SwerveWheel mWheelFR;
		SwerveWheel mWheelBR;
		SwerveWheel mWheelBL;

		int targetEncoder[4];
		float targetSpeed[4], turnMagnitude[4];
		// char rawOffset[10] = {0};
		// bool negativeOffset = false;
		frc::Vector2d mDriveVector;
		frc::Vector2d mTurnVector;
		frc::Vector2d mSumVector;

		double mGyroAngle;
		double mInitialGyroOffset;
};
