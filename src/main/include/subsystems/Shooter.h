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

		double mSpeed; // in RPM
		double mBoostPercent = 1.00;

		nt::NetworkTableEntry mShuffleboardTargetRPM;
		nt::NetworkTableEntry mShuffleboardActualRPM;
		nt::NetworkTableEntry mShuffleboardActualPercent;
		nt::NetworkTableEntry mShuffleboardBoost;

	public:
		Shooter();

		void setShooter(double speed, bool useBoost = true);
		void stopShooter();
		double getSpeed() {
			return mSpeed;
		}
		double getActualSpeed() {
			return velocityToRpm(mShooterMotor.GetSelectedSensorVelocity(0));
		}

		void setShooterPercent(double speed); // DEPRECATED: use RPM instead
		double getActualPercent() {
			return mShooterMotor.GetMotorOutputPercent();
		}

		bool isRunning() {
			return mSpeed > 0;
		}

		double rpmToVelocity(double rpm) {
			return (2048.0 /* encoder ticks per revolution */ * rpm) / (600.0 /* 100ms per minute */);
		};
		double velocityToRpm(double velocity) {
			return (600.0 /* 100ms per minute */ * velocity) / (2048.0 /* encoder ticks per revolution */);
		};

		void Periodic() override;
		
		nt::NetworkTableEntry mShuffleboardReady;
};
