#pragma once

#include <ctre/Phoenix.h>
#include <frc/Servo.h>
#include <frc/system/plant/DCMotor.h>
#include <frc2/command/SubsystemBase.h>

#include "Constants.h"

class Shooter : public frc2::SubsystemBase {
	private:
		TalonFX mShooterMotor;
		frc::Servo mHoodServo;

		float mSpeed;
		bool mIsRunning = false;

	public:
		Shooter();

		void setShooter(double speed, bool useRpm);
		void stopShooter();
		double getSpeed(bool useRpm);
		bool isRunning();

		void setServo(double value);
		void setServoAngle(double degrees);

		void Periodic() override;
};
