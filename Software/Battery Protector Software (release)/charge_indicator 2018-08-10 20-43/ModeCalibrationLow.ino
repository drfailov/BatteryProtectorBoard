void modeCalibrationLowSetup(){
  led(BLUE,RED,     BLUE,BLUE,     BLUE,BLUE,     BLUE,BLUE);
}

void modeCalibrationLowLoop(){
  buttonLoop();
  ledLoop();
  mosfetLoop();
  voltageLoop();
}


void modeCalibrationLowButtonDown(){
  ledWaitFor(5, MAGENTA);
  calibrateMinimumVoltage();
  setNormalMode();
  
}


void modeCalibrationLowButtonUp(){
  
}
