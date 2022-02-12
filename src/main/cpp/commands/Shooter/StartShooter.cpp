#include "commands/Shooter/StartShooter.h"

StartShooter::StartShooter(Shooter* pShooter, double speed, bool useRpm) : mpShooter{pShooter}, mTargetSpeed{speed}, mUseRpm{useRpm} {
	SetName("StartShooter");
	AddRequirements(pShooter);
}

// Called just before this Command runs the first time
void StartShooter::Initialize() {
	mSpeed = mpShooter->getSpeed(mUseRpm);

	if (!mUseRpm) {
		if (mSpeed < mTargetSpeed) mRamp = 0.2;
		else mRamp = -0.2;
	} else {
		if (mSpeed < mTargetSpeed) mRamp = 100.0;
		else mRamp = -100.0;
	}

	printf("Shooting at %f\n", mTargetSpeed);
}

// Called repeatedly when this Command is scheduled to run
void StartShooter::Execute() {
	// Ramp up shooter
	mSpeed += mRamp;
	if (mSpeed > mTargetSpeed) mSpeed = mTargetSpeed;

	mpShooter->setShooter(mSpeed, mUseRpm);
}

// Make this return true when this Command no longer needs to run execute()
bool StartShooter::IsFinished() {
	return mSpeed >= mTargetSpeed;
}

// Called once after isFinished returns true
void StartShooter::End(bool interrupted) {
	if (interrupted) mpShooter->setShooter(mTargetSpeed, mUseRpm);
}