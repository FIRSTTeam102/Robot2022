#pragma once

#include <ctre/Phoenix.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/shuffleboard/ShuffleboardLayout.h>
#include <frc/shuffleboard/ShuffleboardTab.h>
#include <frc2/command/SubsystemBase.h>

#include "Constants.h"

class Shooter : public frc2::SubsystemBase {
	private:
		TalonFX mShooterMotor;

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

		void Periodic() override;
};
