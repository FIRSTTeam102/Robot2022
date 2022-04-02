#pragma once

#include <ctre/Phoenix.h>
#include <frc/filter/LinearFilter.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/shuffleboard/ShuffleboardLayout.h>
#include <frc/shuffleboard/ShuffleboardTab.h>
#include <frc/simulation/BatterySim.h>
#include <frc/simulation/FlywheelSim.h>
#include <frc/simulation/RoboRioSim.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/SubsystemBase.h>
#include <networktables/NetworkTableEntry.h>
#include <networktables/NetworkTableValue.h>
#include <units/moment_of_inertia.h>
#include <wpi/StringMap.h>

#include <memory>
#include <utility>

namespace ShooterConstants {
	// Motor constants
	constexpr double kMaxRpm = 6380;
	const double kDeadband = 0.004;
	const double kFlywheelGearRatio = 1 / 1;
	const double kFlywheelCPR = 2048 /* Falcon CPR */ * kFlywheelGearRatio;

	// Closed loop control
	const double kRPMTolerance = 200.0;
	const int kTimeoutMs = 30;
	const double kD = 0.0; // Derivative gain
	const double kF = 0.046503; // Feed forward gain
	const double kI = 0.0; // Integral gain
	const double kP = 0.22; // Proportional gain
}

class Shooter : public frc2::SubsystemBase {
	private:
		WPI_TalonFX mMotor{9}; // include WPILib specific stuff as well as the default Phoenix stuff
		frc::LinearFilter<double> mFlywheelFilter = frc::LinearFilter<double>::SinglePoleIIR(0.1, 0.02_s); // cleans out noise from sensors

		double mTargetSpeed; // in RPM
		double mActualSpeed; // in RPM, calculated in Periodic()
		double mBoostPercent = 1.00;

		nt::NetworkTableEntry mShuffleboardReady;
		nt::NetworkTableEntry mShuffleboardTargetRPM;
		nt::NetworkTableEntry mShuffleboardActualRPM;
		nt::NetworkTableEntry mShuffleboardActualPercent;
		nt::NetworkTableEntry mShuffleboardBoost;

		// Simulation
		frc::DCMotor mSimGearbox = frc::DCMotor::Falcon500(1);
		frc::sim::FlywheelSim mFlywheelSim{mSimGearbox, ShooterConstants::kFlywheelGearRatio, 0.004_kg_sq_m, {0.01}}; // @todo: get real MOI

	public:
		Shooter();

		void setShooter(double speed, bool useBoost = true);
		void stopShooter();
		double getSpeed() {
			return mTargetSpeed;
		}
		double getActualSpeed() {
			return mActualSpeed;
		}

		void setShooterPercent(double speed); // DEPRECATED: use RPM instead
		double getActualPercent() {
			return mMotor.GetMotorOutputPercent();
		}

		bool isRunning() {
			return mTargetSpeed > 0;
		}
		bool isAtTargetRPM() {
			return fabs(mTargetSpeed - mActualSpeed) < ShooterConstants::kRPMTolerance;
		}

		double rpmToVelocity(double rpm) {
			return (ShooterConstants::kFlywheelCPR /* encoder ticks per revolution */ * rpm) / (600.0 /* 100ms per minute */);
		}
		double rpmToVelocity(units::angular_velocity::revolutions_per_minute_t rpm) {
			return rpmToVelocity(units::angular_velocity::revolutions_per_minute_t(rpm).value());
		}
		double velocityToRpm(double velocity) {
			return (600.0 /* 100ms per minute */ * velocity) / (ShooterConstants::kFlywheelCPR /* encoder ticks per revolution */);
		}

		void enableReverse() { // if we ever want to run the shooter backwards (like ejecting balls)
			mMotor.ConfigPeakOutputReverse(-1.0);
		}
		void disableReverse() {
			mMotor.ConfigPeakOutputReverse(0.0);
		}

		void Periodic() override;
		void SimulationPeriodic() override;

		nt::NetworkTableEntry mShuffleboardTestRPM;
};
