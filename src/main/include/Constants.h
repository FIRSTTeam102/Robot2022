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
	const int kIntakeArmMotor = 0;
	const int kIntakeRollerMotor = 12;
	
	const double kIntakeRollerSpeed = 0.5;
} // namespace IntakeConstants