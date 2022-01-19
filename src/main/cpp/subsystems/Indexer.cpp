#include "subsystems/Indexer.h"

Indexer::Indexer() : mIndexerMotor{IndexerConstants::kIndexerMotor}, mBallSwitch{IndexerConstants::kBallSwitch} {
	SetName("Indexer");
	SetSubsystem("Indexer");
}

void Indexer::Periodic() {
	// Put code here to be run every loop
}

void Indexer::indexDown() {
	mIndexerMotor.Set(ControlMode::PercentOutput, -IndexerConstants::kMotorSpeed);
}

void Indexer::indexUp() {
	mIndexerMotor.Set(ControlMode::PercentOutput, IndexerConstants::kMotorSpeed);
}

void Indexer::stopIndexer() {
	mIndexerMotor.Set(ControlMode::PercentOutput, 0.0);
}

bool Indexer::getSwitch() {
	return mBallSwitch.Get();
}