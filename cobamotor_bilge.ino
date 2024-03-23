//driver motor 1
#define Rpwm 2
#define Lpwm 3
#define Ren 12
#define Len 13
//driver motor 2
#define Rpwm1 4
#define Lpwm1 5
#define Ren1 18
#define Len1 19
//driver motor 3
#define Rpwm2 7
#define Lpwm2 6
#define Ren2 14
#define Len2 15
//deiver motor 4 
#define Rpwm3 8
#define Lpwm3 9
#define Ren3 16
#define Len3 17

void pin() {
  pinMode(Ren ,OUTPUT);
  pinMode(Len ,OUTPUT);
  pinMode(Rpwm ,OUTPUT);
  pinMode(Lpwm ,OUTPUT);

  pinMode(Ren1 ,OUTPUT);
  pinMode(Len1 ,OUTPUT);
  pinMode(Rpwm1 ,OUTPUT);
  pinMode(Lpwm1 ,OUTPUT);
  
  pinMode(Ren2 ,OUTPUT);
  pinMode(Len2 ,OUTPUT);
  pinMode(Rpwm2 ,OUTPUT);
  pinMode(Lpwm2 ,OUTPUT);

  pinMode(Ren3 ,OUTPUT);
  pinMode(Len3 ,OUTPUT);
  pinMode(Rpwm3 ,OUTPUT);
  pinMode(Lpwm3 ,OUTPUT);
}

void enableMotor(bool flag){
  if(flag = true){
    digitalWrite(Ren, HIGH);
    digitalWrite(Len, HIGH);
    digitalWrite(Ren1, HIGH);
    digitalWrite(Len1, HIGH);
    digitalWrite(Ren2, HIGH);
    digitalWrite(Len2, HIGH);
    digitalWrite(Ren3, HIGH);
    digitalWrite(Len3, HIGH);
  }
  else if(flag = false){
    digitalWrite(Ren, LOW);
    digitalWrite(Len, LOW);
    digitalWrite(Ren1, LOW);
    digitalWrite(Len1, LOW);
    digitalWrite(Ren2, LOW);
    digitalWrite(Len2, LOW);
    digitalWrite(Ren3, LOW);
    digitalWrite(Len3, LOW);
  }
}
void runMotor1(){
  if(kecepatan1 < 0){
    analogWrite(Lpwm, abs(kecepatan1));
    analogWrite(Rpwm, 0);
  }
  else if(kecepatan1 > 0){
    analogWrite(Rpwm, abs(kecepatan1));
    analogWrite(Lpwm, 0);
  }
  else if( kecepatan1 == 0 ){
    enableMotor(false);
    analogWrite(Rpwm, 0);
    analogWrite(Lpwm, 0);
  }
}
void runMotor2(){
  if(kecepatan2 < 0){
    analogWrite(Rpwm1, abs(kecepatan2));
    analogWrite(Lpwm1, 0);
  }
  else if(kecepatan2 > 0){
    analogWrite(Lpwm1, abs(kecepatan2));
    analogWrite(Rpwm1, 0);
  }
  else if( kecepatan2 == 0 ){
    enableMotor(false);
    analogWrite(Rpwm1, 0);
    analogWrite(Lpwm1, 0);
  }
}
void runMotor3(){
  if(kecepatan3 < 0){
    analogWrite(Lpwm2, abs(kecepatan3));
    analogWrite(Rpwm2, 0);
  }
  else if(kecepatan3 > 0){
    analogWrite(Rpwm2, abs(kecepatan3));
    analogWrite(Lpwm2, 0);
  }
  else if ( kecepatan3 == 0 ){
    enableMotor(false);
    analogWrite(Rpwm2, 0);
    analogWrite(Lpwm2, 0);
  }
}
void runMotor4(){
  if(kecepatan4 < 0){
    analogWrite(Rpwm3, abs(kecepatan4));
    analogWrite(Lpwm3, 0);
  }
  else if(kecepatan4 > 0){
    analogWrite(Lpwm3, abs(kecepatan4));
    analogWrite(Rpwm3, 0);
  }
  else if ( kecepatan4 == 0 ){
    enableMotor(false);
    analogWrite(Rpwm3, 0);
    analogWrite(Lpwm3, 0);
  }
}

/*
void runPitch(){
    brussspeed1 = brussspeed + pOutput;
    brussspeed2 = brussspeed - pOutput;
    bruss2.writeMicroseconds(brussspeed2);
    bruss1.writeMicroseconds(brussspeed1);
}
                                       */

void runYaw(){
    kecepatan1 = base - yawOutput;
    kecepatan2 = base - yawOutput;
    kecepatan3 = base - yawOutput;
    kecepatan4 = base - yawOutput;
}

void runRoll(){
    kecepatan5 = kecepatan1 - rollOutput;
    kecepatan6 = kecepatan2 - rollOutput;
    kecepatan7 = kecepatan3 + rollOutput;
    kecepatan8 = kecepatan4 + rollOutput;
}
