#pragma once

#include <ctre/Phoenix.h>
#include <frc/DoubleSolenoid.h>
#include <frc2/command/SubsystemBase.h>

#include "Constants.h"

class Intake : public frc2::SubsystemBase {
	public:
		Intake();

		void lowerIntakeArm();
		void raiseIntakeArm();
		void toggleIntakeArm();
		frc::DoubleSolenoid::Value getArmState();

		enum RollerState {
			Off,
			Forward,
			Reverse,
		};

		void startRollers();
		void startReverseRollers();
		void stopRollers();
		void toggleRollerDirection();
		RollerState getRollerState();

		void Periodic() override;

	private:
		TalonSRX mRollerMotor;
		frc::DoubleSolenoid mArmSolenoid;

		RollerState mState = RollerState::Off;

};
