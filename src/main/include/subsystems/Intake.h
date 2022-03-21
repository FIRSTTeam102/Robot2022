#pragma once

#include <ctre/Phoenix.h>
#include <frc/DoubleSolenoid.h>
#include <frc2/command/SubsystemBase.h>

#include "Utilities.h"

namespace IntakeConstants {
	// Ports
	const int kRollerMotor = 11;
	const int kArmSolenoidForward = 3;
	const int kArmSolenoidBackward = 4;

	// Speeds
	const double kRollerSpeed = 0.6;
}

class Intake : public frc2::SubsystemBase {
	public:
		Intake();

		void lowerIntakeArm();
		void raiseIntakeArm();
		void toggleIntakeArm();
		void setIntakeArm(frc::DoubleSolenoid::Value state);
		frc::DoubleSolenoid::Value getArmState();

		void startRollers();
		void startReverseRollers();
		void stopRollers();
		void toggleRollerDirection();
		MotorDirection getRollerState() { return mState; };

		void Periodic() override;

		bool mLock = false; // used to prevent other intake commands from running

	private:
		TalonSRX mRollerMotor;
		frc::DoubleSolenoid mArmSolenoid;

		MotorDirection mState = MotorDirection::kOff;
};
