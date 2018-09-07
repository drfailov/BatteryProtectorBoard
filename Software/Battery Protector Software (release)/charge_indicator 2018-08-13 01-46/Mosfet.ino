int mosfet_pin = 15;
int mosfet_led_pin = 19;
long enalbedTime = -1;
bool currentMosfetState = false;
long mosfetWaitingTime = 200;//задержка в мс перед включением мосфета

void initMosfet(){
  pinMode(mosfet_pin, OUTPUT);
  digitalWrite(mosfet_pin, LOW);
  pinMode(mosfet_led_pin, OUTPUT);
  digitalWrite(mosfet_led_pin, LOW);
}

void mosfetLoop(){
  if(enalbedTime != -1 && millis() - enalbedTime > mosfetWaitingTime){ //должен быть включен
    if(currentMosfetState == false){
      digitalWrite(mosfet_pin, HIGH);
      digitalWrite(mosfet_led_pin, HIGH);
      Serial.println(F("#################### MOSFET ENABLED ####################"));
      currentMosfetState = true;
    }
  }
  else{
    if(currentMosfetState == true){
      digitalWrite(mosfet_pin, LOW);
      digitalWrite(mosfet_led_pin, LOW);
      Serial.println(F("-------------------- MOSFET DISABLED --------------------"));
      currentMosfetState = false;
    }
  }
}

void mosfetEnable(){
  if(enalbedTime == -1)
    enalbedTime = millis();
}
void mosfetDisable(){
  enalbedTime = -1;
}

