int timer_led_pin = 18;
long timerLEDblinkPeriod = 5000; //ms
long timerLEDblinkOffDuration = 100; //ms
long timerLEDblinkOnDuration = 200; //ms
int  timerLEDblinkTimes = 3; //сколько раз надо мигнуть
boolean timerLEDcurrentLedState = true;
int timerLEDcurrentBlink = 0; //0 ... 3 number of blink for current loop
long timerLEDlastActionTime = 0; //time when led changed state last time
boolean ledEnabled = false;

//Задача в целом: мигать быстро по 3 раза с паузами в 5 секунд.
//Примерно так:
//#####################################--####--####--#####################################--####--####--#####################################--####--####--

void initTimerLed(){
  pinMode(timer_led_pin, OUTPUT); 
  digitalWrite(timer_led_pin, LOW);
  timerLEDcurrentLedState = false;
  ledEnabled = false;
}

void timerLedLoop(){
  //если выключен
  if(ledEnabled == false){
    if(timerLEDcurrentLedState == true){
      Serial.println(F("Timer led OFF"));
      digitalWrite(timer_led_pin, LOW);
      timerLEDcurrentLedState = false;
    }
    return;
  }
  long timeAgo = millis() - timerLEDlastActionTime;
  if(timerLEDcurrentBlink >= timerLEDblinkTimes && timeAgo > timerLEDblinkPeriod)
    timerLEDcurrentBlink = 0;
  if(timerLEDcurrentBlink < timerLEDblinkTimes){
    if(timerLEDcurrentLedState == true && timeAgo > timerLEDblinkOnDuration){ //надо выключить
      timerLEDlastActionTime = millis();
      timerLEDcurrentLedState = false;
      digitalWrite(timer_led_pin, LOW);
      Serial.println(F("Timer led OFF"));
    }
    else if(timerLEDcurrentLedState == false && timeAgo > timerLEDblinkOffDuration){ //надо включить
      timerLEDlastActionTime = millis();
      timerLEDcurrentLedState = true;
      digitalWrite(timer_led_pin, HIGH);
      Serial.println(F("Timer led ON"));
      timerLEDcurrentBlink ++;
    }
  }
}

void timerLedEnable(int numberOfBlinks){
  if(!ledEnabled){ //если уже включено, только обновить количество миганий
    ledEnabled = true;
    timerLEDcurrentBlink = numberOfBlinks;
    timerLEDlastActionTime = millis();
    timerLEDcurrentLedState = true;
    Serial.println(F("Timer led ENABLED"));  
    digitalWrite(timer_led_pin, HIGH);
  }
  timerLEDblinkTimes = numberOfBlinks;
}

void timerLedDisable(){
  ledEnabled = false;
}

