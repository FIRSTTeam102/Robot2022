#pragma once

#include <ctre/Phoenix.h>
#include <frc/AnalogInput.h>
#include <frc2/command/SubsystemBase.h>

class SwerveWheel : public frc2::SubsystemBase {
	public:
		SwerveWheel(int drivePort, int turnPort, int encPort, int encOffset, double maxSpeed);

		void setAngle(double angle);
		void setSpeed(double speed);

		int getEnc() {
			return mEnc.GetValue();
		}
		void setCalibration(bool enabled) {
			mCalibration = enabled;
			if (enabled) mTurnMotor.SetNeutralMode(NeutralMode::Coast);
			else mTurnMotor.SetNeutralMode(NeutralMode::Brake);
		}
		void setOffset(int offset) {
			mAngleOffset = offset;
			printf("wheel %d offset set to %d\n", mWheelNum, mAngleOffset);
		}

		void Periodic();

	private:
		TalonSRX mDriveMotor;
		TalonSRX mTurnMotor;
		frc::AnalogInput mEnc;
		int circScale(int i);
		int mWheelNum; // for debugging
		int mAngleOffset;
		double mMaxSpeed;
		int target = 0;
		int scaledTarg;
		int scaledPos, posCurrent;
		bool inverted = false;
		bool mCalibration = false;
};