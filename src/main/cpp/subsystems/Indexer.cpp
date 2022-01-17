#include "subsystems/Indexer.h"

#include <frc/smartdashboard/SmartDashboard.h>

#include "Constants.h"

Indexer::Indexer() : mIndexerMotor{IndexerConstants::kIndexerMotor}, mBallSwitch{IndexerConstants::kBallSwitch} {
	SetName("Indexer");
	SetSubsystem("Indexer");
}

void Indexer::Periodic() {
	// Put code here to be run every loop
}