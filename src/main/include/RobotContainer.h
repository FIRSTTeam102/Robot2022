#pragma once

#include <frc/DriverStation.h>
#include <frc/Joystick.h>
#include <frc/XboxController.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/shuffleboard/ShuffleboardLayout.h>
#include <frc/shuffleboard/ShuffleboardTab.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/Command.h>
#include <frc2/command/ParallelRaceGroup.h>
#include <frc2/command/button/Button.h>

#include "commands/Autonomous/MainAutonomous.h"
#include "commands/Climber/Climb.h"
#include "commands/Indexer/Backward.h"
#include "commands/Indexer/Forward.h"
#include "commands/Intake/ArmToggle.h"
#include "commands/Intake/BallIn.h"
#include "commands/Intake/BallOut.h"
#include "commands/Limelight/AimbotSequential.h"
#include "commands/Limelight/SetShootSpeed.h"
#include "commands/Limelight/YawToTarget.h"
#include "commands/RumbleController.h"
#include "commands/Shooter/StartShooter.h"
#include "commands/Shooter/StopShooter.h"
#include "commands/ShooterHood/SetHoodAngle.h"
#include "commands/SwerveDrive/FlipDrive.h"
#include "commands/SwerveDrive/MoveLinearTimed.h"
#include "commands/SwerveDrive/ResetGyro.h"
#include "commands/SwerveDrive/RunSwerveDrive.h"
#include "commands/SwerveDrive/TurnDegreesGyro.h"
#include "subsystems/Climber.h"
#include "subsystems/Indexer.h"
#include "subsystems/Intake.h"
#include "subsystems/Limelight.h"
#include "subsystems/Shooter.h"
#include "subsystems/ShooterHood.h"
#include "subsystems/SwerveDrive.h"

class RobotContainer {
	public:
		frc2::Command* GetAutonomousCommand();
		static RobotContainer* GetInstance();
		void RobotInit();

		frc::XboxController* GetDriverController() { return &mDriverController; }
		frc::XboxController* GetOperatorController() { return &mOperatorController; }

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

		frc::SendableChooser<frc2::Command*> mChooser;

		// AutonomousCommand mAutonomousCommand;
		static RobotContainer* mRobotContainer;

		void ConfigureButtonBindings();

		// Subsystems and commands
		SwerveDrive mSwerveDrive{&mDriverController};
		RunSwerveDrive mRunSwerveDrive{&mSwerveDrive};
		FlipDrive mFlipOrientation{&mSwerveDrive};
		ResetGyro mResetGyro{&mSwerveDrive};

		Intake mIntake;
		BallIn mBallInCommand{&mIntake, &mIndexer};
		BallOut mBallOutCommand{&mIntake, &mIndexer};
		ArmToggle mArmToggleCommand{&mIntake};

		Indexer mIndexer;
		Forward mIndexUpCommand{&mIndexer};
		Backward mIndexDownCommand{&mIndexer};

		Shooter mShooter;
		SetHoodAngle mActuatorUp{35, &mShooter};
		SetHoodAngle mActuatorMid{6, &mShooter};
		SetHoodAngle mActuatorDown{-8, &mShooter};
		StartShooter mSlowShooterCommand{&mShooter, ShooterConstants::kSlowSpeed};
		StartShooter mMedShooterCommand{&mShooter, ShooterConstants::kMedSpeed};
		StartShooter mFastShooterCommand{&mShooter, ShooterConstants::kFastSpeed};
		StopShooter mStopShooterCommand{&mShooter};

		ShooterHood mShooterHood;
		SetHoodAngle mActuatorUp{26, &mShooterHood};
		SetHoodAngle mActuatorMid{15, &mShooterHood};
		SetHoodAngle mActuatorDown{-4, &mShooterHood};

		Climber mClimber{&mDriverController};
		Climb mClimbCommand{&mClimber};

		Limelight mLimelight;
};
