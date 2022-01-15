#pragma once

#include <ctre/Phoenix.h>
#include <frc/Relay.h>
#include <frc2/command/SubsystemBase.h>

class Intake : public frc2::SubsystemBase {
	private:
		WPI_TalonSRX mIntakeRollerMotor;
		frc::Relay mIntakeArmMotor;

	public:
		Intake();

		void lowerIntakeArm();
		void raiseIntakeArm();
		void stopIntakeArm();
		void startRollers();
		void startReverseRollers();
		void stopRollers();

		void Periodic() override;
};
