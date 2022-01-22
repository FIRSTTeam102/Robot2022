#include "commands/SwerveDrive/TurnDegreesTimed.h"

TurnDegreesTimed::TurnDegreesTimed(SwerveDrive* pSwerveDrive, double speed, double degrees) : mpSwerveDrive{pSwerveDrive}, mSpeed{speed * 0.2}, mTargetDegrees{degrees}, mCounter{0} {
	// Use addRequirements() here to declare subsystem dependencies.
	AddRequirements(pSwerveDrive);
}

// Called when the command is initially scheduled.
void TurnDegreesTimed::Initialize() {
	double adjTurnSpeed = SwerveDrive::kMaxTurnSpeed * mSpeed;

	double minutesPer360 = SwerveDrive::kRotationsPer360 / adjTurnSpeed;
	double minutesToTarget = minutesPer360 * (mTargetDegrees / 360);

	double ticksToTarget = minutesToTarget * 300;
	mTicks = (int)ticksToTarget;
}

// Called repeatedly when this Command is scheduled to run
void TurnDegreesTimed::Execute() {
	mpSwerveDrive->vectorSwerve(0, 0, mSpeed);
	mCounter++;
}

// Called once the command ends or is interrupted.
void TurnDegreesTimed::End(bool interrupted) {
	mpSwerveDrive->stopDrive();
}

// Returns true when the command should end.
bool TurnDegreesTimed::IsFinished() {
	return mCounter >= mTicks;
}
