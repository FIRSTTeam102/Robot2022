#pragma once

#include <frc2/command/SubsystemBase.h>

class Intake : public frc2::SubsystemBase {
private:
public:
	Intake();

	void Periodic() override;
};
