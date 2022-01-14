#pragma once

#include <frc/Joystick.h>
#include <frc/XboxController.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc2/command/Command.h>

#include "commands/AutonomousCommand.h"
#include "commands/Climber/Climb.h"
#include "commands/Drive/FlipDrive.h"
#include "commands/Drive/SwerveDrive.h"
#include "commands/Indexer/Backward.h"
#include "commands/Indexer/Forward.h"
#include "commands/Intake/DownYesRoll.h"
#include "commands/Intake/UpNoRoll.h"
#include "commands/Limelight/AimbotSequential.h"
#include "commands/Limelight/SetShootSpeed.h"
#include "commands/Limelight/YawToTarget.h"
#include "commands/Shooter/BallPiston/ExtendRetract.h"
#include "commands/Shooter/ShootSequential.h"
#include "commands/Shooter/StartFlywheel.h"
#include "commands/Shooter/StopFlywheel.h"
#include "commands/Shooter/StopIndexer.h"
#include "subsystems//Climber.h"
#include "subsystems/Drive.h"
#include "subsystems/Indexer.h"
#include "subsystems/Intake.h"
#include "subsystems/Limelight.h"
#include "subsystems/Shooter.h"

class RobotContainer {
public:
	frc2::Command* GetAutonomousCommand();
	static RobotContainer* GetInstance();

	// The robot's subsystems
	Drive mDrive;
	Intake mIntake;
	Indexer mIndexer;
	Shooter mShooter;
	Climber mClimber;
	Limelight mLimelight;

	frc::XboxController* GetDriverController() { return &mDriverController; }

private:
	RobotContainer();

	frc::XboxController mDriverController{0};
	frc2::Button mDriverButtonA{[&] { return mDriverController.GetAButton(); }};
	frc2::Button mDriverButtonB{[&] { return mDriverController.GetBButton(); }};
	frc2::Button mDriverButtonX{[&] { return mDriverController.GetXButton(); }};
	frc2::Button mDriverButtonY{[&] { return mDriverController.GetYButton(); }};
	frc2::Button mDriverButtonLB{[&] { return mDriverController.GetBumper(frc::GenericHID::JoystickHand::kLeftHand); }};
	frc2::Button mDriverButtonRB{[&] { return mDriverController.GetBumper(frc::GenericHID::JoystickHand::kRightHand); }};
	frc2::Button mDriverButtonLMenu{[&] { return mDriverController.GetBackButton(); }};
	frc2::Button mDriverButtonRMenu{[&] { return mDriverController.GetStartButton(); }};
	frc2::Button mDriverLT{[&] { return (mDriverController.GetTriggerAxis(frc::GenericHID::JoystickHand::kLeftHand) > 0.5); }};
	frc2::Button mDriverRT{[&] { return (mDriverController.GetTriggerAxis(frc::GenericHID::JoystickHand::kRightHand) > 0.5); }};
	frc2::Button mDriverUpDPad{[&] { return (mDriverController.GetPOV() == 0); }};
	frc2::Button mDriverLeftDPad{[&] { return (mDriverController.GetPOV() == 90); }};
	frc2::Button mDriverDownDPad{[&] { return (mDriverController.GetPOV() == 180); }};
	frc2::Button mDriverRightDPad{[&] { return (mDriverController.GetPOV() == 270); }};

	frc::XboxController mOperatorController{1};
	frc2::Button mOperatorButtonA{[&] { return mOperatorController.GetAButton(); }};
	frc2::Button mOperatorButtonB{[&] { return mOperatorController.GetBButton(); }};
	frc2::Button mOperatorButtonX{[&] { return mOperatorController.GetXButton(); }};
	frc2::Button mOperatorButtonY{[&] { return mOperatorController.GetYButton(); }};
	frc2::Button mOperatorButtonLB{[&] { return mOperatorController.GetBumper(frc::GenericHID::JoystickHand::kLeftHand); }};
	frc2::Button mOperatorButtonRB{[&] { return mOperatorController.GetBumper(frc::GenericHID::JoystickHand::kRightHand); }};
	frc2::Button mOperatorButtonLMenu{[&] { return mOperatorController.GetBackButton(); }};
	frc2::Button mOperatorButtonRMenu{[&] { return mOperatorController.GetStartButton(); }};
	frc2::Button mOperatorLT{[&] { return mOperatorController.GetTriggerAxis(frc::GenericHID::JoystickHand::kLeftHand) > 0.5; }};
	frc2::Button mOperatorRT{[&] { return mOperatorController.GetTriggerAxis(frc::GenericHID::JoystickHand::kRightHand) > 0.5; }};
	frc2::Button mOperatorUpDPad{[&] { return (mOperatorController.GetPOV() == 0); }};
	frc2::Button mOperatorLeftDPad{[&] { return (mOperatorController.GetPOV() == 90); }};
	frc2::Button mOperatorDownDPad{[&] { return (mOperatorController.GetPOV() == 180); }};
	frc2::Button mOperatorRightDPad{[&] { return (mOperatorController.GetPOV() == 270); }};

	frc::SendableChooser<frc2::Command*> m_chooser;

	AutonomousCommand mAutonomousCommand;
	static RobotContainer* mRobotContainer;

	void ConfigureButtonBindings();
};