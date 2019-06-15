#include <LowPower.h>
#define sensor A0
int mayor = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  for(int i = 0; i <3; i++){
    LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF); 
  }
  int sensorValue = analogRead(sensor);
  if (sensorValue > mayor){
    mayor = sensorValue;
  }
  
  Serial.println(mayor);
  delay(400);
}
