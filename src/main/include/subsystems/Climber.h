#pragma once

#include <frc/Solenoid.h>
#include <frc2/command/SubsystemBase.h>

class Climber : public frc2::SubsystemBase {
	private:
		frc::Solenoid mClimberSolenoid;

	public:
		Climber();
		void armUp();
		void armDown();
		void Periodic() override;
		void armToggle();
};