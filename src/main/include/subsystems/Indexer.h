#pragma once

#include <ctre/Phoenix.h>
#include <frc/DigitalInput.h>
#include <frc2/command/SubsystemBase.h>

#include "Constants.h"

class Indexer : public frc2::SubsystemBase {
	private:
		TalonSRX mIndexerMotor;
		frc::DigitalInput mBallSwitch;

	public:
		Indexer();
		void Indexer::indexDown() {
			mIndexerMotor.Set(ControlMode::PercentOutput, -IndexerConstants::kMotorSpeed);
		}

		void Indexer::indexUp() {
			mIndexerMotor.Set(ControlMode::PercentOutput, IndexerConstants::kMotorSpeed);
		}

		void Indexer::stopIndexer() {
			mIndexerMotor.Set(ControlMode::PercentOutput, 0.0);
		}

		bool Indexer::getSwitch() {
			return mBallSwitch.Get();
		}

		void Periodic() override;
};
