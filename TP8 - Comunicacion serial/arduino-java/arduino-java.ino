void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void cambiarColor(int color){
  switch(color){
    case 1:{pinMode(4,OUTPUT);//RED
            pinMode(5,INPUT);
            pinMode(6,INPUT);
            break;
            }
    case 2:{pinMode(6,OUTPUT);//AZUL
            pinMode(4,INPUT);
            pinMode(5,INPUT);
            break;
            }
    case 3:{pinMode(5,OUTPUT);//VERDE
            pinMode(6,INPUT);
            pinMode(4,INPUT);
            break;
            }
    case 4:{pinMode(4,OUTPUT);//VIOLETA
            pinMode(6,OUTPUT);
            pinMode(5,INPUT);
            break;
            }
    case 5:{pinMode(4,OUTPUT);//AMARILLO
            pinMode(5,OUTPUT);
            pinMode(6,INPUT);
            break;
            }
    case 6:{pinMode(5,OUTPUT);//CELESTE
            pinMode(6,OUTPUT);
            pinMode(4,INPUT);
            break;
            }
    case 7:{pinMode(4,OUTPUT);//BLANCO
            pinMode(5,OUTPUT);
            pinMode(6,OUTPUT);
            break;
            }
  }
          
}

void apagar() {
  pinMode(4,INPUT);
  pinMode(5,INPUT);
  pinMode(6,INPUT);  
}

void loop() {
  if(Serial.available()>0){
    int color = Serial.parseInt();
    cambiarColor(color);
    
  }
}
