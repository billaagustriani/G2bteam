void setup_pid(){
   yawSetpoint = 226.80; //Dalam Derajat
  yawPID.SetMode(AUTOMATIC);
  yawPID.SetTunings(Kp, Ki, Kd);
  yawPID.SetOutputLimits(-150, 150); //batas pwm motor
  yawPID.SetSampleTime(10); //sampling waktu
  // PID Pitch
  pSetpoint = 25.0;
  pitchPID.SetMode(AUTOMATIC);
  pitchPID.SetTunings(Kp, Ki, Kd);
  pitchPID.SetOutputLimits(-500, 500);
  pitchPID.SetSampleTime(10);
}