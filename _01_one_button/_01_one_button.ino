/////////////////////////////////////////////////
// This program was coded by 
// Nathan Villicana-Shaw in the fall of 2017
// for the Objects and Space class at the
// California College of the Arts
// In-class workshop #1 part 1 of 3
/////////////////////////////////////////////////


// global variables which persist throughout the entire program run-time
int button_pin = 2;
// boolean can be true or false
// this is a good choice of type to represent our button state
// as our button can be either on or off
boolean button_state = false;

// the setup function is run once when the Arduino boots
void setup() {
   // this line of code opens up a serial bus so the arduino can communicate
   // with your computer, 57600 is the baud rate and corresponds to how many bits 
   // can be sent per second over this communication bus
   Serial.begin(57600);
   // this sets the second digital pin on the Arduino up as an input to
   // read the state of the attached button
   pinMode(button_pin, INPUT); 
}

// the loop function will run infinetally after the setup loop (above) has exited
void loop() {
  // read the states of the buttons
  readButtons();
  printButtonStates();
  // wait 1/20th a second before checking the buttons again
  delay(50);
}

void readButtons() {
   button_state = digitalRead(button_pin);
}

void printButtonStates() {
   // print the state of the button over the serial port
   Serial.print(button_state);
   // this will enter in a newline character
   Serial.println(); 
}
