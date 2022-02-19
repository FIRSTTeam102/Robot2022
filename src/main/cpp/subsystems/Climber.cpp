#include "subsystems/Climber.h"

#include "RobotContainer.h"

Climber::Climber() : mClimberSolenoidRight{frc::PneumaticsModuleType::REVPH, ClimberConstants::kClimberSolenoidRightUp, ClimberConstants::kClimberSolenoidRightDown}, mClimberSolenoidLeft{frc::PneumaticsModuleType::REVPH, ClimberConstants::kClimberSolenoidLeftUp, ClimberConstants::kClimberSolenoidLeftDown}, mLineSensorLeft{ClimberConstants::kLineSensorLeft}, mLineSensorRight{ClimberConstants::kLineSensorRight}, mRumbleLeft{RobotContainer::GetInstance()->GetDriverController(), 100, true, false}, mRumbleRight{RobotContainer::GetInstance()->GetDriverController(), 100, false, true} {
	SetName("Climber");
	SetSubsystem("Climber");
}

void Climber::armsUp() {
	mClimberSolenoidRight.Set(frc::DoubleSolenoid::kForward);
	mClimberSolenoidLeft.Set(frc::DoubleSolenoid::kForward);
	printf("Climber arms raising\n");
}

void Climber::armsDown() {
	mClimberSolenoidRight.Set(frc::DoubleSolenoid::kReverse);
	mClimberSolenoidLeft.Set(frc::DoubleSolenoid::kReverse);
	printf("Climber arms descending\n");
}

void Climber::toggleArms() {
	mClimberSolenoidRight.Toggle();
	mClimberSolenoidLeft.Toggle();
	printf("Climber arms toggled\n");
}

void Climber::Periodic() {
	// uncomment when tested
	/* if (frc::Timer::GetMatchTime() < 30_s) {
		if (mLineSensorLeft.Get() && !mRumbleLeft.IsScheduled()) {
			mRumbleLeft.Schedule();
		} else if (!mLineSensorLeft.Get() && mRumbleLeft.IsScheduled()) {
			mRumbleLeft.Cancel();
		}

		if (mLineSensorRight.Get() && !mRumbleRight.IsScheduled()) {
			mRumbleRight.Schedule();
		} else if (!mLineSensorRight.Get() && mRumbleRight.IsScheduled()) {
			mRumbleRight.Cancel();
		}
	} */
}