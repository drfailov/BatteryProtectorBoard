int button_pin = 14;
bool lastState = false;


void initButton(){
  pinMode(button_pin, INPUT_PULLUP);
}

void buttonLoop(){
  bool pressed = isButtonPressed();
  if(pressed && !lastState){
    onButtonDown();
  }
  else if(!pressed && lastState){
    onButtonUp();
  }
  lastState = pressed;
}





boolean isButtonPressed(){
  return digitalRead(button_pin) == LOW;
}

