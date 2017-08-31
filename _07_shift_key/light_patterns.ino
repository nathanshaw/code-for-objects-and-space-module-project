void fadeIn(int pin_number, int time) {
  float fraction = time/255;
  for (int i = 0; i < 255; i++){
     analogWrite(pin_number, i);
     delay(fraction);
  }
}
