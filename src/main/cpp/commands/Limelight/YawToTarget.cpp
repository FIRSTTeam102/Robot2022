#include "commands/Limelight/YawToTarget.h"

YawToTarget::YawToTarget(Limelight *pLimelight, SwerveDrive *pSwerveDrive) : mpLimelight(pLimelight), mpSwerveDrive(pSwerveDrive) {
	SetName("YawToTarget");
	AddRequirements(pSwerveDrive);
}

// Called just before this Command runs the first time
void YawToTarget::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void YawToTarget::Execute() {
	printf("Limelight Move Adjusting \n");
	mpSwerveDrive->move(mpLimelight->left_command, mpLimelight->right_command);
}

// Make this return true when this Command no longer needs to run execute()
bool YawToTarget::IsFinished() {
	return Check();
}

// Called once after isFinished returns true
void YawToTarget::End(bool interrupted) {
	mpSwerveDrive->stop();
}
