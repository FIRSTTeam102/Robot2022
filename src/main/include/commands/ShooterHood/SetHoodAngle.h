#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include <subsystems/Limelight.h>
#include <subsystems/ShooterHood.h>

class SetHoodAngle : public frc2::CommandHelper<frc2::CommandBase, SetHoodAngle> {
	public:
		SetHoodAngle(double degrees, ShooterHood* pShooterHood);
		SetHoodAngle(ShooterHood* pShooterHood, Limelight* pLimelight);

		void Initialize() override;

		void Execute() override;

		void End(bool interrupted) override;

		bool IsFinished() override;
	private:
		double mSetting;
		double mDegrees;
		ShooterHood* mpShooterHood;
		Limelight* mpLimelight;
};
