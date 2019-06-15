#include <Servo.h>
#define pote A1
Servo motor;

void setup() {
  // put your setup code here, to run once:
  motor.attach(9);
  motor.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  motor.write(map(analogRead(pote), 0, 1023, 0, 170));
}
