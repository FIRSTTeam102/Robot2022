#pragma once

#include <ctre/Phoenix.h>
#include <frc/Servo.h>
#include <frc/drive/Vector2d.h>
#include <frc2/command/SubsystemBase.h>

#include <cmath>

#include "Constants.h"

class Shooter : public frc2::SubsystemBase {
	private:
		TalonFX mShooterMotor;
		frc::Servo mHoodActuator;

		float mSpeed;
		bool mIsRunning = false;

	public:
		Shooter();

		void setShooter(double speed);
		void stopShooter();
		double getSpeed() {
			return mSpeed;
		}
		bool isRunning() {
			return mIsRunning;
		}

		double degreesToLinearLength(double degrees);
		double linearLengthToSetting(double length);

		void setActuator(double setting);
		double getHoodSetting() {
			return mHoodActuator.GetSpeed();
		}

		void Periodic() override;
};
