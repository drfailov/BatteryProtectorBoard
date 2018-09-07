long startEnablingTime = 0;
long enableThreshold = 1000; //время, сколько нужно держать чтобы выключить

void modeEnablingSetup(){
  startEnablingTime = millis();
  Serial.print("startEnablingTime: ");Serial.println(startEnablingTime);
}

void modeEnablingLoop(){
  long pressingTime = millis() - startEnablingTime;
  Serial.print("Pressing time: ");Serial.println(pressingTime);
  long pressingPercent = 100 * pressingTime / enableThreshold;
  ledPercent(pressingPercent);
  if(pressingPercent > 100)
    setNormalMode();
    
  buttonLoop();
  ledLoop();
  mosfetLoop();
  voltageLoop();
}


void modeEnablingButtonDown(){
  
}


void modeEnablingButtonUp(){
  setDisabledMode();
}

