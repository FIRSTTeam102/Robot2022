#include "commands/SwerveDrive/SetAnglesCommand.h"

SetAnglesCommand::SetAnglesCommand(SwerveDrive* pSwerveDrive, double angle): mpSwerveDrive{pSwerveDrive}, mAngle{angle} {
	AddRequirements(pSwerveDrive);
}

// Called when the command is initially scheduled.
void SetAnglesCommand::Initialize() {
	mpSwerveDrive->setAngles(mAngle);
}
