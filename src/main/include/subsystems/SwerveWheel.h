#pragma once

#include <ctre/Phoenix.h>
#include <frc/AnalogInput.h>
#include <frc2/command/SubsystemBase.h>

#include "Constants.h"

class SwerveWheel : public frc2::SubsystemBase {
public:
	SwerveWheel(int drivePort, int turnPort, int encPort, int encOffset);

	void setAngle(double angle);
	void setSpeed(double speed);
	void resetEnc();

	void Periodic();

private:
	TalonSRX mDriveMotor;
	TalonSRX mTurnMotor;
	frc::AnalogInput mEnc;
	int circScale(int i);
	int mWheelNum; // for debugging
	int mAngleOffset;
	int target = 0;
	int scaledTarg;
	int scaledPos, posCurrent;
	bool inverted = false;
};