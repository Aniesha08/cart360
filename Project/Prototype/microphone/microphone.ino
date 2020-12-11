int soundSensor = A0;
int LED = D4;
bool ledStatus = false;
const int VR = D5;// Vibration pin
int threshold = 200;


void setup() {
    Serial.begin(57600);
 pinMode(LED,OUTPUT);
//  pinMode(VR,OUTPUT); //initialize the digital pin as an output
 
}

void motor(int n) {
    
    if(n != 0) { 
        analogWrite(VR, map(n, 0, 4096, 0, 255) );//turn the VR on 
    } else {
        analogWrite(VR, 0);//turn the VR on
    }
    delay(n);
}

void loop() {
     int sensorData = abs(analogRead(soundSensor)-threshold);
    
    if ( sensorData > 768 ) {
        Serial.println("In Microphone");
        Serial.println(sensorData);
        if(ledStatus == false ){
            ledStatus = true;
            digitalWrite(LED, HIGH);
        }
            // motor(sensorData);
           

    // }

    Serial.println(sensorData);
//   if(sensorData > 768 ){

//     if(ledStatus == false ){
//         ledStatus = true;
//         digitalWrite(LED, HIGH);
//         analogWrite(VR, map(sensorData, 0, 4096, 0, 255) );//turn the VR on 
//         delay(sensorData);
//         // console.log(sensorData);
//         // console.log(LEDStatus);
//     }

//   }
  else {
    
        ledStatus = false;
        digitalWrite(LED, LOW);
        motor(0); //turn the VR off
        delay(0);
    }
}
