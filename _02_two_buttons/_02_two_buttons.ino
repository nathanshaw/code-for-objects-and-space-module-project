/////////////////////////////////////////////////
// This program was coded by 
// Nathan Villicana-Shaw in the fall of 2017
// for the Objects and Space class at the
// California College of the Arts
// In-class workshop #1 part 2 of 3
/////////////////////////////////////////////////


// global variables which persist throughout the entire program run-time
int button_pins[] = {2,3};
// boolean can be true or false
// this is a good choice of type to represent our button state
// as our button can be either on or off
boolean button_states[] = {false, false};

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
   for (int i = 0; i < sizeof(button_pins)/sizeof(int); i++){
     button_states[i] = digitalRead(button_pins[i]);
   }
}

void printButtonStates() {
   for (int i = 0; i < sizeof(button_pins)/sizeof(int); i++){
     // print the state of the button over the serial port
     Serial.print(button_states[i]);
     Serial.print(" ");
   }
   // this will enter in a newline character
   Serial.println(); 
}
