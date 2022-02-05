#pragma once

#include <ctre/Phoenix.h>
#include <frc/Servo.h>
#include <frc2/command/SubsystemBase.h>

#include "Constants.h"

class Shooter : public frc2::SubsystemBase {
	private:
		TalonFX mShooterMotor;
		frc::Servo mHoodActuator;

		float mSpeed;
		bool mIsRunning = false;

		double degreesToActuator(double deg) {
			return ( 2 / ( ShooterConstants::kHoodMaxAngle - ShooterConstants::kHoodMinAngle ) ) * ( deg - ( ( ShooterConstants::kHoodMinAngle + ShooterConstants::kHoodMaxAngle ) / 2 ) );
		}

		double degreesToServo(double deg) {
			return ( ( deg - ShooterConstants::kHoodMinAngle ) / ( ShooterConstants::kHoodMaxAngle - ShooterConstants::kHoodMinAngle ) );
		}

		double actuatorToDegrees() {
			return ( ( ( ( ShooterConstants::kHoodMaxAngle - ShooterConstants::kHoodMinAngle ) / 2 ) * mHoodActuator.GetSpeed() ) + ( ( ShooterConstants::kHoodMaxAngle + ShooterConstants::kHoodMinAngle ) / 2 ) );
		}

	public:
		Shooter();

		void setShooter(double speed);
		void stopShooter();
		double getSpeed();
		bool isRunning();

		void setHoodAngle(double degrees);
		double getHoodAngle();

		void Periodic() override;
};
