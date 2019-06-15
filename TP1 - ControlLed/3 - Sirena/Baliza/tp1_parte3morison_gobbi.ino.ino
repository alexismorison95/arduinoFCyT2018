void setup() {
  // put your setup code here, to run once:

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
  delay(0500);
}

void titilar(int color, int veces){
  for(int i=0;i<veces;i++){
    cambiarColor(color);
    apagar(); 
  }
}

void baliza(int color,int veces){
  titilar(color,veces);
  cambiarColor(color);
  delay(1000);
  titilar(color,veces);
  cambiarColor(color);
  delay(0250); 
}

void loop() {
  // put your main code here, to run repeatedly:
  baliza(2,4);
}
