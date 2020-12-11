int soundSensor = A0;
int LED=4;
boolean LEDStatus=false;
const int VR = 6;// Vibration pin
int threshold = 200;

void setup() {
  
 Serial.begin(9600);
// pinMode(soundSensor,INPUT);
 pinMode(LED,OUTPUT);
 pinMode(VR,OUTPUT);//initialize the digital pin as an output
}

void loop() {
//
  int sensorData= abs(analogRead(soundSensor)-threshold); 
  
  if(sensorData > 175 ){

    if(LEDStatus== false ){
        LEDStatus=true;
        digitalWrite(LED,HIGH);
        analogWrite(VR,sensorData);//turn the VR on 
        delay(sensorData);
        Serial.println("sensorData");
        Serial.println(sensorData);
    }

  
  }
  else {
        LEDStatus=false;
        digitalWrite(LED,LOW);
        analogWrite(VR,0); //turn the VR off
        delay(0);
    
    }
 }
