#pragma once

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

namespace SwerveDriveConstants {
	// Motor ports
	const int kFLDrive = 21;
	const int kFLTurn = 22;
	const int kFRDrive = 23;
	const int kFRTurn = 24;
	const int kBRDrive = 25;
	const int kBRTurn = 26;
	const int kBLDrive = 27;
	const int kBLTurn = 28;

	// Encoder Ports
	const int kFLEnc = 0;
	const int kFREnc = 1;
	const int kBREnc = 2;
	const int kBLEnc = 3;

	// Calibration Values
	const int kFLOffset = 603;
	const int kFROffset = 415;
	const int kBROffset = 2672;
	const int kBLOffset = 1156;

	const double kMaxSpeed = 1.00;

	// const double kMaxMotorSpeed = 5000.0; // this is in RPM
	// // in inches
	// const double kWheelDiameter = 4;
	// const double kDriveDiameter = 23;
}