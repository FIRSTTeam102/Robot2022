#pragma once

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

namespace SwerveDriveConstants {
// Motor ports
const int kFLDrive = 8;
const int kFLTurn = 1;
const int kFRDrive = 9;
const int kFRTurn = 3;
const int kBRDrive = 7;
const int kBRTurn = 6;
const int kBLDrive = 5;
const int kBLTurn = 4;

// Encoder Ports
const int kFLEnc = 2;
const int kFREnc = 3;
const int kBREnc = 1;
const int kBLEnc = 0;

// Calibration Values
const int kFLOffset = 2618;
const int kFROffset = 3603;
const int kBROffset = 44;
const int kBLOffset = 3466;

const double kMaxSpeed = 1;
} // namespace SwerveDriveConstants