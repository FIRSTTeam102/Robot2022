#include "commands/SwerveDrive/AutonomousLikeAController.h"

AutonomousLikeAController::AutonomousLikeAController(SwerveDrive* pSwerveDrive, double leftX, double leftY, double rightX, units::second_t time) :
mpSwerveDrive{pSwerveDrive}, mLeftX{leftX}, mLeftY{leftY}, mRightX{rightX}, mTime{time} {
	AddRequirements(pSwerveDrive);
}

void AutonomousLikeAController::Initialize() {
	mTimer.Start();
	mpSwerveDrive->setAutoState(true);
}

void AutonomousLikeAController::Execute() {
	mpSwerveDrive->vectorSwerve(mLeftX, mLeftY, mRightX);
}

void AutonomousLikeAController::End(bool interrupted) {
	mTimer.Stop();
	mpSwerveDrive->stopDrive();
	mpSwerveDrive->setAutoState(false);
}

bool AutonomousLikeAController::IsFinished() {
	return mTimer.AdvanceIfElapsed(mTime);
}
