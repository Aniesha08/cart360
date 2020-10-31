/**********************ETUDE 3 CART 360 2020*******************************
 * WELCOME! 
 * THE PURPOSE OF THIS EXERCISE IS TO DESIGN A VERY SIMPLE KEYBOARD (4 KEYS)
 * WHICH ALLOWS YOU TO PLAY LIVE, RECORD, AND PLAYBACK SINGLE NOTES (NO CHORDS OR TIMING). 
 * THERE WILL BE A BUTTON WHICH WHEN PRESSED WILL TAKE THE USER TO THE NEXT MODE:
 * THERE ARE 5 POSSIBLE MODES
 * 0 ==  reset    ==   led off == also resets
 * 1 ==  live     ==   led BLUE
 * 2 ==  record   ==   led RED
 * 3 ==  play     ==   led GREEN
 * 4 ==  looper   ==   led PURPLE
 * 
 * ADDITIONALLY - WHEN THE USER CHANGES MODE, 
 * THE RGB LED WILL CHANGE COLOR (ACCORDING TO THE SPECIFICATIONS)

 * PLEASE FOLLOW THE INSTRUCTIONS IN THE COMMENTS:
 * DO NOT ADD ANY MORE FUNCTION DEFINITIONS 
 * ONLY IMPLEMENT THE FUNCTION DEFINITIONS SUPPLIED
 * THERE IS NO NEED TO ADD ANY NEW VARIABLES OR CONSTANTS
 * PROVIDE COMMENTS FOR ANY OF THE CODE IMPLEMENTED
 * GOOD LUCK!
 */
/**** CONSTANTS ********************************************************/

#define BUTTON_MODE_PIN 2 // Button to change the mode

// constants for RGB LED
#define LED_PIN_R 9  // B PIN
#define LED_PIN_G 10 // G PIN
#define LED_PIN_B 11 // R PIN

// constant for note in (button-resistor ladder on breadboard)
# define NOTE_IN_PIN A0

//constant for max number of notes in array
#define MAX_NOTES 16

// duration for a single played note
const int duration = 200;

// constant for pin to output for buzzer 
#define BUZZER_PIN 3 // PWM

/******** VARIABLES *****************************************************/
// counter for how many notes we have
int countNotes = 0;
int mode = 0; // start at off
// array to hold the notes played (for record/play mode)
int notes [MAX_NOTES]; 


/******** VARIABLES FOR LOOPER *****************************************************/
// check for repetition
int randomRepCheck [MAX_NOTES]; 
// store unrepeated random numbers
int mainRandomNumber [MAX_NOTES]; 
// for while loop to check if all 16 spots of the mainRandomNumber array are filled
int j = 1; 

/*************************************************************************/


/**********************SETUP() DO NOT CHANGE*******************************/
// Declare pin mode for the single digital input
void setup()
{
  pinMode(BUTTON_MODE_PIN, INPUT);
// Define the output for the RGB led and Piezo
  pinMode(LED_PIN_R, OUTPUT);  
  pinMode(LED_PIN_G, OUTPUT);
  pinMode(LED_PIN_B, OUTPUT);
  pinMode(BUZZER_PIN,OUTPUT);
// Define the console window for debugging
  Serial.begin(115200);
  while(!Serial); 
}

/**********************LOOP() DO NOT CHANGE *******************************
 * INSTRUCTIONS: 
 * There is NO NEED to change the loop - it establishes the flow of the program
 * We call here 3 functions repeatedly:
 * 1: chooseMode(): this function will determine the mode that your program is in 
 * based on if the button (linked to the BUTTON_MODE_PIN) was pressed
 * 2: setRGB(): will set the color of the RGB LED based on the value of the mode variable
 * 3: selectMode(): will determine which function to call based on the value of the mode variable

**************************************************************************/
void loop()
{
  chooseMode();
  setRGB(mode);
  selectMode();
}
/******************CHOOSEMODE(): IMPLEMENT *********************************
 * INSTRUCTIONS:
 * Read the value from the Button (linked to the BUTTON_MODE_PIN) and 
 * if is being pressed then change the mode variable.
 * REMEMBER:
 * mode == 0 is reset 
 * mode == 1 is live
 * mode == 2 is record
 * mode == 3 is play
 * mode == 4 is loopMode
 * Every time the user presses the button, the program will go to the next mode,
 * once it reaches 4, it should go back to mode == 0. 
 * (i.e. if mode ==2 and we press, then mode ==3) ...
**************************************************************************/
void chooseMode(){
// Since the button is connected to 2 on the digital side, we say, DigitalRead
// If the button is pressed (HIGH)... 
if (digitalRead(BUTTON_MODE_PIN) == HIGH){
  // and if the mode value is less than 4
  if (mode < 4){
  // add 1 to the value of mode
    mode++;
  }
  else{
    // reset the mode back to a value of 0
    mode = 0;
  }
  // run the code only once whenever the button is pressed
  delay(1000);
}
}

/******************SETRGB(): IMPLEMENT *********************************
 * INSTRUCTIONS:
 * Depending on the value of the mode variable:
 * if the mode is 0 - RGB LED IS OFF
 * if the mode is 1 - RGB LED IS BLUE
 * if mode is 2 - RGB LED IS RED
 * if mode is 3 - RGB LED IS GREEN
 * if mode is 4 - RGB LED iS PURPLE
 * YOU MUST USE A SWITCH CASE CONSTRUCT (NOT A SERIES OF IF / ELSE STATEMENTS
**************************************************************************/

// Define the colors to display in the RGB light for each mode
void setRGB(int modeButtonColor)
{
  switch(modeButtonColor){
    
   case 0:
    digitalWrite(LED_PIN_R,0);
    digitalWrite(LED_PIN_G,0);
    digitalWrite(LED_PIN_B,0);
    break;
    
   case 1:
    digitalWrite(LED_PIN_R,255);
    digitalWrite(LED_PIN_G,0);
    digitalWrite(LED_PIN_B,0);
    break;

   case 2:
    digitalWrite(LED_PIN_R,0);
    digitalWrite(LED_PIN_G,0);
    digitalWrite(LED_PIN_B,255);
    break;
    
   case 3:
    digitalWrite(LED_PIN_R,0);
    digitalWrite(LED_PIN_G,255);
    digitalWrite(LED_PIN_B,0);
    break;
    
   case 4:
    digitalWrite(LED_PIN_R,102);
    digitalWrite(LED_PIN_G,12);
    digitalWrite(LED_PIN_B,125);
    break;
  }
}
/**********************SELECTMODE() DO NOT CHANGE *******************************
 * INSTRUCTIONS: 
 * There is NO NEED to change this function - it selects WHICH function should run based on the mode variable
 * There are 4 possibilities
 * 1: reset(): this function will reset any arrays etc, and will do nothing else
 * 2: live(): this function will play the corresponding notes 
 * to the user pressing the respective buttons. 
 * NOTE:: the notes played are NOT stored
 * 3: record(): this function will play the corresponding notes 
 * to the user pressing the respective buttons
 * AND will STORE up to 16 consecutive notes in an array.
 * 4: play(): this function will playback any notes stored in the array that were recorded
 * in the previous mode
 * 5: loopMode(): this function will playback any notes stored in the array that were recorded, 
 * BUT unlike the previous mode, you can choose in which sequence the notes are played.
 * REQUIRED: only play notes from the array (no live stuff)

******************************************************************************/
void selectMode()
{
  if(mode == 0) { 
    reset();
  }
  else if(mode == 1) {
    live();
  }
  else if(mode == 2) {
    record();
  }
  
  else if(mode == 3) {
    play();
  }
   
   else if(mode == 4) {
    looper();
  }
}
/******************RESET(): IMPLEMENT **************************************
 * INSTRUCTIONS:
 * this function should ensure that any notes recorded are no longer available
**************************************************************************/

// The for loop will go through the maximum notes until 16 and 
// resets the value of the array to the initial value (0)
// therefore, there is free again to record a new set of notes
void reset()
{
  for (int i = 0; i < MAX_NOTES; i++){
    notes [i] = 0;
    countNotes = 0;
  }  
}

/******************LIVE(): IMPLEMENT **************************************
 * INSTRUCTIONS:
 * this function will play the corresponding notes 
 * to the user pressing the respective buttons
 * NOTE:: the notes played are NOT stored
 * SO: you need read in the input from the analog input (linked to the button-resistor ladder combo)
 * THEN - output the note to the buzzer using the tone() function
**************************************************************************/

// Once the buttons are pressed, the tones from the buttons are sent to Piezzo through the A0 pin
void live()
{
  tone(BUZZER_PIN, analogRead(NOTE_IN_PIN), duration);
}
/******************RECORD(): IMPLEMENT **********************************
 * INSTRUCTIONS:
 * this function will play the corresponding notes 
 * to the user pressing the respective buttons
 * AND will STORE up to 16 consecutive notes in an array.
 * SO:you need read in the input from the analog input (linked to the button-resistor ladder combo)
 * AND - output the note to the buzzer using the tone() function
 * THEN store that note in the array  - BE CAREFUL - you can only allow for up to MAX_NOTES to be stored
**************************************************************************/
void record()
{
  // As long as the number of notes being played has not reached to maximum # of notes (16)
  while (countNotes < MAX_NOTES){
    delay(2000);
    // play the tone
    tone(BUZZER_PIN, analogRead(NOTE_IN_PIN), duration);
    // store the played note in the array
    notes[countNotes] = {analogRead(NOTE_IN_PIN)};
    // go to the next element of the array
    countNotes += 1; 
  }
}
/******************PLAY(): IMPLEMENT ************************************
 * INSTRUCTIONS:
 * this function will playback any notes stored in the array that were recorded
 * in the previous mode
 * SO: you need to go through the array of values (be careful - the user may not have put in MAX_NOTES)
 * READ each value IN ORDER
 * AND output each note to the buzzer using the tone() function
 * ALSO: as long as we are in this mode, the notes are played over and over again
 * BE CAREFUL: make sure you allow for the user to get to another mode from the mode button...
**************************************************************************/
void play()
{
  for (int i = 0; i < MAX_NOTES; i++){
    tone(BUZZER_PIN, notes[i], duration);
    delay(duration);
  }
  delay(duration*3);
    if (digitalRead(BUTTON_MODE_PIN) == HIGH){
      noTone(BUZZER_PIN);
    }
}
/******************LOOPMODE(): IMPLEMENT *********************************
 * INSTRUCTIONS:
 * this function will playback any notes stored in the array that were recorded
 * in the previous mode
 * SO: you need to go through the array of values (be careful - the user may not have put in MAX_NOTES)
 * READ values IN ANY ORDERING (You MUST use the array - but you can determine your own sequence)
 * AND output each note to the buzzer using the tone() function
 * ALSO: as long as we are in this mode, the notes are played over and over again
 * BE CAREFUL: make sure you allow for the user to get to another mode from the mode button...
**************************************************************************/

// Assistance from Zahra Ahmadi *

void looper()
{
  // CODE TO RANDOMIZE THE ORDER OF THE NOTES IN THE ARRAY
  // verify if the condition for the random generated number is true or false
  boolean randomAlreadyExists = false;
    
  while (j < MAX_NOTES) {
    // store the new random generated number
    int newRandom = random(1, 16);
    // the condition makes sure that the new random number is not repetitive  
    for (int i= 1; i < MAX_NOTES; i++){
        if (newRandom == randomRepCheck[i]) {
        // If it is repetitive, change the state of the boolean
        randomAlreadyExists = true;
        break;
        }
       }

    // if the boolean is false   
    if (!randomAlreadyExists) {
        // assign the unrepeated numbers to the mainRandomNumber array
        mainRandomNumber[j] = newRandom;
        // also assign it to the randomRepCheck, since this verifies the repetitiveness
        randomRepCheck[j] = newRandom;
        // move to the next element 
        j++;
        }
        // reset the value of the boolean to default
        randomAlreadyExists = false;
       }

  // PLAY THE RECORDED NOTES IN THE ORDER DETERMINED ABOVE
    for (int k = 0; k < MAX_NOTES; k++) {
      // Make sure that the pauses won't be played (0)  
      if (notes[mainRandomNumber[k]] != 0) {
        tone(BUZZER_PIN, notes[mainRandomNumber[k]], duration);
        delay(duration);
        }
      }
      delay(duration);
}

/************************************************************************** 

Provide an analysis of the observed behavior of the resistor ladder (keyboard), mode selector and what is occurring on the Arduino as a voltage. How does the input become audible sound?

The circuit has 5 buttons in total. Four of them act as a keyboard which is used to play the tones while the fifth one is designated to be used as a mode controller (reset, live, 
record, play and looper). The four buttons (keyboard) are connected using a resistor ladder (the resistors are in series circuit position). Therefore, there is no need to connect 
each button to a different analog to digital converter. Instead, there are all connected to the A0 pin. 

A voltage divider is created due to the resistor ladder. This way, each button is delivering its own unique voltage to the analog A0 pin. In the resistor ladder, since the primary 
resistors' resistance value is being added to the following ones, the further the buttons would be from the reference voltage, the less voltage they can send to the Arduino. 
Therefore, each keyboard button press is delivering just a fraction from the total voltage of 5V. 

With each mode selector, the colour of the RGB LED light changes in order to convey which mode the user is on. With each mode selection, the output changes as each mode is 
designed with its own function. For example, the record mode will let you play the tones while the play button will playback the tones that were recorded. 

The input from the keyboard buttons is read from the analog input is converted into notes through the tones() function. Then, the note is outputted as sound 
through the Piezo. With the maximum of 16 tones that can be played each time, the use of the array and randomization creates a variety in the audible sound. 
Specially, in the looper. Mechanically speaking, “[the piezo works] by using a piezo crystal, a special material that changes shape when voltage is applied to it. 
If the crystal pushes against a diaphragm, like a tiny speaker cone, it can generate a pressure wave which the human ear picks up as sound” 
(Adafruit - https://learn.adafruit.com/using-piezo-buzzers-with-circuitpython-arduino). 

**************************************************************************/
