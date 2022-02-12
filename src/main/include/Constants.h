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

namespace IndexerConstants {
	// Ports
	const int kIndexerMotor = 10;
	const int kBallSwitch = 5;

	// Speeds
	const double kMotorSpeed = 0.4;
}

namespace IntakeConstants {
	// Ports
	const int kRollerMotor = 11;
	const int kArmSolenoid = 0;

	// Speeds
	const double kRollerSpeed = 0.5;
}

namespace ShooterConstants {
	// Ports
	const int kShooterMotor = 9;
	const int kHoodServo = 11;

	// Motor constants
	const double kMaxRpm = 6380;

	// Speeds
	const float kSlowSpeed = 0.3;
	const float kMedSpeed = 0.6;
	const float kFastSpeed = 1.0;

	// const float kRPMSlowSpeed = kMaxRpm * kSlowSpeed;
	// const float kRPMMedSpeed = kMaxRpm * kMedSpeed;
	// const float kRPMFastSpeed = kMaxRpm * kFastSpeed;

	// const float kRPMSlowSpeed = 2000;
	// const float kRPMMedSpeed = 3000;
	// const float kRPMFastSpeed = 4000;

}

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
}