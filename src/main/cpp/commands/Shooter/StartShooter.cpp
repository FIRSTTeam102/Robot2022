#include "commands/Shooter/StartShooter.h"
#include "RobotContainer.h"

StartShooter::StartShooter(Shooter* pShooter, double speed) : mpShooter{pShooter}, mTargetSpeed{speed} {
	SetName("StartShooter");
	AddRequirements(pShooter);
}

// Called just before this Command runs the first time
void StartShooter::Initialize() {
	// Start at the shooter's current speed
	mSpeed = mpShooter->getSpeed();

	// If ramping down, just jump
	if (mSpeed > mTargetSpeed) mpShooter->setShooter(mTargetSpeed);

	printf("Shooting at %f\n", mTargetSpeed);
}

// Called repeatedly when this Command is scheduled to run
void StartShooter::Execute() {
	// Ramp up shooter
	mSpeed += 0.02;
	if (mSpeed > mTargetSpeed) mSpeed = mTargetSpeed;

	mpShooter->setShooter(mSpeed);
}

// Make this return true when this Command no longer needs to run execute()
bool StartShooter::IsFinished() {
	return mSpeed >= mTargetSpeed;
}

// Called once after isFinished returns true
void StartShooter::End(bool interrupted) {
	if (interrupted) mpShooter->setShooter(mTargetSpeed);

	(new RumbleController(RobotContainer::GetInstance()->GetDriverController()))->Schedule();
}