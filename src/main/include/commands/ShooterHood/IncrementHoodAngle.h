#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include <subsystems/ShooterHood.h>

class IncrementHoodAngle : public frc2::CommandHelper<frc2::CommandBase, IncrementHoodAngle> {
	public:
		IncrementHoodAngle(double degrees, ShooterHood* pShooterHood);

		void Initialize() override;

		void Execute() override;

		void End(bool interrupted) override;

		bool IsFinished() override;

	private:
		double mDegreeChange;
		ShooterHood* mpShooterHood;
};
