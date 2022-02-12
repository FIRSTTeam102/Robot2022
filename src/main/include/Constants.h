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

namespace ClimberConstants {
	// Ports
	const int kClimberSolenoidRightUp = 0;
	const int kClimberSolenoidRightDown = 1;
	const int kClimberSolenoidLeftUp = 6;
	const int kClimberSolenoidLeftDown = 7;
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
	const int kHoodActuator = 0;

	// Speeds
	const float kSlowSpeed = 0.5;
	const float kMedSpeed = 0.75;
	const float kFastSpeed = 1.0;

	// Hood/Actuator Data 
	const double kHoodMaxAngle = 85; // Not needed right now, may need later for LM
	const double kHoodMinAngle = 65; // Not needed right now, may need later for LM
	const double kInnerR = 12.239;
	const double kOuterR = 18.734;
	const double kOuterY = 12.989;
	const double kMaxLength = 14.336;
	const double kMinLength = 8.946;
	const double kActuatorUpperBound = 0.95;
	const double kActuatorLowerBound = -0.95;
}