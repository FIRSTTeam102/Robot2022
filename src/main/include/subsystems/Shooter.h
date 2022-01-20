#pragma once

#include <ctre/Phoenix.h>
#include <frc/Servo.h>
#include <frc2/command/SubsystemBase.h>

#include "Constants.h"

class Shooter : public frc2::SubsystemBase {
	private:
		TalonSRX mShooterMotor;
		frc::Servo mHoodServo;

		float mSpeed;
		bool mIsRunning = false;

	public:
		Shooter();

		void setShooter(double speed);
		void stopShooter();
		double getSpeed();
		bool isRunning();

		void setServo(double value);
		void setServoAngle(double degrees);

		void Periodic() override;
};
