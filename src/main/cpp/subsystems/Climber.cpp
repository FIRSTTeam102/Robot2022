#include "subsystems/Climber.h"

Climber::Climber(frc::XboxController *pController) : mpController{pController} {
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
	// printf("Climber line sensor L%d R%d\n", mLineSensorLeft.Get(), mLineSensorRight.Get());
	// if (frc::Timer::GetMatchTime() < 30_s && frc::DriverStation::IsTeleopEnabled()) {
	// 	if (mLineSensorLeft.Get()) {
	// 		mpController->SetRumble(frc::GenericHID::kLeftRumble, 1);
	// 		mLeftRumbling = true;
	// 	} else if (mLeftRumbling) { // only stop rumbling once
	// 		mpController->SetRumble(frc::GenericHID::kLeftRumble, 0);
	// 		mLeftRumbling = false;
	// 	}

	// 	if (mLineSensorRight.Get()) {
	// 		mpController->SetRumble(frc::GenericHID::kRightRumble, 1);
	// 		mRightRumbling = true;
	// 	} else if (mRightRumbling) { // only stop rumbling once
	// 		mpController->SetRumble(frc::GenericHID::kRightRumble, 0);
	// 		mRightRumbling = false;
	// 	}
	// }
}