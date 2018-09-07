

void modeCalibrationHighSetup(){
  led(BLUE,BLUE,     BLUE,BLUE,     BLUE,BLUE,     BLUE,GREEN);
}

void modeCalibrationHighLoop(){
  buttonLoop();
  ledLoop();
  mosfetLoop();
  voltageLoop();
}


void modeCalibrationHighButtonDown(){
  ledWaitFor(5, CYAN);
  calibrateMaximumVoltage();
  setCalibrationLowMode();
}


void modeCalibrationHighButtonUp(){
  
}
