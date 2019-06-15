#define pinSender 10
#define pinInt 2

#define led 6

volatile int state = LOW;
volatile bool control = true;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(pinSender, OUTPUT);
  pinMode(pinInt, INPUT);

  //RISING ----- LOW A HIGH
  //FALLING ---- HIGH A LOW
  attachInterrupt(digitalPinToInterrupt(pinInt),blink,RISING);
}

void loop() {
  activar();
}

void blink() {
  if(control){
    Serial.println("Se activo interrupcion");
    digitalWrite(led, HIGH);
    control = false;
  }
}

void activar(){
  interrupts(); 
  delay(1000);
  digitalWrite(led, LOW);
  noInterrupts();
  control = true;
}

