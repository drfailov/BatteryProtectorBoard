long precalibrationStarted = 0;

void modePreCalibrationSetup(){
  led(BLUE,BLUE,BLUE,BLUE);
  precalibrationStarted = millis();
}

void modePreCalibrationLoop(){
  buttonLoop();
  ledLoop();
  mosfetLoop();
  voltageLoop();

  //RESET
  if(millis() - precalibrationStarted > 10000){
    ledWaitFor(5, RED);
    setMinimumVoltage(150);
    setMaximumVoltage(195);
    setNormalMode();
  }
}


void modePreCalibrationButtonDown(){
  
}


void modePreCalibrationButtonUp(){
  setCalibrationHighMode();
}
