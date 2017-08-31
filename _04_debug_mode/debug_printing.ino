void dprint(String msg) {
  // if the variable "debug" is equal to "true" the string passed into
  // this function will be printed to the console monitor
  if (DEBUG) {
    Serial.print(msg); 
  }
}
void dprintln(String msg) {
  if (DEBUG) {
    Serial.println(msg); 
  }
}
