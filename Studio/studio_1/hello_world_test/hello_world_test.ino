void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
  while(!Serial);
  Serial.println("SETUP COMPLETE");
  
}

void loop() {
  // put your main code here, to run repeatedly:
   Serial.println("SPINNING MY WHEELS");
}
