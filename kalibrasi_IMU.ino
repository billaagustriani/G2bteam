void kalibrasi(int16_t Gyrox, int16_t Gyroy, int16_t Gyroz, int n) {
  accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  gyroX = (float) gx / gyrosensitivity;
  gyroY = (float) gy / gyrosensitivity;
  gyroZ = (float) gz / gyrosensitivity;
  for (int i = 0; i < n; i++) {
    Gyrox = Gyrox + gyroX;
    Gyroy = Gyroy + gyroY ;
    Gyroz = Gyroz + gyroZ;
  }
  Gyrox = Gyrox / n;
  Gyroy = Gyroy / n;
  Gyroz = Gyroz / n;
}