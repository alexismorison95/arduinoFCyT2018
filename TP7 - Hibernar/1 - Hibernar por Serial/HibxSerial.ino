#include <LowPower.h>
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
}

void loop() {
  String msj = " ";
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
    msj = Serial.readString();
    //delay(500);
    Serial.println("Recibi: "+ msj);
  }
  if(msj=="dormir"){
    Serial.println("durmiendo");
    delay(250);
    LowPower.powerDown(SLEEP_4S, ADC_OFF, BOD_OFF);
  }
  Serial.println("despierto");
    delay(500);
}

