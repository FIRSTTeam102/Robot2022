#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include <subsystems/ShooterHood.h>

class SetHoodAngle : public frc2::CommandHelper<frc2::CommandBase, SetHoodAngle> {
	public:
		SetHoodAngle(double degrees, ShooterHood* pShooterHood);

		void Initialize() override;

		void Execute() override;

		void End(bool interrupted) override;

		bool IsFinished() override;

	private:
		double mDegrees;
		ShooterHood* mpShooterHood;
};
