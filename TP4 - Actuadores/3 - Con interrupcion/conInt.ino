#include <Servo.h>
#define led 9
#define pinInt 2
Servo motor;
volatile int state = LOW;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  attachInterrupt(digitalPinToInterrupt(pinInt),prenderLed,RISING);
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
    for(int i=emp; i<= fin; i+=45){
      motor.write(i);
      delay(500);
    }
  }
  else{
    for(int i=emp; i>= fin; i-=45){
      motor.write(i);
      delay(500);
    }
  }
}

void prenderLed(){
  state = !state;
  digitalWrite(led, state);
}

