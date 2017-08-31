void readButtons() {
   for (int i = 0; i < sizeof(button_pins)/sizeof(int); i++){
     button_states[i] = digitalRead(button_pins[i]);
     // if our reading is different from the last reading
     if (button_states[i] != last_button_states[i] && millis() > last_button_presses[i] +
         debounce_time){
         // update the time of the last button press to now
         last_button_presses[i] = millis();
         // update the last_reading to reflect the current reading
         last_button_states[i] = button_states[i];
         // print the state of the buttons
         printButtonStates();
     }
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
