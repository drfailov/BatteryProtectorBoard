long timerStartTime = -1; //-1 = disabled
long timerTime = -1; //-1 = disabled
long lastTimerLog = 0;


void initTimer(){
  initTimerLed();
  timerStartTime = -1;
  timerTime = -1;  
}

void timerLoop(){
  timerLedLoop();
  if(timerStartTime == -1)//если выключен
    return;
  long passed = millis() - timerStartTime;
  long remaining = timerTime - passed;
  if(millis() - lastTimerLog > 30000){
    Serial.print("Timer remaining: ");
    printTime(remaining);
    lastTimerLog = millis();
  }
  long min1 = 1000L*60L*1L;
  long min5 = 1000L*60L*5L;
  long min10 = 1000L*60L*10L;
  long min20 = 1000L*60L*20L;
  long min40 = 1000L*60L*40L;
  if(remaining <= 0){
    timerStartTime = -1;
    timerTime = -1;  
    Serial.println(F("Timer is out."));
    timerLedDisable();
    setDisabledMode();
  }
  else if(remaining < min1){
    timerLedEnable(8);
  }
  else if(remaining < min5){
    timerLedEnable(4);
  }
  else if(remaining < min10){
    timerLedEnable(3);
  }
  else if(remaining < min20){
    timerLedEnable(2);
  }
  else{
    timerLedEnable(1);
  }
}

void cancelTimer(){
  timerStartTime = -1;
  timerTime = -1;  
  Serial.println(F("Timer cancelled."));
  timerLedDisable();
}
void setTimer(long timeMs){  //-1 = off
  if(timeMs == -1){
    timerStartTime = -1;
    timerTime = -1;  
    Serial.println(F("Timer disabled."));
    timerLedDisable();
    setNormalMode();
    return;
  }
  
  timerStartTime = millis();
  timerTime = timeMs;
  Serial.print(F("Timer set for "));
  printTime(timeMs);
  setNormalMode();
}


void printTime(long ms){
  if(ms < 1000L*60L){
    Serial.print(ms / 1000L);
    Serial.println(" seconds.");
  }
  else if(ms < 1000L*60L*60L){
    Serial.print(ms / 60000L);
    Serial.println(" minutes.");
  }
  else {
    Serial.print(ms / 3600000L);
    Serial.println(" hours.");
  }
}

