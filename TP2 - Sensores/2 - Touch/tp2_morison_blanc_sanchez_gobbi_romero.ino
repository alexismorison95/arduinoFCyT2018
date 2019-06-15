#define sensor 7
#define led 13

void setup() {
  // put your setup code here, to run once:
  pinMode(sensor, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensortactil();
}

void sensortactil(){
  int sensorValue = digitalRead(sensor);
  if(sensorValue==1){
    digitalWrite(led,HIGH);
  }
  else{
    digitalWrite(led,LOW);
  }  
}
