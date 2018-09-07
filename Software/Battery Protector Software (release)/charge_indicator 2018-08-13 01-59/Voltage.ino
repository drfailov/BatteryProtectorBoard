#include <EEPROM.h>

int voltage_pin = 2;//analog!
int minVoltage = 150;
int maxVoltage = 195;
int last100voltage[100];

long logPeriod = 5000;
long lastLog = 0;

void initVoltage(){
  int value = EEPROM.read(10);
  if(value != 0 && value != 255){
    minVoltage = value;
    Serial.print(F("Minimum voltage read from EEPROM: ")); Serial.println(minVoltage);
  }
  value = EEPROM.read(12);
  if(value != 0 && value != 255){
    maxVoltage = value;
    Serial.print(F("Maximum voltage read from EEPROM: ")); Serial.println(maxVoltage);
  }
  
  
  for(int i=0; i<100; i++)
    last100voltage[i] = getRawVoltage();
}

void voltageLoop(){
  //получить напряжение и добавить в массив последних 100 замеров со сдвигом массива (для усреднения)
  int voltage = getRawVoltage();
  for(int i=1; i<100; i++)
    last100voltage[i-1] = last100voltage[i];
  last100voltage[99] = voltage;

  if(millis() - lastLog > logPeriod){
    Serial.print("P=");Serial.print(getVoltagePercent());
    Serial.print(", Avg=");Serial.print(getVoltage());
    Serial.print(", Min=");Serial.print(minVoltage);
    Serial.print(", Max=");Serial.print(maxVoltage);
    Serial.println();
    Serial.flush();
    lastLog = millis();
  }
}


void calibrateMinimumVoltage(){
  setMinimumVoltage(getVoltage());
  Serial.print("Minimum voltage writed from EEPROM: "); Serial.println(minVoltage);
}

void calibrateMaximumVoltage(){
  setMaximumVoltage(getVoltage());
  Serial.print("Maximum voltage writed from EEPROM: "); Serial.println(maxVoltage);
}


void setMinimumVoltage(int voltage){
  minVoltage = voltage;
  EEPROM.write(10, voltage);
}

void setMaximumVoltage(int voltage){
  maxVoltage = voltage;
  EEPROM.write(12, voltage);
}

int getVoltagePercent(){
  int percent = 100 * (getVoltage() - minVoltage) / (maxVoltage-minVoltage);
  return percent;
}

int getVoltage(){
  //Считаем среднее из 100 последних замеров
  long sum = 0;
  for(int i=0; i<100; i++)
    sum += last100voltage[i];
  int avgVoltage = (int)(sum / 100L);
  return avgVoltage;
}

int getRawVoltage(){
  long sum = 0;
  for(int i=0; i<100; i++){
    delayMicroseconds(10);
    sum += analogRead(voltage_pin);
  }
  return (int)(sum / 100L);
}

