#define sensor A0
#define ledverde 4 
#define ledrojo 3
#define ledama 2

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  //pinMode(sensor, INPUT);
  pinMode(ledverde, OUTPUT); //comienza apagado
  pinMode(ledrojo, OUTPUT); //comienza apagado
  pinMode(ledama, OUTPUT); //comienza apagado
}

void luminosidad(){ //comienza apagado
  int sensorValue = analogRead(sensor);
  Serial.println(sensorValue);
  if(sensorValue< 400){
    digitalWrite(ledverde,HIGH);
    digitalWrite(ledrojo,LOW);
    digitalWrite(ledama,LOW);
  }

  if(sensorValue< 800 && sensorValue>400){
    digitalWrite(ledama,HIGH);
    digitalWrite(ledrojo,LOW);
    digitalWrite(ledverde,LOW);
  }
  if(sensorValue>800){
    digitalWrite(ledrojo,HIGH); 
    digitalWrite(ledverde,LOW);
    digitalWrite(ledama,LOW); 
  }  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  luminosidad();
  delay(1000);
}
