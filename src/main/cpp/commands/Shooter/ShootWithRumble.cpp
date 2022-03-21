#include "commands/Shooter/ShootWithRumble.h"
#include "RobotContainer.h"

ShootWithRumble::ShootWithRumble(Shooter* pShooter, double speed, bool useRpm) {
	AddCommands(StartShooter(pShooter, speed, useRpm));
}

ShootWithRumble::ShootWithRumble(Shooter* pShooter, Limelight* pLimelight, bool useRpm) {
	AddCommands(StartShooter(pShooter, pLimelight, useRpm), RumbleController(RobotContainer::GetInstance()->GetDriverController()));
}