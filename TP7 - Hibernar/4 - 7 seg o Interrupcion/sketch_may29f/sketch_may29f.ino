#include <LowPower.h>
#define boton 2
#define LED 13

volatile bool inter = false;

volatile int state = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(boton, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);

  attachInterrupt(digitalPinToInterrupt(boton),blink,FALLING);
}

void loop() {
  // put your main code here, to run repeatedly: 
  Serial.println("Dormido");
  delay(400);
  LowPower.powerDown(SLEEP_4S,ADC_OFF,BOD_OFF);
  
  if(inter == false){
    Serial.println("Despertado al pasar 7 segundos");
    state = !state;
    digitalWrite(LED,state);
    delay(1000);
  }
  else{
    inter = false;
  }
  
}

void blink(){
  inter = true;
  Serial.println("Despertado por interrupcion");
  state = !state;
  digitalWrite(LED,state);
  delay(1000);
}
