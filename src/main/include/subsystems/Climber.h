#pragma once

#include <frc2/command/SubsystemBase.h>

class Climber: public frc2::SubsystemBase {
private:
public:
Climber();

    void Periodic() override;
};

