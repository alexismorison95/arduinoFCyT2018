#define pinInt 2

volatile int state = LOW;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(pinInt, INPUT);

  attachInterrupt(digitalPinToInterrupt(pinInt),activoFalling,FALLING); 
}

void loop() {
  if(state){
    delay(1000);
    attachInterrupt(digitalPinToInterrupt(pinInt),activoRising,RISING);
    state=LOW;}
}

void activoFalling() {
  Serial.println("MAMAAAA");
  detachInterrupt(digitalPinToInterrupt(pinInt));
  state = HIGH;
}

void activoRising(){  
  Serial.println("saca la mano de ahi carajo");
  detachInterrupt(digitalPinToInterrupt(pinInt));
  attachInterrupt(digitalPinToInterrupt(pinInt),activoFalling,FALLING);
}


