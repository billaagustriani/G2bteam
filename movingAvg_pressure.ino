#define pressurePin 14
#define FILTER_LEN 10

uint32_t pressureBuffer[FILTER_LEN] = { 0 }; //array pressureBuffer yang digunakan untuk menyimpan data pembacaan sensor tekanan
uint16_t pressureraw = 0, pressureFiltered = 0, indeX = 0;
const long interval = 1000; // Interval pembacaan dalam milidetik (misalnya 1000ms = 1 detik)
const float Rho = 1000; // satuan Kg/m^3
const float grav = 9.8; // satuan m/s^2
unsigned long previousMillis = 0;
float depth;

void setup() {
  Serial.begin(115200);
}

void loop() {
  pressureraw = analogRead(pressurePin);
  pressureFiltered = movingAverage(pressureraw);
  Serial.print(pressureraw);    
  Serial.print(",");      
  Serial.println(pressureFiltered);  // Print Filtered Output
  
  // Ambil waktu sekarang
  unsigned long currentMillis = millis();

  // Cek apakah sudah waktunya membaca sensor
  if (currentMillis - previousMillis >= interval) {
    // Update waktu terakhir pembacaan
    previousMillis = currentMillis;
  }

  float voltage = pressureraw * (5.0 / 4095.0); // Convert to voltage
  // Assuming 0.5V = 0 PSI and 4.5V = 174 PSI
  // Adjust 'baselineVoltage' based on your zero-pressure reading
  // float baselineVoltage = 0.45; // Example value, adjust based on your sensor at zero pressure

  // Serial.print("baselineVoltage: ");
  float pressureraw = voltage * (174.0 / (4.5));// membaca nilai tekanan dari sensor

  // Menghitung kedalaman menggunakan rumus hidrostatik: depth = pressure / (Rho * grav)
  float depth = pressureraw / (Rho * grav);

  Serial.print(voltage);
  Serial.println(" v");
  //Serial.print("Pressureraw: ");
  //Serial.print(pressureraw);
  //Serial.println(" psi");
  // Menampilkan nilai kedalaman ke Serial Monitor
  Serial.print(depth);
 // Serial.print(depth, 2);
  Serial.println(" m ");
}

uint32_t movingAverage(int rawData) { // menghitung nilai rata-rata bergerak dari data sensor tekanan
  uint32_t sum = 0;
  pressureBuffer[indeX++] = rawData;
  if (indeX == FILTER_LEN) indeX = 0;
  for (uint8_t i = 0; i < FILTER_LEN; i++) {
    sum += pressureBuffer[i];
  }
  return (sum / FILTER_LEN);
}
