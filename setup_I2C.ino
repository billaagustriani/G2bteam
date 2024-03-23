void koneksi(){
  //MPU6050
  Serial.println("Initializing I2C devices...");
  accelgyro.initialize();
  //Serial.println("kalibrasi sensor...");
  //kalibrasi(GX,GY,GZ,100);
  // verify connection
  Serial.println("Testing device connections...");
  Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");
  // HMC5883L
  mag.initialize();
  // verify connection
  Serial.println("Testing device connections...");
  Serial.println(mag.testConnection() ? "HMC5883L connection successful" : "HMC5883L connection failed");
  // initialize variables to pace updates to correct rate
}