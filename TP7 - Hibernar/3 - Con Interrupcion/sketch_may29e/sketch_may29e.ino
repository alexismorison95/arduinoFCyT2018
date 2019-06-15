#include <LowPower.h>
#define boton 2
#define LED 13

volatile int state = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(boton, INPUT);
  Serial.begin(9600);

  attachInterrupt(digitalPinToInterrupt(boton),blink,FALLING);
}

void loop() {
  // put your main code here, to run repeatedly:
  LowPower.powerDown(SLEEP_8S,ADC_OFF,BOD_OFF);
}

void blink(){
  Serial.println("Entro a blink");
  state = !state;
  digitalWrite(LED,state);
  delay(1000);
}

