#pragma once

// For drive practice
// #define PRACTICE

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants. This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

const int kPneumaticHub = 1;
const int kPowerDistributionHub = 2;

enum MotorDirection {
	kOff,
	kForward,
	kReverse
};

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
	const int kFLOffset = 577;
	const int kFROffset = 392;
	const int kBROffset = 2657;
	const int kBLOffset = 1150;

	const double kMaxSpeed = 1.00;

	const double kDeadzone = 0.1;

	// Motor Max Speeds
	const double kFLMaxSpeed = 490;
	const double kFRMaxSpeed = 507;
	const double kBRMaxSpeed = 494;
	const double kBLMaxSpeed = 513;
	const double kSlowestSpeed = kFLMaxSpeed;

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
	const int kLineSensorLeft = 0;
	const int kLineSensorRight = 1;
}

namespace IntakeConstants {
	// Ports
	const int kRollerMotor = 11;
	const int kArmSolenoidForward = 3;
	const int kArmSolenoidBackward = 4;

	// Speeds
	const double kRollerSpeed = 0.6;
}

namespace IndexerConstants {
	// Ports
	const int kIndexerMotor = 10;
	const int kBallSwitch = 5;

	// Speeds
	const double kMotorSpeed = 0.95;
}

namespace ShooterConstants {
	// Ports
	const int kShooterMotor = 9;

	// Motor constants
	constexpr double kMaxRpm = 6380;

	// Closed loop control
	const int kTimeoutMs = 30;
	const double kD = 0.0; // Derivative gain
	const double kF = 0.049588; // Feed forward gain
	const double kI = 0.0; // Integral gain
	const double kP = 0.22; // Proportional gain
}

namespace ShooterHoodConstants {
	const int kActuator = 0;

	const double kMinAngle = 60;
	const double kMaxAngle = 85;
	const double kAngleOffset = 13.818;

	const double kInnerR = 12.239;
	const double kOuterR = 18.734;
	const double kOuterY = 12.989;

	const double kMaxLength = 14.336;
	const double kMinLength = 8.946;

	const double kActuatorUpperBound = 0.95;
	const double kActuatorLowerBound = -0.95;
}

namespace HardcodedShots {
#ifdef PRACTICE
	constexpr float kTarmacLowerSpeedRPM = 1000;
	constexpr float kTarmacUpperSpeedRPM = 3000;
#else
	constexpr float kTarmacLowerSpeedRPM = 1800; // lower hub
	constexpr float kTarmacUpperSpeedRPM = 5920; // upper hub
#endif

	constexpr float kTarmacLowerSpeedPercent = kTarmacLowerSpeedRPM / ShooterConstants::kMaxRpm;
	constexpr float kTarmacUpperSpeedPercent = kTarmacUpperSpeedRPM / ShooterConstants::kMaxRpm;

	const double kTarmacLowerAngle = 75;
	const double kTarmacUpperAngle = 85;
}

namespace LimelightConstants {
	const double h = 60; // Height of limelight to target
	const double ay = 29.8; // Angle of limelight to target
	const double kDistanceError = 23; // Distance error, from edge to center of target
	const double kP = 0.0238; // tx multiplier
	const double kMinCommand = 0.35; // Yaw calculation deritive term

	const double kMaxDistance = 145; // Maximum distance that shooter can shoot from in inches, used by Shuffleboard
}