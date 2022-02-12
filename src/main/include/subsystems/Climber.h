#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/DoubleSolenoid.h>

#include "Constants.h"

class Climber : public frc2::SubsystemBase {
	private:
		frc::DoubleSolenoid mClimberSolenoidRight;
		frc::DoubleSolenoid mClimberSolenoidLeft;

	public:
		Climber();
		void Periodic() override;
        void armsUp();
        void armsDown();
        void toggleArms();
};