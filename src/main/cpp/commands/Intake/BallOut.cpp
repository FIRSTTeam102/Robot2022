// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Intake/BallOut.h"

BallOut::BallOut(Intake* pIntake, Indexer* pIndexer): mpIntake{pIntake}, mpIndexer{pIndexer} {
	// Use addRequirements() here to declare subsystem dependencies.
	AddRequirements(pIntake);
	AddRequirements(pIndexer);
}

// Called when the command is initially scheduled.
void BallOut::Initialize() {
	if (!mpIndexer->mLock) {
		mpIntake->lowerIntakeArm();
		mpIntake->startReverseRollers();
		mpIndexer->indexDown();
	}
}

// Called repeatedly when this Command is scheduled to run
void BallOut::Execute() {}

// Called once the command ends or is interrupted.
void BallOut::End(bool interrupted) {
	if (!mpIndexer->mLock) {
		mpIntake->raiseIntakeArm();
		mpIntake->stopRollers();
		mpIndexer->stopIndexer();
	}
}

// Returns true when the command should end.
bool BallOut::IsFinished() {
	return mpIndexer->mLock; // true if it should just quit
}
