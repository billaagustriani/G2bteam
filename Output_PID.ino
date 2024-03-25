void runYaw(){
 brush3 = brushAwal - yawOutput;
 brush4 = brushAwal - yawOutput;
 brush5 = brushAwal - yawOutput;
 brush6 = brushAwal - yawOutput;
  
  motor3.writeMicroseconds(brush3);
  motor4.writeMicroseconds(brush4);
  motor5.writeMicroseconds(brush5);
  motor6.writeMicroseconds(brush6);
}
