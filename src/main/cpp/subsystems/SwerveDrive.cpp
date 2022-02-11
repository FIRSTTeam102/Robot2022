#include "subsystems/SwerveDrive.h"

#include <frc/smartdashboard/SmartDashboard.h>

SwerveDrive::SwerveDrive() : mWheelFL{SwerveDriveConstants::kFLDrive, SwerveDriveConstants::kFLTurn, SwerveDriveConstants::kFLEnc, SwerveDriveConstants::kFLOffset}, mWheelFR{SwerveDriveConstants::kFRDrive, SwerveDriveConstants::kFRTurn, SwerveDriveConstants::kFREnc, SwerveDriveConstants::kFROffset}, mWheelBR{SwerveDriveConstants::kBRDrive, SwerveDriveConstants::kBRTurn, SwerveDriveConstants::kBREnc, SwerveDriveConstants::kBROffset}, mWheelBL{SwerveDriveConstants::kBLDrive, SwerveDriveConstants::kBLTurn, SwerveDriveConstants::kBLEnc, SwerveDriveConstants::kBLOffset} {
	SetName("SwerveDrive");
	SetSubsystem("SwerveDrive");
	mIsFieldOriented = true;
	mAutoState = false;
	mGyro.Calibrate();
}

double SwerveDrive::angleCalc(double x, double y) {
	double angle;
	if (x == 0 && y == 0)
		return -1;
	if (y == 0)
		angle = 90.0;
	else
		angle = atan2(abs(x), abs(y)) * 57.2958; // multiply by 57.2958 to convert radians to degrees
	if (x < 0 && y < 0) {
		angle += 180;
	} else if (x < 0) {
		angle += 180 + (2 * (90 - angle));
		// if (y < 0)
		//     angle -= 2 * (90 - angle);
	} else if (y < 0)
		angle += 2 * (90 - angle);
	return angle;
}

double SwerveDrive::pythag(double x, double y) {
	return sqrt(pow(x, 2) + pow(y, 2));
}

// void SwerveDrive::testSwerve() {
// 	angle = angleCalc(mpDriverController->GetLeftX(), -mpDriverController->GetLeftY());
// 	printf("Set all to angle: %d\n", angle);
// 	mWheelFL.setAngle(angle);
// 	mWheelFR.setAngle(angle);
// 	mWheelBR.setAngle(angle);
// 	mWheelBL.setAngle(angle);

// 	// speed = kMaxSpeed * pythag(mpDriverController->GetRightTriggerAxis(), -mpDriverController->GetLeftTriggerAxis());
// 	speed = SwerveDriveConstants::kMaxSpeed * mpDriverController->GetRightTriggerAxis() - SwerveDriveConstants::kMaxSpeed * mpDriverController->GetLeftTriggerAxis();
// 	mWheelFL.setSpeed(speed);
// 	mWheelFR.setSpeed(speed);
// 	mWheelBR.setSpeed(speed);
// 	mWheelBL.setSpeed(speed);
// 	printf("Set to speed: %f\n", speed);
// }

int SwerveDrive::readOffset() {
	double offset = *getGyroAngle();
	
	return (int) offset;
}


void SwerveDrive::controllerSwerve() {
	if (mIsFieldOriented) {
		offset = readOffset();
	} else {
		offset = 0;
	}
	vectorSwerve(mpDriverController->GetLeftX(), -mpDriverController->GetLeftY(), mpDriverController->GetRightX(), offset);
}

void SwerveDrive::vectorSwerve(double leftX, double leftY, double rightX, int offset) {
	mDriveVector.x = leftX;
	mDriveVector.y = leftY;
	mDriveVector.Rotate(360 - offset); // Factor in gyroscope value (subtract from 360 to go from counterclockwise to clockwise)
	mTurnVector.x = rightX;
	mTurnVector.y = rightX;
	// printf("Turn speed: %f\n",mTurnVector.x);
	for (int i = 0; i < 4; i++) { // For each wheel:
		mSumVector.x = (0.7 * mDriveVector.x + 0.3 * mTurnVector.x); // Add the two vectors to get one final vector
		mSumVector.y = (0.7 * mDriveVector.y + 0.3 * mTurnVector.y);
		targetEncoder[i] = angleCalc(mSumVector.x, mSumVector.y); // Calculate the angle of this vector
		targetSpeed[i] = mSumVector.Magnitude() * SwerveDriveConstants::kMaxSpeed; // Scale the speed of the wheels
		// targetSpeed[i] = SwerveDriveConstants::kMaxSpeed * mpDriverController->GetRightTriggerAxis() - SwerveDriveConstants::kMaxSpeed * mpDriverController->GetLeftTriggerAxis();
		mTurnVector.Rotate(-90.0); // Rotate the vector clockwise 90 degrees
	}
	mWheelFL.setAngle(targetEncoder[0]);
	mWheelFR.setAngle(targetEncoder[1]);
	mWheelBR.setAngle(targetEncoder[2]);
	mWheelBL.setAngle(targetEncoder[3]);
	mWheelFL.setSpeed(targetSpeed[0]);
	mWheelFR.setSpeed(targetSpeed[1]);
	mWheelBR.setSpeed(targetSpeed[2]);
	mWheelBL.setSpeed(targetSpeed[3]);

	// printf("Swerve speed %f %f %f %f\n", targetSpeed[0], targetSpeed[1], targetSpeed[2], targetSpeed[3]);
}

void SwerveDrive::autoDrive(double angle, double speed) {
	mWheelFL.setAngle(angle);
	mWheelFR.setAngle(angle);
	mWheelBR.setAngle(angle);
	mWheelBL.setAngle(angle);
	mWheelFL.setSpeed(speed);
	mWheelFR.setSpeed(speed);
	mWheelBR.setSpeed(speed);
	mWheelBL.setSpeed(speed);
}

void SwerveDrive::stopDrive() {
	mWheelFL.setSpeed(0);
	mWheelFR.setSpeed(0);
	mWheelBR.setSpeed(0);
	mWheelBL.setSpeed(0);
}

void SwerveDrive::changeOrientation() {
	mGyro.Reset();
	mIsFieldOriented = !mIsFieldOriented;
}

void SwerveDrive::resetGyro() {
	mGyro.Reset();
}

double SwerveDrive::getGyroAngle() {
	return gyroAngle;
}

void SwerveDrive::setAutoState(bool state) {
	mAutoState = state;
}

bool SwerveDrive::getAutoState() {
	return mAutoState;
}

// This method will be called once per scheduler run
void SwerveDrive::Periodic() {
	gyroAngle = mGyro.GetAngle();
}
