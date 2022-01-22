#pragma once

#include <frc/Solenoid.h>
#include <frc2/command/SubsystemBase.h>

#include "Constants.h"

class Climber : public frc2::SubsystemBase {
	private:
		frc::Solenoid mClimberSolenoidRight;
		frc::Solenoid mClimberSolenoidLeft;

	public:
		Climber();
		void Periodic() override;
        void armsUp();
        void armsDown();
        void toggleArms();
};