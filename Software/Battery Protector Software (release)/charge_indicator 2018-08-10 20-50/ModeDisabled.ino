boolean buttonPressed = false;
long startDisabledTime = 0;
long timerThreshold = 5000; //ms

void modeDisabledSetup(){
  mosfetDisable();
  led(BLACK,BLACK,BLACK,BLUE);
  buttonPressed = isButtonPressed();
  startDisabledTime = millis();
}

void modeDisabledLoop(){
  buttonLoop();
  ledLoop();
  mosfetLoop();
  voltageLoop();

  //если мы держим кнопку уже больше 5 секунд
  if(buttonPressed && millis() - startDisabledTime > timerThreshold){
    setSetTimerMode();
  }
}


void modeDisabledButtonDown(){
  setEnablingMode();
}


void modeDisabledButtonUp(){
  buttonPressed = false;
}
