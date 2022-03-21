#pragma once

#include <cameraserver/CameraServer.h>
#include <frc/DriverStation.h>
#include <frc/Joystick.h>
#include <frc/XboxController.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/shuffleboard/ShuffleboardLayout.h>
#include <frc/shuffleboard/ShuffleboardTab.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc2/command/Command.h>
#include <frc2/command/ParallelCommandGroup.h>
#include <frc2/command/PrintCommand.h>
#include <frc2/command/SequentialCommandGroup.h>
#include <frc2/command/button/Button.h>

#include "commands/Autonomous/MainAutonomous.h"
#include "commands/Autonomous/OneBallAuto.h"
#include "commands/Climber/Climb.h"
#include "commands/Indexer/Backward.h"
#include "commands/Indexer/Forward.h"
#include "commands/Intake/ArmToggle.h"
#include "commands/Intake/BallIn.h"
#include "commands/Intake/BallOut.h"
#include "commands/Limelight/AimbotParallel.h"
#include "commands/Limelight/YawToTarget.h"
#include "commands/RumbleController.h"
// #include "commands/Shooter/ShootWithRumble.h"
#include "commands/Shooter/StartShooter.h"
#include "commands/Shooter/StopShooter.h"
#include "commands/ShooterHood/IncrementHoodAngle.h"
#include "commands/ShooterHood/SetHoodAngle.h"
#include "commands/SwerveDrive/MoveLinearTimed.h"
#include "commands/SwerveDrive/ResetGyro.h"
#include "commands/SwerveDrive/RunSwerveDrive.h"
#include "commands/SwerveDrive/ToggleDriveMode.h"
#include "commands/SwerveDrive/TurnDegreesGyro.h"
#include "subsystems/Climber.h"
#include "subsystems/Indexer.h"
#include "subsystems/Intake.h"
#include "subsystems/Limelight.h"
#include "subsystems/Shooter.h"
#include "subsystems/ShooterHood.h"
#include "subsystems/SwerveDrive.h"

namespace HardcodedShots {
#ifdef PRACTICE
	constexpr float kTarmacLowerSpeedRPM = 1000;
	constexpr float kTarmacUpperSpeedRPM = 3000;
#else
	constexpr float kTarmacLowerSpeedRPM = 1800; // lower hub
	constexpr float kTarmacUpperSpeedRPM = 5920; // upper hub
#endif

	constexpr float kTarmacLowerSpeedPercent = kTarmacLowerSpeedRPM / ShooterConstants::kMaxRpm;
	constexpr float kTarmacUpperSpeedPercent = kTarmacUpperSpeedRPM / ShooterConstants::kMaxRpm;

	const double kTarmacLowerAngle = 75;
	const double kTarmacUpperAngle = 85;
}

class RobotContainer {
	public:
		frc2::Command* GetAutonomousCommand();
		static RobotContainer* GetInstance();
		void RobotInit();

		frc::XboxController* GetDriverController() { return &mDriverController; }
		frc::XboxController* GetOperatorController() { return &mOperatorController; }

	private:
		RobotContainer();

		cs::UsbCamera mCamera;

		frc::SendableChooser<frc2::Command*> mAutoMode;

		static RobotContainer* mRobotContainer;

		void ConfigureButtonBindings();

		// Subsystems and commands
		SwerveDrive mSwerveDrive{&mDriverController};
		RunSwerveDrive mRunSwerveDrive{&mSwerveDrive};
		ToggleDriveMode mToggleDriveMode{&mSwerveDrive};
		ResetGyro mResetGyro{&mSwerveDrive};

		Intake mIntake;
		BallIn mBallInCommand{&mIntake, &mIndexer};
		BallOut mBallOutCommand{&mIntake, &mIndexer};
		ArmToggle mArmToggleCommand{&mIntake};

		Indexer mIndexer;
		Forward mIndexUpCommand{&mIndexer};
		Backward mIndexDownCommand{&mIndexer};

		Shooter mShooter;
		StopShooter mStopShooterCommand{&mShooter};
		// StartShooter mTarmacLowerSpeed{&mShooter, HardcodedShots::kTarmacLowerSpeedPercent};
		// StartShooter mTarmacUpperSpeed{&mShooter, HardcodedShots::kTarmacUpperSpeedPercent};
		StartShooter mTarmacLowerSpeed{&mShooter, HardcodedShots::kTarmacLowerSpeedRPM, true};
		StartShooter mTarmacUpperSpeed{&mShooter, HardcodedShots::kTarmacUpperSpeedRPM, true};

		ShooterHood mShooterHood;
		IncrementHoodAngle mIncrementHood{2.0, &mShooterHood};
		IncrementHoodAngle mDecrementHood{-2.0, &mShooterHood};
		SetHoodAngle mTarmacLowerAngle{HardcodedShots::kTarmacLowerAngle, &mShooterHood};
		SetHoodAngle mTarmacUpperAngle{HardcodedShots::kTarmacUpperAngle, &mShooterHood};

		frc2::ParallelCommandGroup mTarmacLower{mTarmacLowerSpeed, mTarmacLowerAngle};
		frc2::ParallelCommandGroup mTarmacUpper{mTarmacUpperSpeed, mTarmacUpperAngle};

		Climber mClimber;
		Climb mClimbCommand{&mClimber};

		Limelight mLimelight;
		AimbotParallel mLimelightShooter{&mLimelight, &mShooter, &mShooterHood};
		YawToTarget mYawToTarget{&mLimelight, &mSwerveDrive, &mDriverController};

		// frc2::SequentialCommandGroup mLimelightShooterRumble{mLimelightShooter, RumbleController(&mDriverController)};

		// Controllers
		frc::XboxController mDriverController{0};
		frc2::Button mDriverButtonA{[&] { return mDriverController.GetAButton(); }};
		frc2::Button mDriverButtonB{[&] { return mDriverController.GetBButton(); }};
		frc2::Button mDriverButtonX{[&] { return mDriverController.GetXButton(); }};
		frc2::Button mDriverButtonY{[&] { return mDriverController.GetYButton(); }};
		frc2::Button mDriverButtonLB{[&] { return mDriverController.GetLeftBumper(); }};
		frc2::Button mDriverButtonRB{[&] { return mDriverController.GetRightBumper(); }};
		frc2::Button mDriverButtonLMenu{[&] { return mDriverController.GetBackButton(); }};
		frc2::Button mDriverButtonRMenu{[&] { return mDriverController.GetStartButton(); }};
		frc2::Button mDriverLT{[&] { return (mDriverController.GetLeftTriggerAxis() > 0.5); }};
		frc2::Button mDriverRT{[&] { return (mDriverController.GetRightTriggerAxis() > 0.5); }};
		frc2::Button mDriverButtonLS{[&] { return mDriverController.GetLeftStickButton(); }};
		frc2::Button mDriverButtonRS{[&] { return mDriverController.GetRightStickButton(); }};
		frc2::Button mDriverUpDPad{[&] { return (mDriverController.GetPOV() == 0); }};
		frc2::Button mDriverRightDPad{[&] { return (mDriverController.GetPOV() == 90); }};
		frc2::Button mDriverDownDPad{[&] { return (mDriverController.GetPOV() == 180); }};
		frc2::Button mDriverLeftDPad{[&] { return (mDriverController.GetPOV() == 270); }};

		frc::XboxController mOperatorController{1};
		frc2::Button mOperatorButtonA{[&] { return mOperatorController.GetAButton(); }};
		frc2::Button mOperatorButtonB{[&] { return mOperatorController.GetBButton(); }};
		frc2::Button mOperatorButtonX{[&] { return mOperatorController.GetXButton(); }};
		frc2::Button mOperatorButtonY{[&] { return mOperatorController.GetYButton(); }};
		frc2::Button mOperatorButtonLB{[&] { return mOperatorController.GetLeftBumper(); }};
		frc2::Button mOperatorButtonRB{[&] { return mOperatorController.GetRightBumper(); }};
		frc2::Button mOperatorButtonLMenu{[&] { return mOperatorController.GetBackButton(); }};
		frc2::Button mOperatorButtonRMenu{[&] { return mOperatorController.GetStartButton(); }};
		frc2::Button mOperatorLT{[&] { return mOperatorController.GetLeftTriggerAxis() > 0.5; }};
		frc2::Button mOperatorRT{[&] { return mOperatorController.GetRightTriggerAxis() > 0.5; }};
		frc2::Button mOperatorButtonLS{[&] { return mOperatorController.GetLeftStickButton(); }};
		frc2::Button mOperatorButtonRS{[&] { return mOperatorController.GetRightStickButton(); }};
		frc2::Button mOperatorUpDPad{[&] { return (mOperatorController.GetPOV() == 0); }};
		frc2::Button mOperatorRightDPad{[&] { return (mOperatorController.GetPOV() == 90); }};
		frc2::Button mOperatorDownDPad{[&] { return (mOperatorController.GetPOV() == 180); }};
		frc2::Button mOperatorLeftDPad{[&] { return (mOperatorController.GetPOV() == 270); }};
};
