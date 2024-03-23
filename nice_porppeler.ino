// Definisi pin yang digunakan
#include <Servo.h>

char command;

Servo motor1;

void setup() {
  // Atur pin sebagai output
  motor1.attach(10);

  // Inisialisasi Serial Monitor dengan kecepatan 9600 bps
  Serial.begin(115200);
}

void loop() {
  // Tampilkan instruksi pada Serial Monitor
  //Serial.println("Ketik 'R' untuk menggerakkan motor ke kanan atau 'L' untuk ke kiri:");
  
  if(Serial.available() > 0){
    command = Serial.read();
  }
  
  // Brussless kanan
  else if (command == 'R' || command == 'r'){
    motor1.writeMicroseconds(2000);
    delay(2000);
  }

  // brushless kiri
  else if (command == 'L' || command == 'l'){
    motor1.writeMicroseconds(1000);
    delay(2000);
  }

  //Matikan Brussles 
  else if (command == 'B' || command == 'b'){
    motor1.writeMicroseconds(1500);
    delay(1000);
  }
}
