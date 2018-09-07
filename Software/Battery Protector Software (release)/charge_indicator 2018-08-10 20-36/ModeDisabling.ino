long startDisablingTime = 0;
long disableThreshold = 1000; //время, сколько нужно держать чтобы выключить

void modeDisablingSetup(){
  startDisablingTime = millis();
}

void modeDisablingLoop(){
  long time = millis();
  long pressingTime = time - startDisablingTime;
  long pressingPercent = 100L * pressingTime / disableThreshold;
  ledPercent(100 - pressingPercent);
  if(pressingPercent > 100)
    setDisabledMode();

    
  buttonLoop();
  ledLoop();
  mosfetLoop();
  voltageLoop();
}


void modeDisablingButtonDown(){
  
}


void modeDisablingButtonUp(){
  setNormalMode();
}
