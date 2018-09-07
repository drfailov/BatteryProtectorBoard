long timerStartTime = -1; //-1 = disabled
long timerTime = -1; //-1 = disabled


void initTimer(){
  initTimerLed();
  timerStartTime = -1;
  timerTime = -1;  
}

void timerLoop(){
  timerLedLoop();
  if(timerStartTime == -1)
    return;
  long passed = millis() - timerStartTime;
  long remaining = timerTime - passed;
  if(remaining <= 0){
    timerStartTime = -1;
    timerTime = -1;  
    Serial.println("Timer is out.");
    //digitalWrite(timer_led_pin, LOW);             // LED OFF ====================
    setDisabledMode();
  }
}


void setTimer(long timeMs){  //-1 = off
  if(timeMs == -1){
    timerStartTime = -1;
    timerTime = -1;  
    Serial.println("Timer disabled.");
    //digitalWrite(timer_led_pin, LOW);      //LED OFF ================
    setNormalMode();
    return;
  }
  
  timerStartTime = millis();
  timerTime = timeMs;
  //digitalWrite(timer_led_pin, HIGH);//LED ON ======================
  Serial.print("Timer set for ");
  if(timeMs < 1000L*60L){
    Serial.print(timeMs / 1000L);
    Serial.println(" seconds.");
  }
  else if(timeMs < 1000L*60L*60L){
    Serial.print(timeMs / 60000L);
    Serial.println(" minutes.");
  }
  else {
    Serial.print(timeMs / 3600000L);
    Serial.println(" hours.");
  }
  setNormalMode();
}
