void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  for(int i = 2; i < 16; i++)
    pinMode(i, OUTPUT);
}

int index = 2;
long last = 0;
void loop() {
  long sum = 0;
  for(int i=0; i<300; i++)
    sum += analogRead(2);
  Serial.println(sum / 300);

  
  if(millis() - last > 300){
    light(index);
    index++;
    last = millis();
    if(index >= 16)
      index = 2;
  }
}

void light(int pin){
  for(int i = 2; i < 16; i++){
    if(i == pin)
      digitalWrite(i, HIGH);
    else
      digitalWrite(i, LOW);
  }
}

