#pragma once

#include <frc/DigitalInput.h>
#include <frc/DoubleSolenoid.h>
#include <frc2/command/SubsystemBase.h>

#include "commands/RumbleController.h"
#include "Constants.h"

class Climber : public frc2::SubsystemBase {
	public:
		Climber();
		void Periodic() override;
		void armsUp();
		void armsDown();
		void toggleArms();

	private:
		frc::DoubleSolenoid mClimberSolenoidRight;
		frc::DoubleSolenoid mClimberSolenoidLeft;

		frc::DigitalInput mLineSensorLeft;
		frc::DigitalInput mLineSensorRight;

		RumbleController mRumbleLeft;
		RumbleController mRumbleRight;
};