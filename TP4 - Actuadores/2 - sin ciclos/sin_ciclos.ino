#include <Servo.h>
Servo motor;
int i = 0;

void setup() {
  // put your setup code here, to run once:
  motor.attach(10);
  motor.write(i);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(i<170){
    motor.write(i);
    i++;
    delay(20);
  }
  else{
    i = 0;
  }
}
