#include <LowPower.h>

#define sensor A0

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  int valor = 0;
  int leido = 0;
  String msj = " ";
  // put your main code here, to run repeatedly:
  Serial.println("dormido");
  delay(500);
  dormir();
  Serial.println("despierto");
  leido = analogRead(sensor);
  delay(500);
  while(valor<leido){
    valor = leido;
    leido = analogRead(sensor);
    delay(500);
  }
  Serial.print("El mayor valor leido fue: ");
  Serial.println(valor);
  delay(500);
}

void dormir(){
  for(int i=0; i<3; i++){
    LowPower.powerDown(SLEEP_4S, ADC_OFF, BOD_OFF);
    delay(500);
  }
}

