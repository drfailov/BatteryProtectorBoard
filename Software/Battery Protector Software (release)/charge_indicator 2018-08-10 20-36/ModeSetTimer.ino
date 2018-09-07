long lastAction = -1;
long buttonDownTime = -1; //-1 = не нажата

int timerAmount = 1;
int TIMER_OFF = 0;
int TIMER_5M = 1;
int TIMER_10M = 2;
int TIMER_20M = 3;
int TIMER_40M = 4;
int TIMER_1H = 5;
int TIMER_2H = 6;
int TIMER_4H = 7;
int TIMER_8H = 8;


void modeSetTimerSetup(){
  lastAction = millis();
  updateLed();
}

void modeSetTimerLoop(){
  buttonLoop();
  ledLoop();
  mosfetLoop();
  voltageLoop();
  if(millis() - lastAction > 30000L){
    Serial.println("Set timer mode exited after 30 seconds of inactivity");
  }
}


void modeSetTimerButtonDown(){
  buttonDownTime = millis();
  lastAction = millis();
}


void modeSetTimerButtonUp(){
  lastAction = millis();
  if(millis() - buttonDownTime < 2000){
    //короткое нажатие
    Serial.println("Short press");
    timerAmount ++;
    if(timerAmount > 8)
      timerAmount = 0;
  }
}

void updateLed(){
  if(timerAmount == TIMER_OFF)
    led(RED, RED, RED, RED);
  else if(timerAmount == TIMER_5M)
    led(MAGENTA, RED, RED, RED);
  else if(timerAmount == TIMER_10M)
    led(RED, MAGENTA, RED, RED);
  else if(timerAmount == TIMER_20M)
    led(RED, RED, MAGENTA, RED);
  else if(timerAmount == TIMER_40M)
    led(RED, RED, RED, MAGENTA);
  else if(timerAmount == TIMER_1H)
    led(YELLOW, RED, RED, RED);
  else if(timerAmount == TIMER_2H)
    led(RED, YELLOW, RED, RED);
  else if(timerAmount == TIMER_4H)
    led(RED, RED, YELLOW, RED);
  else if(timerAmount == TIMER_8H)
    led(RED, RED, RED, YELLOW);
}

