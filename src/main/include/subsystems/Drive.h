#pragma once

#include <frc2/command/SubsystemBase.h>

class Drive : public frc2::SubsystemBase {
private:
public:
	Drive();

	void Periodic() override;
};
