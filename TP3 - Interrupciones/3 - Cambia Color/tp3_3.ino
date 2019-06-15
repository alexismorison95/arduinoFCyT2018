#define pinSender 10
#define pinInt 2

#define verde 6
#define amarillo 5
#define rojo 4

volatile int state = LOW;
volatile bool control = true;
volatile int cont = 0;

void setup() {
  Serial.begin(9600);
  pinMode(pinSender, OUTPUT);
  pinMode(pinInt, INPUT);
  pinMode(verde, OUTPUT);
  pinMode(amarillo, OUTPUT);
  pinMode(rojo, OUTPUT);

  //RISING ----- LOW A HIGH
  //FALLING ---- HIGH A LOW
  attachInterrupt(digitalPinToInterrupt(pinInt),blink,RISING);
}

void loop() {
  activar();
}

void blink() {
  if(control){
    //Serial.println("Se activo interrupcion");
    cont = cont+1;
    Serial.println(cont);
    control = false;
    if(cont>0 && cont<3){
      digitalWrite(verde, HIGH);
      digitalWrite(amarillo, LOW);
      digitalWrite(rojo, LOW);
    }
    else{
      if(cont<5){
      digitalWrite(verde, LOW);
      digitalWrite(amarillo, HIGH);
      digitalWrite(rojo, LOW);
    }
    else{
      if(cont<7){
      digitalWrite(verde, LOW);
      digitalWrite(amarillo, LOW);
      digitalWrite(rojo, HIGH);
    }
    else{
      cont = 0;
      digitalWrite(verde, LOW);
      digitalWrite(amarillo, LOW);
      digitalWrite(rojo, LOW);
    }
  }
}
}
}

void activar(){
  interrupts(); 
  delay(500);
  noInterrupts();
  control = true;
}

