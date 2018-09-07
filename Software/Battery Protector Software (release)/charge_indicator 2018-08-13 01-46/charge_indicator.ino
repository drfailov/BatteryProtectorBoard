int MODE_NORMAL = 0;
int MODE_ENABLING = 1;
int MODE_DISABLING = 2;
int MODE_DISABLED = 3;
int MODE_OVERVOLTAGE = 4;
int MODE_DISCHARGED = 5;
int MODE_CALIBRATION_HIGH = 6;
int MODE_CALIBRATION_LOW = 7;
int MODE_PRE_CALIBRATION = 8;
int MODE_SET_TIMER = 9;

int currentMode = MODE_NORMAL;




void setup() {
  Serial.begin(9600);
  Serial.println(F("Hello!:)"));
  Serial.print(F("Software version: "));
  Serial.print(__DATE__);
  Serial.print(" ");
  Serial.println(__TIME__);
  Serial.println(F("Loading..."));
  initLed();
  initButton();
  initVoltage();
  initMosfet();
  initTimer();  

  //Просто анимация
  for(int i=0; i<100; i++){
    ledPercent(i);
    delay(4);
  }
  //delay(50);


  if(isButtonPressed()){
    setPreCalibrationMode();
  }
  else{
    setNormalMode();
  }
  Serial.println(F("Ready."));
}

void loop() {
  if(currentMode == MODE_NORMAL)
    modeNormalLoop();  
  else if(currentMode == MODE_ENABLING)
    modeEnablingLoop();  
  else if(currentMode == MODE_DISABLING)
    modeDisablingLoop();  
  else if(currentMode == MODE_DISABLED)
    modeDisabledLoop();  
  else if(currentMode == MODE_OVERVOLTAGE)
    modeOvervoltageLoop();  
  else if(currentMode == MODE_DISCHARGED)
    modeDischargedLoop();  
  else if(currentMode == MODE_CALIBRATION_HIGH)
    modeCalibrationHighLoop();  
  else if(currentMode == MODE_CALIBRATION_LOW)
    modeCalibrationLowLoop();  
  else if(currentMode == MODE_PRE_CALIBRATION)
    modePreCalibrationLoop();  
  else if(currentMode == MODE_SET_TIMER)
    modeSetTimerLoop();  
  delay(1);
}

void onButtonDown(){
  Serial.println(F("Button down"));
  if(currentMode == MODE_NORMAL)
    modeNormalButtonDown();  
  else if(currentMode == MODE_ENABLING)
    modeEnablingButtonDown();  
  else if(currentMode == MODE_DISABLING)
    modeDisablingButtonDown();  
  else if(currentMode == MODE_DISABLED)
    modeDisabledButtonDown();  
  else if(currentMode == MODE_OVERVOLTAGE)
    modeOvervoltageButtonDown();  
  else if(currentMode == MODE_DISCHARGED)
    modeDischargedButtonDown();  
  else if(currentMode == MODE_CALIBRATION_HIGH)
    modeCalibrationHighButtonDown();  
  else if(currentMode == MODE_CALIBRATION_LOW)
    modeCalibrationLowButtonDown();  
  else if(currentMode == MODE_PRE_CALIBRATION)
    modePreCalibrationButtonDown(); 
  else if(currentMode == MODE_SET_TIMER)
    modeSetTimerButtonDown();  
}
void onButtonUp(){
  Serial.println(F("Button up"));
  if(currentMode == MODE_NORMAL)
    modeNormalButtonUp();  
  else if(currentMode == MODE_ENABLING)
    modeEnablingButtonUp();  
  else if(currentMode == MODE_DISABLING)
    modeDisablingButtonUp();  
  else if(currentMode == MODE_DISABLED)
    modeDisabledButtonUp();  
  else if(currentMode == MODE_OVERVOLTAGE)
    modeOvervoltageButtonUp();  
  else if(currentMode == MODE_DISCHARGED)
    modeDischargedButtonUp();  
  else if(currentMode == MODE_CALIBRATION_HIGH)
    modeCalibrationHighButtonUp();  
  else if(currentMode == MODE_CALIBRATION_LOW)
    modeCalibrationLowButtonUp();  
  else if(currentMode == MODE_PRE_CALIBRATION)
    modePreCalibrationButtonUp();  
  else if(currentMode == MODE_SET_TIMER)
    modeSetTimerButtonUp();  
}

void setNormalMode(){
  Serial.println(F("Normal mode"));
  currentMode = MODE_NORMAL;
  modeNormalSetup();
}

void setEnablingMode(){
  Serial.println(F("Enabling mode"));
  currentMode = MODE_ENABLING;
  modeEnablingSetup();
}

void setDisablingMode(){
  Serial.println(F("Disabling mode"));
  currentMode = MODE_DISABLING;
  modeDisablingSetup();
}

void setDisabledMode(){
  Serial.println(F("Disabled mode"));
  currentMode = MODE_DISABLED;
  modeDisabledSetup();
}

void setOvervoltageMode(){
  Serial.println(F("Overvoltage mode"));
  currentMode = MODE_OVERVOLTAGE;
  modeOvervoltageSetup();
}

void setDischargedMode(){
  Serial.println(F("Discharged mode"));
  currentMode = MODE_DISCHARGED;
  modeDischargedSetup();
}

void setCalibrationHighMode(){
  Serial.println(F("Calibration high mode"));
  currentMode = MODE_CALIBRATION_HIGH;
  modeCalibrationHighSetup();
}

void setCalibrationLowMode(){
  Serial.println(F("Calibration low mode"));
  currentMode = MODE_CALIBRATION_LOW;
  modeCalibrationLowSetup();
}

void setPreCalibrationMode(){
  Serial.println(F("PRE Calibration mode"));
  currentMode = MODE_PRE_CALIBRATION;
  modePreCalibrationSetup();
}

void setSetTimerMode(){
  Serial.println(F("Set Timer mode"));
  currentMode = MODE_SET_TIMER;
  modeSetTimerSetup();
}








