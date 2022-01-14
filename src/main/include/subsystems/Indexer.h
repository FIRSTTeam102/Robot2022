#pragma once

#include <frc2/command/SubsystemBase.h>

class Indexer : public frc2::SubsystemBase {
private:
public:
	Indexer();

	void Periodic() override;
};
