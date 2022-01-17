#pragma once

#include <frc/Solenoid.h>
#include <frc2/command/SubsystemBase.h>

class Climber : public frc2::SubsystemBase {
	private:
		frc::Solenoid mClimberSolenoid;

	public:
		Climber();
		void Periodic() override;
		void armUp();
		void armDown();
		void toggleArm();
};