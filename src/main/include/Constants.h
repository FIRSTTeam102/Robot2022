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
	const int kIndexerMotor = 7;
	const int kBallSwitch = 5;

	// Speeds
	const double kMotorSpeed = 0.4;
}

namespace IntakeConstants {
	// Ports
	const int kRollerMotor = 12;
	const int kArmSolenoid = 0;

	// Speeds
	const double kRollerSpeed = 0.5;
}

namespace ShooterConstants {
	// Ports
	const int kShooterMotor = 9;
	const int kHoodActuator = 11;

	// Speeds
	const float kSlowSpeed = 0.3;
	const float kMedSpeed = 0.6;
	const float kFastSpeed = 1.0;

	// Hood Angles
	const double kHoodMaxAngle = 85;
	const double kHoodMinAngle = 25;
}