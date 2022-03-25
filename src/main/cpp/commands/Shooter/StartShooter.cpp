#include "commands/Shooter/StartShooter.h"

// #define RAMP

// Create StartShooter with a hardcoded speed value
StartShooter::StartShooter(Shooter* pShooter, double speed) : mpShooter{pShooter}, mpLimelight{NULL}, mTargetSpeed{speed} {
	SetName("StartShooter");
	AddRequirements(pShooter);
}

// Create StartShooter using the Limelight to determine the speed
StartShooter::StartShooter(Shooter* pShooter, Limelight* pLimelight) : mpShooter{pShooter}, mpLimelight{pLimelight}, mTargetSpeed{0} {
	SetName("StartShooter");
	AddRequirements(pShooter);
}

// Called just before this Command runs the first time
void StartShooter::Initialize() {
	if (mpLimelight) mTargetSpeed = mpLimelight->getShootSpeed();
#ifdef RAMP
	mSpeed = mpShooter->getSpeed();

	if (mSpeed == mTargetSpeed) End(true);

	if (mSpeed <= mTargetSpeed) mRamp = 500.0;
	else mRamp = -500.0;
#else
	mpShooter->setShooter(mTargetSpeed);
#endif

	printf("Shooting at %f\n", mTargetSpeed);
}

// Called repeatedly when this Command is scheduled to run
void StartShooter::Execute() {
#ifdef RAMP
	// Ramp up shooter
	mSpeed += mRamp;
	if (mSpeed > mTargetSpeed) mSpeed = mTargetSpeed;

	mpShooter->setShooter(mSpeed);
#endif
}

// Make this return true when this Command no longer needs to run execute()
bool StartShooter::IsFinished() {
	// return mSpeed >= mTargetSpeed;
	return mpShooter->isAtTargetRPM();
}

// Called once after isFinished returns true
void StartShooter::End(bool interrupted) {
	if (interrupted || mpShooter->getActualPercent() < -0.1) mpShooter->setShooter(mTargetSpeed);
}