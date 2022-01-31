#pragma once

#include <frc/Joystick.h>
#include <frc/XboxController.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc2/command/Command.h>
#include <frc2/command/button/Button.h>

#include "commands/AutonomousCommand.h"
#include "commands/Climber/Climb.h"
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
#include "commands/SwerveDrive/FlipDrive.h"
#include "commands/SwerveDrive/RunSwerveDrive.h"
#include "commands/SwerveDrive/ResetGyro.h"
#include "commands/SwerveDrive/TurnDegreesGyro.h"
#include "commands/SwerveDrive/MoveLinearTimed.h"
#include "subsystems/Climber.h"
#include "subsystems/Indexer.h"
#include "subsystems/Intake.h"
#include "subsystems/Limelight.h"
#include "subsystems/Shooter.h"
#include "subsystems/SwerveDrive.h"

class RobotContainer {
	public:
		frc2::Command* GetAutonomousCommand();
		static RobotContainer* GetInstance();

		frc::XboxController* GetDriverController() { return &mDriverController; }

	private:
		RobotContainer();

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
		frc2::Button mDriverUpDPad{[&] { return (mDriverController.GetPOV() == 0); }};
		frc2::Button mDriverLeftDPad{[&] { return (mDriverController.GetPOV() == 90); }};
		frc2::Button mDriverDownDPad{[&] { return (mDriverController.GetPOV() == 180); }};
		frc2::Button mDriverRightDPad{[&] { return (mDriverController.GetPOV() == 270); }};

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
		frc2::Button mOperatorUpDPad{[&] { return (mOperatorController.GetPOV() == 0); }};
		frc2::Button mOperatorLeftDPad{[&] { return (mOperatorController.GetPOV() == 90); }};
		frc2::Button mOperatorDownDPad{[&] { return (mOperatorController.GetPOV() == 180); }};
		frc2::Button mOperatorRightDPad{[&] { return (mOperatorController.GetPOV() == 270); }};

		frc::SendableChooser<frc2::Command*> mChooser;

		AutonomousCommand mAutonomousCommand;
		static RobotContainer* mRobotContainer;

		void ConfigureButtonBindings();

		// Subsystems and commands
		SwerveDrive mSwerveDrive;
		RunSwerveDrive mRunSwerveDrive{&mSwerveDrive};
		FlipDrive mFlipOrientation{&mSwerveDrive};
		ResetGyro mResetGyro{&mSwerveDrive};

		TurnDegreesGyro mQuarterTurn{&mSwerveDrive, 0.8, 90};
		TurnDegreesGyro mInvertedQuarterTurn{&mSwerveDrive, 0.8, -90};
		TurnDegreesGyro mHalfTurn{&mSwerveDrive, 0.8, 180};
		TurnDegreesGyro mInvertedHalfTurn{&mSwerveDrive, 0.8, -180};
		TurnDegreesGyro mFullTurn{&mSwerveDrive, 0.8, 360};
		TurnDegreesGyro mInvertedFullTurn{&mSwerveDrive, 0.8, -360};
		TurnDegreesGyro mFunnyTurn{&mSwerveDrive, -0.8, -90};

		MoveLinearTimed mForward{&mSwerveDrive, 0.6, 0.5};
		MoveLinearTimed mBackward{&mSwerveDrive, -0.6, 0.5};

		Intake mIntake;

		Indexer mIndexer;

		Shooter mShooter;

		Climber mClimber;

		Limelight mLimelight;
};