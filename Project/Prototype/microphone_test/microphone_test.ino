/*
 * Rui Santos 
 * Complete Project Details https://randomnerdtutorials.com/guide-for-microphone-sound-sensor-with-arduino/
*/

int ledPin=13;
int sensorPin=7;
boolean val = 1;

void setup(){
  pinMode(sensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin (9600);
}

void loop (){
  val =digitalRead(sensorPin);
  // when the sensor detects a signal above the threshold value, LED flashes
  if (val== LOW) {
    digitalWrite(ledPin, HIGH); 
    delay(1000);
    Serial.println (val);
  }
  else {
    digitalWrite(ledPin, LOW);
  }
}
