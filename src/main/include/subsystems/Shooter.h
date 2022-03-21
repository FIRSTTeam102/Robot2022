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

namespace ShooterConstants {
	// Ports
	const int kShooterMotor = 9;

	// Motor constants
	constexpr double kMaxRpm = 6380;

	// Closed loop control
	const int kTimeoutMs = 30;
	const double kD = 0.0; // Derivative gain
	const double kF = 0.049588; // Feed forward gain
	const double kI = 0.0; // Integral gain
	const double kP = 0.22; // Proportional gain
}

class Shooter : public frc2::SubsystemBase {
	private:
		TalonFX mShooterMotor;

		float mSpeed;
		double mBoostPercent = 1.00;
		bool mIsRunning = false;

		nt::NetworkTableEntry mShuffleboardSpeedTarget;
		nt::NetworkTableEntry mShuffleboardSpeedActual;
		nt::NetworkTableEntry mShuffleboardBoost;
		nt::NetworkTableEntry mShuffleboardRPM;

	public:
		Shooter();

		void setShooter(double speed, bool useRpm);
		void stopShooter();
		double getSpeed(bool useRpm);
		double getActualPercent() {
			return mShooterMotor.GetMotorOutputPercent();
		}
		bool isRunning() {
			return mIsRunning;
		}

		void Periodic() override;
		
		nt::NetworkTableEntry mShuffleboardReady;
};
