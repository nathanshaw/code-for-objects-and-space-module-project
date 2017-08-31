/////////////////////////////////////////////////
// This program was coded by 
// Nathan Villicana-Shaw in the fall of 2017
// for the Objects and Space class at the
// California College of the Arts
// In-class workshop #1 part 3 of 3
/////////////////////////////////////////////////
/*
This version of the code will only print to the console monitor once 
a change occurs on either of the two buttons. This includes a button being
pressed and a button being released. 

The code in the main loop runs much faster, allowing the program to recognize
button presses quicker.

Additionally button debouncing has been added to cut down on false positives
and false negatives.
*/

// different program states
const int STANDBY = 0;
const int RED_ALERT    = 1;
const int GREEN_ALERT  = 2;

// debug mode
const boolean debug = false;
// global variables which persist throughout the entire program run-time
const int button_pins[] = {2,3};
// boolean can be true or false
// this is a good choice of type to represent our button state
// as our button can be either on or off
boolean button_states[] = {false, false};
// we are now going to keep track of each buttons previous state
boolean last_button_states[] = {false, false};
// we need to keep track of when our buttons were last pressed
// as we will be keeping track of the number of milliseconds which passed
// we are going to use a data type which stores a higher value than a simple int
long last_button_presses[] = {0,0};
// how many milliseconds long do we want our debounce time to be?
// 50ms or 1/20th of a second is fast enough to not miss any presses
// while being slow enough to protect us from any electrical bouncing
int debounce_time = 50;

// the setup function is run once when the Arduino boots
void setup() {
   // this line of code opens up a serial bus so the arduino can communicate
   // with your computer, 57600 is the baud rate and corresponds to how many bits 
   // can be sent per second over this communication bus
   Serial.begin(57600);
   // this sets the second digital pin on the Arduino up as an input to
   // read the state of the attached button
   for (int i = 0; i < sizeof(button_pins)/sizeof(int); i++){
     pinMode(button_pins[i], INPUT); 
   }
   dprintln("finished setup loop");
}

// the loop function will run infinetally after the setup loop (above) has exited
void loop() {
  // static variables will persist through iterations through the loop
  static int PROGRAM_STATE = STANDBY;
  
  switch (state) {
    case STANDBY;
      readButtons();
      // red alert is more important than green alert
      // so we check for its conditions first
      if (button_states[0] == true) {
        state = RED_ALERT;
      }
      else if (button_states[1] == true) {
        state = GREEN_ALERT; 
      }
    case RED_ALERT;
      // print out alert message, wait 1 second and return to standby
      Serial.println("RED ALERT!!!");
      delay(1000);
      state = STANDBY;
    case GREEN_ALERT;
      // print out alert message, wait 1 second and return to standby
      Serial.println("GREEN ALERT!!!");
      delay(1000);
      state = STANDBY;
    }
}
