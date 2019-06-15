#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//#include <OneWire.h>
//#include <DallasTemperature.h>

//const int oneWirePin = 5;
 
//OneWire oneWireBus(oneWirePin);
//DallasTemperature sensor(&oneWireBus);



#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#if (SSD1306_LCDHEIGHT != 32)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif


void setup() {
  // put your setup code here, to run once:

  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  // init done

  // Clear the buffer.
  display.clearDisplay();

  Serial.begin(9600);
  //sensor.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  /*float temp;
Serial.println("Leyendo temperaturas: ");
  sensor.requestTemperatures();

 Serial.print("Temp. Visor: ");
   Serial.print(sensor.getTempCByIndex(0));
   Serial.println(" ºC");*/
  
  display.clearDisplay(); // clear previous buffered data

  display.setTextColor(WHITE);

  // header
  display.setCursor(0,0);
  display.setTextSize(1);
  display.println("Arduino");

 
  // texto
  display.setCursor(35,18);
  display.setTextSize(2);
  display.println("MONA");
  //display.println(" º");
  display.display(); // update display

  delay(1000); // temp update interval
}


