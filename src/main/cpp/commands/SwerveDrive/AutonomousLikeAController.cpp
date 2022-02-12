#include "commands/SwerveDrive/AutonomousLikeAController.h"

AutonomousLikeAController::AutonomousLikeAController(SwerveDrive* pSwerveDrive, double leftX, double leftY, double rightX, double time):
	mpSwerveDrive{pSwerveDrive}, mLeftX{leftX}, mLeftY{leftY}, mRightX{rightX}, mTicks{(int) (time * 50.0)}
{
	// Use addRequirements() here to declare subsystem dependencies.
	mCounter = 0;
	AddRequirements(pSwerveDrive);
}

// Called when the command is initially scheduled.
void AutonomousLikeAController::Initialize() {
	mpSwerveDrive->setAutoState(true);
}

// Called repeatedly when this Command is scheduled to run
void AutonomousLikeAController::Execute() {
	mpSwerveDrive->vectorSwerve(mLeftX, mLeftY, mRightX);
	mCounter++;
}

// Called once the command ends or is interrupted.
void AutonomousLikeAController::End(bool interrupted) {
	mpSwerveDrive->stopDrive();
	mpSwerveDrive->setAutoState(false);
}

// Returns true when the command should end.
bool AutonomousLikeAController::IsFinished() {
	return (mCounter >= mTicks);
}
