#include "commands/Shooter/ShootWithRumble.h"
#include "RobotContainer.h"

ShootWithRumble::ShootWithRumble(Shooter* pShooter, double speed) {
	AddCommands(StartShooter(pShooter, speed));
}

ShootWithRumble::ShootWithRumble(Shooter* pShooter, Limelight* pLimelight) {
	AddCommands(StartShooter(pShooter, pLimelight), RumbleController(RobotContainer::GetInstance()->GetDriverController()));
}