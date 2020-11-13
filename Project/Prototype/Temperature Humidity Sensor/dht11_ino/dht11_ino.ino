/*
Reference
https://www.circuitbasics.com/how-to-set-up-the-dht11-humidity-sensor-on-an-arduino/
*/

#include <dht.h>
#define DHT11_PIN 7 // Analog Pin sensor is connected to
#define HeatingPad_PIN A0 // Heating pad anode is connected to

dht DHT;

void setup(){
  Serial.begin(9600);
}

void loop(){
  
  int chk = DHT.read11(DHT11_PIN); // Read and store the data received from the analog pin
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature); // Temperature value
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity); // Humidity value
  delay(1000);

  // Use the humidity value to generate voltage for the heating pad
  int voltage = DHT.humidity;
  //Map analog values ranging from 0-100 to values 0-1023
  voltage = map(voltage=, 0, 100, 0, 1023);
  // Warm up the heating pad using the given voltage
  analogWrite(HeatingPad_PIN, voltage*2);
  Serial.print("Voltage = ");
  Serial.println(voltage*2); // Print voltage value
}
