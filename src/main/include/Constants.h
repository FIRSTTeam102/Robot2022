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

const int kPneumaticHub = 1;
const int kPowerDistributionHub = 2;

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

	// Encoder ports
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
}

namespace IntakeConstants {
	// Ports
	const int kRollerMotor = 11;
	const int kArmSolenoidDown = 3;
	const int kArmSolenoidUp = 4;
	// Speeds
	const double kRollerSpeed = 0.5;
}

namespace IndexerConstants {
	// Ports
	const int kIndexerMotor = 10;
	const int kBallSwitch = 5;
	// Speeds
	const double kMotorSpeed = 0.4;
}

namespace ShooterConstants {
	// Ports
	const int kShooterMotor = 9;
	const int kHoodActuator = 11;

	// Speeds
	const float kSlowSpeed = 0.3;
	const float kMedSpeed = 0.6;
	const float kFastSpeed = 1.0;

	// Hood angles
	const double kHoodMaxAngle = 85;
	const double kHoodMinAngle = 65;
}