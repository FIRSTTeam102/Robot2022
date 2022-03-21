#pragma once

#include <ctre/Phoenix.h>
#include <frc/DigitalInput.h>
#include <frc2/command/SubsystemBase.h>

#include "Utilities.h"

namespace IndexerConstants {
	// Ports
	const int kIndexerMotor = 10;
	const int kBallSwitch = 5;

	// Speeds
	const double kMotorSpeed = 0.95;
}

class Indexer : public frc2::SubsystemBase {
	private:
		TalonSRX mIndexerMotor;
		frc::DigitalInput mBallSwitch;
		MotorDirection mState = MotorDirection::kOff;

	public:
		Indexer();

		void indexDown();
		void indexUp();
		void stopIndexer();
		bool getSwitch();
		MotorDirection getMotorDirection() { return mState; }

		void Periodic() override;
};
