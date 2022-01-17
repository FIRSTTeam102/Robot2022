#pragma once

#include <ctre/Phoenix.h>
#include <frc/Solenoid.h>
#include <frc2/command/SubsystemBase.h>

class Intake : public frc2::SubsystemBase {
	private:
		TalonSRX mRollerMotor;
		frc::Solenoid mArmSolenoid;

	public:
		Intake();

		void lowerIntakeArm();
		void raiseIntakeArm();
		// void stopIntakeArm();
		void startRollers();
		void startReverseRollers();
		void stopRollers();

		void Periodic() override;
};
