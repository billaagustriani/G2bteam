#include <ESP32Servo.h>
#include <PID_v1.h>
#include <HMC5883L.h>
#include <I2Cdev.h>
#include <MPU6050.h>
#include "Wire.h"
#include <MadgwickAHRS.h>

float heading;
const float gyrosensitivity = 131.00;
const float accelsensitivity = 16384.00;
const float Rho = 1000; // satuan Kg/m^3
const float grav = 9.8; // Satuan m/s^2

double depthInput, depthOutput;
double yawInput, yawOutput;
double pInput, pOutput;
double yawSetpoint; //dalam derajat (sudut)
double pSetpoint;
double dSetpoint;
double Kp = 0.0;
double Ki = 0.0;
double Kd = 0.0;

int brushAwal;
float brush3;
float brush4;
float brush5;
float brush6;

Servo motor1, motor2, motor3, motor4, motor5, motor6;
Madgwick filter;
MPU6050 accelgyro;
HMC5883L mag;
PID yawPID(&yawInput, &yawOutput, &yawSetpoint, Ki, Kp, Kd, DIRECT);
PID pitchPID(&pInput, &pOutput, &pSetpoint, Ki, Kp, Kd, DIRECT);
PID DepthPID(&depthInput, &depthOutput, &dSetpoint, Ki, Kp, Kd, DIRECT);

int16_t ax, ay, az;
float accX, accY, accZ;
float gyroX, gyroY, gyroZ;
int16_t gx, gy, gz;
int16_t mx, my, mz;
int16_t GX, GY, GZ;
unsigned long microsPerReading, microsPrevious;
float pitch, yaw;
float depth;

void setup(){
  Serial.begin(115200);
  setup_motor();
  filter.begin(20);
  Wire.begin();
  setup_pid();
  koneksi();
  microsPerReading = 1000000 / 50;
  microsPrevious = micros();

}
void loop(){
  gerak();
  unsigned long microsNow;
  microsNow = micros();
 if (microsNow - microsPrevious >= microsPerReading) {
    // read raw accel/gyro measurements from device
    accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
    // read raw heading measurements from device
    mag.getHeading(&mx, &my, &mz);
    accX = (float) ax / accelsensitivity;
    accY = (float) ay / accelsensitivity;
    accZ = (float) az / accelsensitivity;
    gyroX = (float) gx / gyrosensitivity;
    gyroY = (float) gy / gyrosensitivity;
    gyroZ = (float) gz / gyrosensitivity;

    gyroX = gyroX - GX;
    gyroY = gyroY - GY;
    gyroZ = gyroZ - GZ;
    
    //HMC5883L
    heading = atan2 (my, mx) * 180 / M_PI;
    filter.update(gyroX, gyroY, gyroZ, accX, accY, accZ, mx, my, mz);

    yaw = filter.getYaw();
    yawPID.Compute();

    pitch = filter.getPitch();
    pitchPID.Compute();

    microsPrevious = microsPrevious + microsPerReading;
 }

}
