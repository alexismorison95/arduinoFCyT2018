#include <Servo.h>
Servo motor;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  motor.attach(9);
  motor.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  int i = 0;
  while(i<3){
    motor.write(rand()%170);
    i++;
    delay(500);
  }
  Serial.println(motor.read());
  delay(1000);
}
