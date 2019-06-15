#include <NewPing.h>

/*Aqui se configuran los pines donde debemos conectar el sensor*/
#define TRIGGER_PIN  5
#define ECHO_PIN     4
#define MAX_DISTANCE 200
#define buzzer 10

/*Crear el objeto de la clase NewPing*/
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // Esperar 1 segundo entre mediciones
  //delay(1000);
  // Obtener medicion de tiempo de viaje del sonido y guardar en variable uS
  int uS = sonar.ping_median();
  int distancia = uS / US_ROUNDTRIP_CM;
  Serial.println("la distancia es: "+(String) distancia+" cm.");
  if(distancia>20){
    sonido(1500);
  }
  else{
    if(distancia<10){
      sonido(250);
    }
    else{
      sonido(750);
    }
  }
}

void sonido(int segundos){
  analogWrite(buzzer, 50);
  delay(segundos);
  analogWrite(buzzer, 0);
}

