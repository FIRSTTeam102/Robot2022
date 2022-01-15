#include "subsystems/Intake.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include "RobotContainer.h"
#include "Constants.h"

Intake::Intake(): 
    mIntakeArmMotor{IntakeConstants::kIntakeArmMotor, frc::Relay::kBothDirections},
    mIntakeRollerMotor{IntakeConstants::kIntakeRollerMotor}
{
    SetName("Intake");
    SetSubsystem("Intake");
}

//lower the intake arm - start the arm motor
void Intake::lowerIntakeArm() {
    printf("Deploying intake\n");
    mIntakeArmMotor.Set(frc::Relay::kReverse);
    // printf("Is arm down - %d\n", isArmDown());
}
//raise the intake arm -  start the arm motor
void Intake::raiseIntakeArm() {
    printf("Retracting intake\n");
    mIntakeArmMotor.Set(frc::Relay::kForward);
}
//stopIntakeArm - stop the intake arm motor by shutting it off
void Intake::stopIntakeArm() {
    mIntakeArmMotor.Set(frc::Relay::kOff);
}
//startRollers - start the intake arms rollers, to capture power cells
void Intake::startRollers() {
    printf("Rollers should be moving\n");
    mIntakeRollerMotor.Set(-IntakeConstants::kIntakeRollerSpeed);
    printf("Status: %d\n", mIntakeRollerMotor.IsAlive());
}
//startReversRollers - start the intake arm rollers in reverse - this is to
//  spit out power cells in the event the power cell intake needs to be
//  cleared
void Intake::startReverseRollers(){
    mIntakeRollerMotor.Set(IntakeConstants::kIntakeRollerSpeed);
}
//stopRollers - stop the intake arm roller motors from running
void Intake::stopRollers() {
    mIntakeRollerMotor.Set(0);
}

void Intake::Periodic() {
    // Put code here to be run every loop

}