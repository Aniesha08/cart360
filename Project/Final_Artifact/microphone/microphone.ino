int soundSensor = A0; // Microphone pin
int LED = 4; // LED pin
bool ledStatus = false; // boolean check if LED is on or OFF
const int VR = 6; // Vibration pin


void setup() {
 Serial.begin(57600);
 pinMode(LED,OUTPUT);
 pinMode(VR, OUTPUT); // initialize the digital pin as an output
}

// The function that turns the vibration motor on and off and keeps the range between 0 to 4095, 0 to 255
void motor(int n) {
    if(n != 0) { 
        analogWrite(VR, n);//turn the VR on 
    } else {
        analogWrite(VR, 0);//turn the VR on
    }
    delay(n);
}

// The function that sums up the 40 samples of the microphone value and returns it. 
int getMicrophone() {
    int _t = 0;
    
    for(int i = 0; i < 42; i++) {
        
        _t += analogRead(soundSensor);
        delay(1);
    }
    
    return (_t / 32);
}

void loop() {
     // the variable that stores the micropone's value
     int sensorData = getMicrophone();
     Serial.println(sensorData);
     // if sensor data value is more than 1000...
    if ( sensorData > 300 ) {
        Serial.println("In Microphone");
        Serial.println(sensorData);
        //...and if the LED is off...
        if(ledStatus == false ){
            ledStatus = true;
            //...turn on the LED and vibrate the vibration motor
            digitalWrite(LED, HIGH);
            motor(sensorData);
        }
  }
    else {
        // if the LED is on...
        ledStatus = false;
        //...turn off the LED...
        digitalWrite(LED, LOW);
        //..,turn off the vibration motor
        motor(0);
        delay(0);
    }
}
