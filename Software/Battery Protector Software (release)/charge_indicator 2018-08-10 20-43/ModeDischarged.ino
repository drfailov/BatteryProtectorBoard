void modeDischargedSetup(){
  mosfetDisable();
  led(MAGENTA,BLACK,     MAGENTA,BLACK,     MAGENTA,BLACK,     MAGENTA,BLACK);
}

void modeDischargedLoop(){
  buttonLoop();
  ledLoop();
  mosfetLoop();
  voltageLoop();
}


void modeDischargedButtonDown(){
  
}


void modeDischargedButtonUp(){
  
}
