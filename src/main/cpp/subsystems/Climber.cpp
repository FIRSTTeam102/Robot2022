#include "subsystems/Climber.h"

Climber::Climber(frc::XboxController *pController) : mpController{pController} {
	SetName("Climber");
	SetSubsystem("Climber");

	wpi::StringMap<std::shared_ptr<nt::Value>> sensorGridProperties = {
		std::make_pair("Number of columns", nt::Value::MakeDouble(2)),
		std::make_pair("Number of rows", nt::Value::MakeDouble(1))
	};

	frc::ShuffleboardLayout& sensorGrid = frc::Shuffleboard::GetTab("Drive")
		.GetLayout("Climb sensors", frc::BuiltInLayouts::kGrid)
			.WithProperties(sensorGridProperties);

	mShuffleboardSensorLeft = sensorGrid.Add("Left", false).GetEntry();
	mShuffleboardSensorRight = sensorGrid.Add("Right", false).GetEntry();
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
	// Automatically pull up climber just before match ends
	// if (
	// 	frc::DriverStation::IsTeleop() // in teleop
	// 	&& frc::DriverStation::IsFMSAttached() // a real competition
	// 	&& frc::DriverStation::GetMatchType() != frc::DriverStation::MatchType::kNone
	// 	&& frc::Timer::GetMatchTime() < 500_ms // less than 0.5 seconds left in the match
	// ) {
	// 	printf("Automatically pulling up climber\n");
	// 	armsDown();
	// }

	// printf("Climber line sensor L%d R%d\n", mLineSensorLeft.Get(), mLineSensorRight.Get());
	if (
		frc::DriverStation::IsTeleopEnabled()
		&& frc::DriverStation::GetMatchType() != frc::DriverStation::MatchType::kNone
		&& frc::Timer::GetMatchTime() < 30_s
	) {
		if (mLineSensorLeft.Get()) {
			mpController->SetRumble(frc::GenericHID::kLeftRumble, 1);
			mLeftRumbling = true;
		} else if (mLeftRumbling) { // only stop rumbling once
			mpController->SetRumble(frc::GenericHID::kLeftRumble, 0);
			mLeftRumbling = false;
		}

		if (mLineSensorRight.Get()) {
			mpController->SetRumble(frc::GenericHID::kRightRumble, 1);
			mRightRumbling = true;
		} else if (mRightRumbling) { // only stop rumbling once
			mpController->SetRumble(frc::GenericHID::kRightRumble, 0);
			mRightRumbling = false;
		}
	}

	mShuffleboardSensorLeft.SetBoolean(mLineSensorLeft.Get());
	mShuffleboardSensorRight.SetBoolean(mLineSensorRight.Get());
}