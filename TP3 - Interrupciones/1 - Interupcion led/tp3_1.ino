#define pinSender 10
#define pinInt 2

#define led 13

volatile int state = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(pinSender, OUTPUT);
  pinMode(pinInt, INPUT);

  //RISING ----- LOW A HIGH
  //FALLING ---- HIGH A LOW
  attachInterrupt(digitalPinToInterrupt(pinInt),blink,FALLING);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pinSender, HIGH);
  Serial.println("ALTO");
  delay(1000);
  digitalWrite(pinSender, LOW);
  Serial.println("BAJO");
  delay(1000);
}

void blink() {
  Serial.println("Entro a blink");
  state = !state;
  digitalWrite(led,state);
  delay(1000);
}

