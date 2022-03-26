#include "subsystems/Shooter.h"

Shooter::Shooter() {
	SetName("Shooter");
	SetSubsystem("Shooter");

	using namespace ShooterConstants;

	// Shooter motor setup
	mMotor.ConfigFactoryDefault(); // resets all settings
	mMotor.SetInverted(true);
	mMotor.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Coast);
	mMotor.SetSafetyEnabled(false);

	// Sensor
	mMotor.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor, 0, kTimeoutMs);
	mMotor.SetSensorPhase(true);
	mMotor.SetSelectedSensorPosition(0, 0, kTimeoutMs);

	// Peak and nominal outputs
	mMotor.ConfigNominalOutputForward(0, kTimeoutMs);
	mMotor.ConfigNominalOutputReverse(0, kTimeoutMs);
	mMotor.ConfigPeakOutputForward(1, kTimeoutMs);
	mMotor.ConfigPeakOutputReverse(-0.0, kTimeoutMs); // DO NOT run the motor backwards (worst mistake of my life)

	// Voltage compensation
	mMotor.ConfigNeutralDeadband(kDeadband, kTimeoutMs);

	// Closed loop gains
	mMotor.Config_kD(0, kD, kTimeoutMs);
	mMotor.Config_kF(0, kF, kTimeoutMs);
	mMotor.Config_kI(0, kI, kTimeoutMs);
	mMotor.Config_kP(0, kP, kTimeoutMs);
	mMotor.SelectProfileSlot(0, 0);

	stopShooter();

	// Shuffleboard
	wpi::StringMap<std::shared_ptr<nt::Value>> boostSliderProperties = {
		std::make_pair("Min", nt::Value::MakeDouble(0.10)),
		std::make_pair("Max", nt::Value::MakeDouble(1.50)),
		std::make_pair("Block increment", nt::Value::MakeDouble(0.1))
	};

	frc::ShuffleboardLayout& layout = frc::Shuffleboard::GetTab("Drive").GetLayout("Shooter", frc::BuiltInLayouts::kList);

	mShuffleboardReady = layout.Add("Ready?", false).GetEntry();
	mShuffleboardTargetRPM = layout.Add("Target RPM", 0.0).GetEntry();
	mShuffleboardActualRPM = layout.Add("Actual RPM", 0.0).GetEntry();
	mShuffleboardActualPercent = layout.Add("Actual %", 0.0).GetEntry();
	mShuffleboardBoost = layout.AddPersistent("Boost", mBoostPercent)
		.WithWidget(frc::BuiltInWidgets::kNumberSlider)
		.WithProperties(boostSliderProperties)
		.GetEntry();

	mShuffleboardTestRPM = frc::Shuffleboard::GetTab("Test").Add("Set RPM command", 0.0).GetEntry();
}

void Shooter::setShooter(double speed, bool useBoost) {
	if (useBoost) speed = speed * mBoostPercent;

	mMotor.Set(ControlMode::Velocity, rpmToVelocity(speed));

	mTargetSpeed = speed;
}

void Shooter::stopShooter() {
	mTargetSpeed = 0.0;
	mMotor.Set(ControlMode::Velocity, 0.0);
}

void Shooter::setShooterPercent(double speed) {
	mMotor.Set(ControlMode::PercentOutput, speed);
	mTargetSpeed = speed / ShooterConstants::kMaxRpm;
}

void Shooter::Periodic() {
	mActualSpeed = mFlywheelFilter.Calculate(velocityToRpm(mMotor.GetSelectedSensorVelocity(0)));

	mShuffleboardReady.SetBoolean(isRunning() && isAtTargetRPM());
	mShuffleboardActualRPM.SetDouble(mActualSpeed);
	mShuffleboardActualPercent.SetDouble(getActualPercent());
	mBoostPercent = mShuffleboardBoost.GetDouble(mBoostPercent);

	// if (double newTargetSpeed = mShuffleboardTargetRPM.GetDouble(mTargetSpeed) != mTargetSpeed) setShooter(newTargetSpeed);
	mShuffleboardTargetRPM.SetDouble(mTargetSpeed);
}

void Shooter::SimulationPeriodic() {
	TalonFXSimCollection &motorSim(mMotor.GetSimCollection());

	// Set simulation inputs 
	motorSim.SetBusVoltage(frc::RobotController::GetInputVoltage());
	mFlywheelSim.SetInputVoltage(motorSim.GetMotorOutputLeadVoltage() * 1_V);

	// Update simulation, standard loop time is 20ms
	mFlywheelSim.Update(20_ms);

	// Set simulated outputs
	frc::sim::RoboRioSim::SetVInVoltage(
		frc::sim::BatterySim::Calculate({mFlywheelSim.GetCurrentDraw()})
	);
	motorSim.SetIntegratedSensorVelocity(
		rpmToVelocity(mFlywheelSim.GetAngularVelocity())
	);
}