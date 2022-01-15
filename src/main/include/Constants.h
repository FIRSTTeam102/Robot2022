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

namespace IntakeConstants {
	// ports (NOT FINAL)
	const int kRollerMotor = 12;
	const int kArmSolenoid = 0;
	// speeds
	const double kRollerSpeed = 0.5;
} // namespace IntakeConstants