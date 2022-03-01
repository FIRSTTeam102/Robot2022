#pragma once

#include <ctre/Phoenix.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/shuffleboard/ShuffleboardLayout.h>
#include <frc/shuffleboard/ShuffleboardTab.h>
#include <frc2/command/SubsystemBase.h>
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

		static wpi::StringMap<std::shared_ptr<nt::Value>> kNumberSliderProperties{
			std::make_pair("Min", nt::Value::MakeString("0.5")),
			std::make_pair("Max", nt::Value::MakeString("2.0")),
			std::make_pair("Block increment", nt::Value::MakeString("0.1"))
		};


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
