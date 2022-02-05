#pragma once

#include <ctre/Phoenix.h>
#include <frc/DoubleSolenoid.h>
#include <frc2/command/SubsystemBase.h>

class Intake : public frc2::SubsystemBase {
	private:
		TalonSRX mRollerMotor;
		frc::DoubleSolenoid mArmSolenoid;

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
