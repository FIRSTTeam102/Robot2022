#pragma once

#include <ctre/Phoenix.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/shuffleboard/ShuffleboardLayout.h>
#include <frc/shuffleboard/ShuffleboardTab.h>
#include <frc2/command/SubsystemBase.h>
#include <networktables/NetworkTableEntry.h>
#include <networktables/NetworkTableValue.h>
#include <wpi/StringMap.h>

#include <memory>
#include <utility>

#include "Constants.h"

class Shooter : public frc2::SubsystemBase {
	private:
		TalonFX mShooterMotor;

		float mSpeed;
		double mBoostPercent = 1.00;
		bool mIsRunning = false;

		nt::NetworkTableEntry mShuffleboardSpeedTarget;
		nt::NetworkTableEntry mShuffleboardSpeedActual;
		nt::NetworkTableEntry mShuffleboardBoost;

	public:
		Shooter();

		void setShooter(double speed, bool useRpm);
		void stopShooter();
		double getSpeed(bool useRpm);
		bool isRunning() {
			return mIsRunning;
		}

		void Periodic() override;
		
		nt::NetworkTableEntry mShuffleboardReady;
};
