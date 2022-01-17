#include "subsystems/Indexer.h"

Indexer::Indexer() : mIndexerMotor{IndexerConstants::kIndexerMotor}, mBallSwitch{IndexerConstants::kBallSwitch} {
	SetName("Indexer");
	SetSubsystem("Indexer");
}

void Indexer::Periodic() {
	// Put code here to be run every loop
}