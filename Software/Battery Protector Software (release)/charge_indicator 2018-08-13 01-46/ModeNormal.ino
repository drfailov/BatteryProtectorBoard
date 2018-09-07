void modeNormalSetup(){
  mosfetEnable();
}

void modeNormalLoop(){
  int percent = getVoltagePercent();
  updateLeds(percent);
  if(percent <= 0)
    setDischargedMode();
  if(percent > 100)
    setOvervoltageMode();
  
  buttonLoop();
  ledLoop();
  mosfetLoop();
  voltageLoop();
  timerLoop(); 
}


void modeNormalButtonDown(){
  setDisablingMode();
}

void modeNormalButtonUp(){
  
}

void updateLeds(int percent){
  if(percent > 100)//100
    led(GREEN,BLACK,   GREEN,BLACK,   GREEN,BLACK,    GREEN,BLACK);
  else if(percent > 75)//68
    led(GREEN,GREEN,   GREEN,GREEN,   GREEN,GREEN,    GREEN,GREEN);
  else if(percent > 70)//57
    led(GREEN,GREEN,   GREEN,GREEN,   GREEN,GREEN,    GREEN,BLACK);
  else if(percent > 65)//50
    led(GREEN,GREEN,   GREEN,GREEN,   GREEN,GREEN,    BLACK,BLACK);
  else if(percent > 60)//45
    led(GREEN,GREEN,   GREEN,GREEN,   GREEN,BLACK,    BLACK,BLACK);
  else if(percent > 50)//39
    led(GREEN,GREEN,   GREEN,GREEN,   BLACK,BLACK,    BLACK,BLACK);
  else if(percent > 35)//35
    led(MAGENTA,MAGENTA,   MAGENTA,BLACK,   BLACK,BLACK,    BLACK,BLACK);
  else if(percent > 20)//30
    led(MAGENTA,MAGENTA,   BLACK,BLACK,   BLACK,BLACK,    BLACK,BLACK);
  else if(percent > 0)
    led(MAGENTA,BLACK,   BLACK,BLACK,   BLACK,BLACK,    BLACK,BLACK);
  else if(percent <= 0)
    led(MAGENTA,BLACK,   MAGENTA,BLACK,   MAGENTA,BLACK,    MAGENTA,BLACK);
}

