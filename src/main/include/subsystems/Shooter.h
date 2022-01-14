#pragma once

#include <frc2/command/SubsystemBase.h>

class Shooter : public frc2::SubsystemBase {
private:
public:
	Shooter();

	void Periodic() override;
};
