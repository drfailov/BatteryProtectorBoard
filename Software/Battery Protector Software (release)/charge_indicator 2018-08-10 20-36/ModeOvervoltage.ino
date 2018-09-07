void modeOvervoltageSetup(){
  mosfetDisable();
  led(GREEN,BLACK,     GREEN,BLACK,     GREEN,BLACK,     GREEN,BLACK);
}

void modeOvervoltageLoop(){
  buttonLoop();
  ledLoop();
  mosfetLoop();
  voltageLoop();
}


void modeOvervoltageButtonDown(){
  
}


void modeOvervoltageButtonUp(){
  
}

