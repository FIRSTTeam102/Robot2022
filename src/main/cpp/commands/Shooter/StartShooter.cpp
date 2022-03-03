#include "commands/Shooter/StartShooter.h"
#include "RobotContainer.h"

StartShooter::StartShooter(Shooter* pShooter, Limelight* pLimelight, SpeedSettings speedType, bool useRpm) : 
    mpShooter{pShooter}, mpLimelight(pLimelight),
    mUseSpeed{speedType}, mUseRpm{useRpm} {
	SetName("StartShooter");
	AddRequirements(pShooter);

	switch (mUseSpeed){
		case SpeedSettings::SLOW:
		   mTargetSpeed = ShooterConstants::kRPMSlowSpeed;
		   break;
	    case SpeedSettings::MED:
		   mTargetSpeed = ShooterConstants::kRPMMedSpeed;
		   break;
	    case SpeedSettings::FAST:
		   mTargetSpeed = ShooterConstants::kRPMFastSpeed;
		   break;
	    case SpeedSettings::LMDET:
		   mTargetSpeed = 0;
		break;
		default:
		   mTargetSpeed = 0;
	}


}

// Called just before this Command runs the first time
void StartShooter::Initialize() {

	if (mUseSpeed == SpeedSettings::LMDET){
        mTargetSpeed = mpLimelight->getShootSpeed();
	}
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