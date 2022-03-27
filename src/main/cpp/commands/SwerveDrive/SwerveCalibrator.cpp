#include "commands/SwerveDrive/SwerveCalibrator.h"

SwerveCalibrator::SwerveCalibrator(SwerveDrive* pSwerveDrive): mpSwerveDrive{pSwerveDrive} {
	AddRequirements(pSwerveDrive);
}

void SwerveCalibrator::Initialize() {
	mpSwerveDrive->setAutoState(true);
	mpSwerveDrive->stopDrive();
	mpSwerveDrive->setCalibration(true);
}

void SwerveCalibrator::Execute() {
	mpSwerveDrive->updateShuffleboardOffsets();
}

void SwerveCalibrator::End(bool interrupted) {
	mpSwerveDrive->setAutoState(false);
	mpSwerveDrive->setCalibration(false);
}

bool SwerveCalibrator::IsFinished() {
	return !frc::DriverStation::IsEnabled();
}
