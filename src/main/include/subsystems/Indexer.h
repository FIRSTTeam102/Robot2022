#pragma once

#include <ctre/Phoenix.h>
#include <frc/DigitalInput.h>
#include <frc2/command/SubsystemBase.h>

#include "Constants.h"

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
