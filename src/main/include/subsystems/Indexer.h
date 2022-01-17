#pragma once

#include <ctre/Phoenix.h>
#include <frc/DigitalInput.h>
#include <frc2/command/SubsystemBase.h>

class Indexer : public frc2::SubsystemBase {
	private:
		TalonSRX mIndexerMotor;
		frc::DigitalInput mBallSwitch;

	public:
		Indexer();
		void indexDown();
		void indexUp();
		void stopIndexer();
		bool getSwitch();

		void Periodic() override;
};
