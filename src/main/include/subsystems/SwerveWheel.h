#pragma once

#include <frc/AnalogInput.h>
#include <frc/motorcontrol/PWMTalonSRX.h>	
#include <frc2/command/SubsystemBase.h>

#include "Constants.h"

class SwerveWheel : public frc2::SubsystemBase {
public:
	SwerveWheel(int drivePort, int turnPort, int encPort, int encOffset, int id);

	void setAngle(double angle);
	void setSpeed(double speed);
	void resetEnc();

	void Periodic();

private:
	frc::PWMTalonSRX mDriveMotor;
	frc::PWMTalonSRX mTurnMotor;
	frc::AnalogInput mEnc;
	int circScale(int i);
	int mAngleOffset;
	int target = 0;
	int scaledTarg;
	int scaledPos, posCurrent;
	bool inverted = false;
	int mId;
};