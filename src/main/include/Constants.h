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
	const int kFLDrive = 1;
	const int kFLTurn = 2;
	const int kFRDrive = 3;
	const int kFRTurn = 4;
	const int kBRDrive = 5;
	const int kBRTurn = 6;
	const int kBLDrive = 7;
	const int kBLTurn = 8;

	// Encoder Ports
	const int kFLEnc = 0;
	const int kFREnc = 1;
	const int kBREnc = 2;
	const int kBLEnc = 3;

	// Calibration Values
	const int kFLOffset = 573;
	const int kFROffset = 412;
	const int kBROffset = 2686;
	const int kBLOffset = 1176;

	const double kMaxSpeed = 1.00;

	const double kMaxMotorSpeed = 6380.0; // this is in RPM
	// in inches
	const double kWheelDiameter = 4;
	const double kDriveDiameter = 23;
}