#pragma once

#include <frc/SerialPort.h>
#include <frc/XboxController.h>
#include <frc/drive/Vector2d.h>
#include <frc2/command/SubsystemBase.h>
#include <math.h>

#include "Constants.h"
#include "subsystems/SwerveWheel.h"

// Use Field Oriented Drive with the Gyro Sensor
#define GYRO

class SwerveDrive : public frc2::SubsystemBase {
	public:
		SwerveDrive();
		void setController(frc::XboxController *pDriverController) {
			mpDriverController = pDriverController;
		}
		void testSwerve();
		void vectorSwerve();

		void Periodic() override;

	private:
		double pythag(double x, double y);
		double angleCalc(double x, double y);

#ifdef GYRO
		int readOffset();
#endif

		int angle;
		double speed;

		frc::XboxController *mpDriverController;
#ifdef GYRO
		frc::SerialPort mSerial{115200, frc::SerialPort::kUSB};
#endif

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
