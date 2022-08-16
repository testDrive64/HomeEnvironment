#include <Arduino.h>
#include <DFRobot_DHT11.h>

// A0 - Taster
// D2 - DTH11
// A4 - SDA
// A5 - SCL
// Auf Tastendruck Temperatur und Luftfeuchtigkeit messen und
// auf dem Display ausgeben.
DFRobot_DHT11 DHT;
#define DHT11_PIN 2
#define button A0

#include <Wire.h>

void setup() {
 
Serial.begin(115200);
  // Leonardo: wait for serial port to connect
  while (!Serial) 
    {
    }

  Serial.println ();
  Serial.println ("I2C scanner. Scanning ...");
  byte count = 0;
  
  Wire.begin();
  for (byte i = 8; i < 120; i++)
  {
    Wire.beginTransmission (i);
    if (Wire.endTransmission () == 0)
      {
      Serial.print ("Found address: ");
      Serial.print (i, DEC);
      Serial.print (" (0x");
      Serial.print (i, HEX);
      Serial.println (")");
      count++;
      delay (1);  // maybe unneeded?
      } // end of good response
  } // end of for loop
  Serial.println ("Done.");
  Serial.print ("Found ");
  Serial.print (count, DEC);
  Serial.println (" device(s).");


  
  pinMode(button, INPUT);
  
}

void loop(){
  DHT.read(DHT11_PIN);
  Serial.print("temp:");
  Serial.print(DHT.temperature);
  Serial.print("  humi:");
  Serial.println(DHT.humidity);
  delay(1000);
}
