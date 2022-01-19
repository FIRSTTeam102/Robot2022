#include "commands/Limelight/SetShootSpeed.h"

SetShootSpeed::SetShootSpeed(ShootSequential *pShootSequential, Limelight *pLimelight) : mpShootSequential{pShootSequential}, mpLimelight{pLimelight} {
	SetName("SetShootSpeed");
	AddRequirements(mpShootSequential);
}

// Called just before this Command runs the first time
void SetShootSpeed::Initialize() {
	rampUpSpeed = 0;
	printf("Limelight Hood Adjusting\n");
	if (mpLimelight->isClose()) {
		mpShootSequential->retrServo();
	}
	else {
		mpShootSequential->extServo();
	}
}

// Called repeatedly when this Command is scheduled to run
void SetShootSpeed::Execute() {
	rampUpSpeed += 0.02;
	mpShootSequential->setSpeed(rampUpSpeed * mpLimelight->getShootSpeed());
	mpShootSequential->startMotor();
	printf("Ramp Up Percent: %f\n", rampUpSpeed * mpLimelight->getShootSpeed());
}

// Make this return true when this Command no longer needs to run execute()
bool SetShootSpeed::IsFinished() {
	return (rampUpSpeed >= 1);
}

// Called once after isFinished returns true
void SetShootSpeed::End(bool interrupted) {
	if (interrupted) {
		mpShootSequential->setSpeed(mpLimelight->getShootSpeed());
		mpShootSequential->startMotor();
	}
}