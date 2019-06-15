#include <Servo.h>
#define sensor A0
#define sol 975
Servo motor;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sensor, INPUT);
  motor.attach(9);
  motor.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  int medOeste = 0;
  int medEste = 0;
  int valor = analogRead(sensor);
  int posicion = motor.read();
  if(valor<sol){
    if(posicion<170){
      motor.write(posicion+10);
      delay(500);
      medOeste = analogRead(sensor);
    }
    if(posicion>0){
      motor.write(posicion-10);
      delay(500);
      medEste = analogRead(sensor);
    }
    if(medOeste>medEste){
      while((valor<sol)&&(motor.read()<170)){
        posicion += 5;
        motor.write(posicion);
        valor = analogRead(sensor);
        delay(500);
      }
    }
    else{
      while((valor<sol)&&(motor.read()>0)){
        posicion -= 5;
        motor.write(posicion);
        valor = analogRead(sensor);
        delay(500);
      }
    }
  }
  Serial.println(valor);
  delay(500);

}
