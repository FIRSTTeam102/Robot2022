#include "subsystems/SwerveWheel.h"

SwerveWheel::SwerveWheel(int drivePort, int turnPort, int encPort, int encOffset) : mDriveMotor{drivePort}, mTurnMotor{turnPort}, mEnc{encPort}, mAngleOffset{encOffset} {
	SetName("SwerveWheel");
	SetSubsystem("SwerveWheel");
	mWheelNum = encPort + 1;
}

void SwerveWheel::setAngle(double angle) {
	target = 360 - angle;
}

void SwerveWheel::setSpeed(double speed) {
	if (!inverted) {
		mDriveMotor.Set(TalonSRXControlMode::PercentOutput, speed);
	} else {
		mDriveMotor.Set(TalonSRXControlMode::PercentOutput, -speed);
	}
}

int SwerveWheel::circScale(int i) {
	return (i + 720) % 360;
}

// This method will be called once per scheduler run
void SwerveWheel::Periodic() {
	// printf("Encoder #%d at %d\n", mWheelNum, mEnc.GetValue()); // for calibration

	scaledPos = (double)(mEnc.GetValue() - mAngleOffset) * 360.0 / 4096.0;
	posCurrent = circScale(scaledPos);
	scaledTarg = circScale(target - posCurrent);
	if (scaledTarg > 90 && scaledTarg < 270) {
		scaledTarg += 180;
		scaledTarg = circScale(scaledTarg);
		inverted = true;
	} else {
		inverted = false;
	}
	if (scaledTarg > 180) {
		scaledTarg -= 360;
	}
	mTurnMotor.Set(TalonSRXControlMode::PercentOutput, SwerveDriveConstants::kMaxSpeed * (double)scaledTarg / 90.0);
	// printf("Wheel #%d Going to: %d   At: %d   Speed: %f\n", mWheelNum, target, scaledPos, SwerveDriveConstants::kMaxSpeed * (double)scaledTarg / 90.0);
}