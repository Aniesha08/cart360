Subscribe / Publish:

// -----------------------------------------
// Zahra and Aniesha Project
/* -----------------------------------------


------------------------------------------*/
// Variables 
int soundSensorZ = A0;   // Microphone pin
int LEDZ=4;              // LED pin
bool LEDStatusZ = false;
const int VRZ = 6;       // Vibration pin
int thresholdZ = 200;
int sensorDataZ = 0;

void setup() {
  
    pinMode(LEDZ,OUTPUT); // led to test if sound working
    pinMode(VRZ,OUTPUT);// initialize the digital pin as an output
    
    // Subscribe to Aniesha's variables
    Particle.subscribe("LEDA", microphoneCode, "A_Argon");
    Particle.subscribe("LEDStatusA", microphoneCode, "A_Argon");
    Particle.subscribe("VRA", microphoneCode, "A_Argon");
}

void loop() {
  // My sensor data
  sensorDataZ = abs(analogRead(soundSensorZ)-thresholdZ); 
    
     // Publish my sensor value and keep it live for 2 mins
    Particle.publish("sensorDataZ", 120, PRIVATE);


 }
 
 void microphoneCode (const char *event, const char *data) {
     
       // If my sensor data greater than 175,
    if(sensorDataZ > 175 ){

        // Turn on Aniesha's LED light if it is off
        if(LEDStatusA == false ){
            
            LEDStatusA = true;
            digitalWrite(LEDA, HIGH); // turn on the LED (Aniesha's)
            analogWrite(VRA, sensorDataZ);// Vibrates vibration motor
            delay(sensorDataZ);
            console.log(sensorDataZ);
        }

    }
    else {
        
        LEDStatusA = false;
        digitalWrite(LEDA, LOW); // turn off the LED
        analogWrite(VRA, 0); // turn the vibration motor off
        delay(0);
    
    }
     
 }
