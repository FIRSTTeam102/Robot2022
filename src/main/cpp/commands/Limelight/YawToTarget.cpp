#include "commands/Limelight/YawToTarget.h"


YawToTarget::YawToTarget(Limelight *pLimelight, SwerveDrive *pSwerveDrive) : mpLimelight(pLimelight), mpSwerveDrive(pSwerveDrive) {
	SetName("YawToTarget");
	AddRequirements(pSwerveDrive);
}

// Called just before this Command runs the first time
void YawToTarget::Initialize() {
	Lights::GetInstance()->setMode(Lights::kLimelight);
}

// Called repeatedly when this Command is scheduled to run
void YawToTarget::Execute() {
	// printf("Limelight Rotation Adjusting \n");
	mpSwerveDrive->vectorSwerve(0.0, 0.0, mpLimelight->getRotation());
}

// Make this return true when this Command no longer needs to run execute()
bool YawToTarget::IsFinished() {
	return false;
	// return mpLimelight->Check();
}

// Called once after isFinished returns true
void YawToTarget::End(bool interrupted) {
	Lights::GetInstance()->setMode(Lights::kDefault);
}
