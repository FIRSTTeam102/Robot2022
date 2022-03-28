#include "subsystems/SwerveDrive.h"

#include "commands/SwerveDrive/SwerveCalibrator.h"

#define M_DEGTORAD 57.2958

SwerveDrive::SwerveDrive(frc::XboxController* pController) :
mpController{pController} {
	SetName("SwerveDrive");
	SetSubsystem("SwerveDrive");
	mIsFieldOriented = false;
	mAutoState = false;
	mGyro.Calibrate();

	// Shuffleboard
	mShuffleboardFieldOriented = frc::Shuffleboard::GetTab("Drive").Add("Field oriented", mIsFieldOriented).GetEntry();

	frc::ShuffleboardLayout& calibrationLayout = frc::Shuffleboard::GetTab("Test").GetLayout("Swerve calibrator", frc::BuiltInLayouts::kList);
	mShuffleboardCalibrationFL = calibrationLayout.Add("FL", SwerveDriveConstants::kFLOffset).GetEntry();
	mShuffleboardCalibrationFR = calibrationLayout.Add("FR", SwerveDriveConstants::kFROffset).GetEntry();
	mShuffleboardCalibrationBL = calibrationLayout.Add("BL", SwerveDriveConstants::kBLOffset).GetEntry();
	mShuffleboardCalibrationBR = calibrationLayout.Add("BR", SwerveDriveConstants::kBROffset).GetEntry();
	calibrationLayout.Add("Calibrate", new SwerveCalibrator(this)).WithWidget(frc::BuiltInWidgets::kCommand).GetEntry();
	calibrationLayout.Add("Set values", new frc2::InstantCommand([&] { setOffsets(); }, {this})).WithWidget(frc::BuiltInWidgets::kCommand).GetEntry();
}

double SwerveDrive::angleCalc(double x, double y) {
	double angle;

	if (x == 0 && y == 0) return -1;

	if (y == 0) angle = 90.0;
	else angle = atan2(abs(x), abs(y)) * M_DEGTORAD;

	if (x < 0 && y < 0) {
		angle += 180;
	} else if (x < 0) {
		angle += 180 + (2 * (90 - angle));
		// if (y < 0)
		//     angle -= 2 * (90 - angle);
	} else if (y < 0) {
		angle += 2 * (90 - angle);
	}

	return angle;
}

double SwerveDrive::pythag(double x, double y) {
	return sqrt(pow(x, 2) + pow(y, 2));
}

void SwerveDrive::controllerSwerve() {
	double offset;
	if (mIsFieldOriented) offset = getGyroAngle();
	else offset = 0.0;

	vectorSwerve(
		fixInput(mpController->GetLeftX()),
		fixInput(-mpController->GetLeftY()),
		fixInput(mpController->GetRightX()),
		offset);
}

void SwerveDrive::vectorSwerve(double driveX, double driveY, double turn, double offset) {
	mDriveVector.x = driveX;
	mDriveVector.y = driveY;
	mDriveVector.Rotate(/*360 - */ offset); // Factor in gyroscope value (subtract from 360 to go from counterclockwise to clockwise)

	mTurnVector.x = turn;
	mTurnVector.y = turn;
	// printf("Turn speed: %f\n", mTurnVector.x);

	double turnPercent = 0.4 * abs(turn); // give at max 40% to turn
	double drivePercent = (1 - turnPercent); // allocate all of the remaining power to drive

	if (frc::DriverStation::IsAutonomous()) { // use hardcoded values for auto for now
		drivePercent = 0.7;
		turnPercent = 0.3;
	}

	for (int i = 0; i < 4; i++) { // For each wheel:
		mSumVector.x = (drivePercent * mDriveVector.x + turnPercent * mTurnVector.x); // Add the two vectors to get one final vector
		mSumVector.y = (drivePercent * mDriveVector.y + turnPercent * mTurnVector.y);
		targetEncoder[i] = angleCalc(mSumVector.x, mSumVector.y); // Calculate the angle of this vector
		targetSpeed[i] = mSumVector.Magnitude() * SwerveDriveConstants::kMaxSpeed; // Scale the speed of the wheels
		// targetSpeed[i] = SwerveDriveConstants::kMaxSpeed *
		// mpController->GetRightTriggerAxis() - SwerveDriveConstants::kMaxSpeed
		// * mpDriverController->GetLeftTriggerAxis();
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

	// printf("Swerve speed %f %f %f %f\n", targetSpeed[0], targetSpeed[1],
	// targetSpeed[2], targetSpeed[3]);
}

void SwerveDrive::autoDrive(double angle, double speed) {
	setAngles(angle);
	setSpeeds(speed);
}

void SwerveDrive::setAngles(double angle) {
	mWheelFL.setAngle(angle);
	mWheelFR.setAngle(angle);
	mWheelBR.setAngle(angle);
	mWheelBL.setAngle(angle);
}

void SwerveDrive::setSpeeds(double speed) {
	mWheelFL.setSpeed(speed);
	mWheelFR.setSpeed(speed);
	mWheelBR.setSpeed(speed);
	mWheelBL.setSpeed(speed);
}

void SwerveDrive::stopDrive() { setSpeeds(0); }

void SwerveDrive::changeOrientation() {
	mIsFieldOriented = !mIsFieldOriented;
	mShuffleboardFieldOriented.SetBoolean(mIsFieldOriented);
}

void SwerveDrive::resetGyro() { mGyro.Reset(); }

// This method will be called once per scheduler run
void SwerveDrive::Periodic() {
	mGyroAngle = mGyro.GetAngle();
}
