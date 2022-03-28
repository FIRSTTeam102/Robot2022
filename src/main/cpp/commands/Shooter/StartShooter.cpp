#include "commands/Shooter/StartShooter.h"

#include "RobotContainer.h"

// #define RAMP

// Create StartShooter with a hardcoded speed value
StartShooter::StartShooter(Shooter* pShooter, double speed) :
mpShooter{pShooter}, mpLimelight{NULL}, mTargetSpeed{speed}, mpNTEntry{NULL} {
	SetName("StartShooter");
	AddRequirements(pShooter);
}

// Create StartShooter using the Limelight to determine the speed
StartShooter::StartShooter(Shooter* pShooter, Limelight* pLimelight) :
mpShooter{pShooter}, mpLimelight{pLimelight}, mTargetSpeed{0}, mpNTEntry{NULL} {
	SetName("StartShooter");
	AddRequirements(pShooter);
}

StartShooter::StartShooter(Shooter* pShooter, nt::NetworkTableEntry* pNTEntry) :
mpShooter{pShooter}, mpLimelight{NULL}, mTargetSpeed{0}, mpNTEntry{pNTEntry} {
	SetName("StartShooter");
	AddRequirements(pShooter);
}

// Called just before this Command runs the first time
void StartShooter::Initialize() {
	if (mpLimelight) mTargetSpeed = mpLimelight->getShootSpeed();
	else if (mpNTEntry) mTargetSpeed = mpNTEntry->GetDouble(0.0);
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
	printf("Shooter spinning up to %f, currently at %f\n", mTargetSpeed, mpShooter->getActualSpeed());
}

// Make this return true when this Command no longer needs to run execute()
bool StartShooter::IsFinished() {
	// return mSpeed >= mTargetSpeed;
	return mpShooter->isAtTargetRPM();
}

// Called once after isFinished returns true
void StartShooter::End(bool interrupted) {
	if (interrupted || mpShooter->getActualPercent() < -0.1) mpShooter->setShooter(mTargetSpeed);

	// Rumble test
	/* RobotContainer::GetInstance()->setDriverRumble(0.25);
	frc::Wait(250_ms);
	RobotContainer::GetInstance()->setDriverRumble(0); */
}