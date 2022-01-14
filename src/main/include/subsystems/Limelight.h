#pragma once

#include <frc2/command/SubsystemBase.h>

class Limelight : public frc2::SubsystemBase {
private:
public:
	Limelight();

	void Periodic() override;
};
