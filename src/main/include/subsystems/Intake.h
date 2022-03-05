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
