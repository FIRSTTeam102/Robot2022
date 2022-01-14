#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>

class AimbotSequential : public frc2::CommandHelper<frc2::SequentialCommandGroup, AimbotSequential> {
public:
	explicit AimbotSequential();

private:
};
