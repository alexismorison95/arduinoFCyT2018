#include <Servo.h>
Servo motor;

void setup() {
  // put your setup code here, to run once:
  motor.attach(10);
  motor.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  mover(0,170);
  mover(170,0);
}

void mover(int emp, int fin){
  if(emp<fin){
    for(int i=emp; i<= fin; i++){
      motor.write(i);
      delay(20);
    }
  }
  else{
    for(int i=emp; i>= fin; i--){
      motor.write(i);
      delay(20);
    }
  }
}

