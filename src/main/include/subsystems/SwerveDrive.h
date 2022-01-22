#pragma once

#include <frc/AnalogGyro.h>
#include <frc/XboxController.h>
#include <frc/drive/Vector2d.h>
#include <frc2/command/SubsystemBase.h>
#include <cmath>

#include "Constants.h"
#include "subsystems/SwerveWheel.h"

// Use Field Oriented Drive with the Gyro Sensor

class SwerveDrive : public frc2::SubsystemBase {
	public:
		SwerveDrive();
		void setController(frc::XboxController *pDriverController) {
			mpDriverController = pDriverController;
		}
		double fixInput(double s, bool square = true) {
			if (square) s = std::copysign(s * s, s);

			if (-0.1 < s && s < 0.1)
				return 0.0;
			else
				return s;
		}
		void testSwerve();
		void controllerSwerve();
		void vectorSwerve(double leftX, double leftY, double rightX, int offset = 0);
		void autoDrive(double angle, double speed);
		void stopDrive();
		void changeOrientation();
		void resetGyro();
		double getGyroAngle();

		void Periodic() override;

		// Static values 

		static const double kWheelCircum = SwerveDriveConstants::kWheelDiameter * M_PI;
		static const double kDriveCircum = SwerveDriveConstants::kDriveDiameter * M_PI;

		static const double kRotationsPer360 = kDriveCircum / kWheelCircum;
		static const double kMaxTurnSpeed = SwerveDriveConstants::kMaxMotorSpeed * 0.70711;
	private:
		double pythag(double x, double y);
		double angleCalc(double x, double y);

		int readOffset();

		int angle;
		double speed;
		bool mIsFieldOriented;

		frc::XboxController *mpDriverController;
		frc::AnalogGyro mGyro{SwerveDriveConstants::kGyro};

		SwerveWheel mWheelFL;
		SwerveWheel mWheelFR;
		SwerveWheel mWheelBR;
		SwerveWheel mWheelBL;

		int targetEncoder[4];
		float targetSpeed[4], turnMagnitude[4];
		char rawOffset[10] = {0};
		int offset = 0;
		bool negativeOffset = false;
		frc::Vector2d mDriveVector;
		frc::Vector2d mTurnVector;
		frc::Vector2d mSumVector;
};
