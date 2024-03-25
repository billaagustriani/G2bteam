// Definisi pin yang digunakan
#include <ESP32Servo.h>

Servo motor3, motor4, motor5, motor6;

void setup() {
  // Inisialisasi Serial Monitor dengan kecepatan 9600 bps
  Serial.begin(115200);
  // Atur pin sebagai output
  motor3.attach(4);
  motor4.attach(18);
  motor5.attach(5);
  motor6.attach(16);
}

void loop() {
  // Tampilkan instruksi pada Serial Monitor
  //Serial.println("Ketik 'R' untuk menggerakkan motor ke kanan atau 'L' untuk ke kiri:");
  
  if(Serial.available() > 0){
   char command = Serial.read();
  
  
    // Brussless kanan
    if (command == 'R' || command == 'r'){
    motor3.writeMicroseconds(1700);//CCW
    motor4.writeMicroseconds(1700);//CW
    motor5.writeMicroseconds(1700);//CCW
    motor6.writeMicroseconds(1700);//CW
    delay(1000);
    }

    // brushless kiri
    else if (command == 'L' || command == 'l'){
    motor3.writeMicroseconds(1300);
    motor4.writeMicroseconds(1300);
    motor5.writeMicroseconds(1300);
    motor6.writeMicroseconds(1300);
    delay(1000);
    }

    //Matikan Brussles 
     else if (command == 'B' || command == 'b'){
    motor3.writeMicroseconds(1500);
    motor4.writeMicroseconds(1500);
    motor5.writeMicroseconds(1500);
    motor6.writeMicroseconds(1500);
    delay(1000);
    }
  

    else if (command == 'M' || command == 'm'){
    ///gerak maju
    motor3.writeMicroseconds(1700); // Kecepatan penuh ke depan//CCW
    motor4.writeMicroseconds(1300); // Kecepatan penuh ke depan//CW
    motor5.writeMicroseconds(1700); // Kecepatan penuh ke belakang//cCW
    motor6.writeMicroseconds(1300); // Kecepatan penuh ke belakang//CW
    delay(1000);
    }

    else if (command == 'U' || command == 'u'){
    ///gerak mundur
    motor3.writeMicroseconds(1300); // Kecepatan penuh ke belakang/ccw
    motor4.writeMicroseconds(1700); // Kecepatan penuh ke belakang/cw
    motor5.writeMicroseconds(1300); // Kecepatan penuh ke depan/ccw
    motor6.writeMicroseconds(1700); // Kecepatan penuh ke depan/cw
    delay(1000);
    }
  }
}
