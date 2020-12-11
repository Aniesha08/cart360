/*
 Reference
  https://www.circuitbasics.com/how-to-set-up-the-dht11-humidity-sensor-on-an-arduino/
*/

#include <dht.h>
#define DHT11_PIN 7 // Analog Pin sensor is connected to
#define heatingPad_PIN 5 // Heating pad anode is connected to
#define led_PIN 8
dht DHT;

void setup() {
  Serial.begin(9600);
  pinMode(DHT11_PIN, INPUT);
  pinMode(led_PIN, OUTPUT);
  pinMode(heatingPad_PIN, OUTPUT);
}

void loop() {
 
  if (DHT.humidity > 15) {
    digitalWrite(led_PIN, HIGH);
    delay(500);
    digitalWrite(led_PIN, LOW);
    delay(500);
   }

  int chk = DHT.read11(DHT11_PIN); // Read and store the data received from the digital pin
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature); // Temperature value
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity); // Humidity value
  delay(1000);

  // Use the humidity value to generate voltage for the heating pad
  int voltage = DHT.humidity;
  //Map analog values ranging from 0-100 to values 0-255
  voltage = map(voltage, 0, 100, 0, 255);
  // Warm up the heating pad using the given voltage
  analogWrite(heatingPad_PIN, voltage);
  Serial.print("Voltage = ");
  Serial.println(voltage); // Print voltage value
}
