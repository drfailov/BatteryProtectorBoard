int RED = 0;
int BLUE = 1;
int GREEN = 2;
int CYAN = 3;
int MAGENTA = 4;
int YELLOW = 5;
int WHITE = 6;
int BLACK = 7;

int led1R_pin = 12;
int led1G_pin = 13;
int led1B_pin = 11;
int led2R_pin = 8;
int led2G_pin = 9;
int led2B_pin = 10;
int led3R_pin = 7;
int led3G_pin = 5;
int led3B_pin = 6;
int led4R_pin = 3;
int led4G_pin = 4;
int led4B_pin = 2;


//Этот блок нужен для того, чтобы реализовать мигание диодами.
//Нам достаточно задать два разных цвета для каждого диода и он будет мигать между ними
long lastTick = 0;
long blinkPeriod = 400;
int color = 1;//какой набор цветов сейчас
int led1_color1 = BLACK;
int led2_color1 = BLACK;
int led3_color1 = BLACK;
int led4_color1 = BLACK;
int led1_color2 = BLACK;
int led2_color2 = BLACK;
int led3_color2 = BLACK;
int led4_color2 = BLACK;


void initLed(){
  pinMode(led1R_pin, OUTPUT);
  pinMode(led1G_pin, OUTPUT);
  pinMode(led1B_pin, OUTPUT);
  pinMode(led2R_pin, OUTPUT);
  pinMode(led2G_pin, OUTPUT);
  pinMode(led2B_pin, OUTPUT);
  pinMode(led3R_pin, OUTPUT);
  pinMode(led3G_pin, OUTPUT);
  pinMode(led3B_pin, OUTPUT);
  pinMode(led4R_pin, OUTPUT);
  pinMode(led4G_pin, OUTPUT);
  pinMode(led4B_pin, OUTPUT);
}

void ledLoop(){
  if(millis() - lastTick > blinkPeriod){
    if(color == 1){
      led1(led1_color2);
      led2(led2_color2);
      led3(led3_color2);
      led4(led4_color2);
      color = 2;
    }
    else if(color == 2){
      led1(led1_color1);
      led2(led2_color1);
      led3(led3_color1);
      led4(led4_color1);
      color = 1;
    }
    lastTick = millis();
  }
}

void ledWaitFor(int sec, int color){
  long started = millis();
  int ledn = 1;
  while(millis() - started < sec * 1000){
    if(ledn == 1)
      led(color, BLACK, BLACK, BLACK);
    if(ledn == 2)
      led(BLACK, color, BLACK, BLACK);
    if(ledn == 3)
      led(BLACK, BLACK, color, BLACK);
    if(ledn == 4)
      led(BLACK, BLACK, BLACK, color);
    
    delay(100);
    ledn ++;
    if(ledn > 4)
      ledn = 1;
  }
}

void ledPercent(int percent){
  int FIRST = RED;
  int SECOND = YELLOW;
  while(percent > 100)
    percent -= 100;
  if(percent > 96) led(SECOND, SECOND, SECOND, SECOND);
  else if(percent > 84) led(SECOND, SECOND, SECOND, FIRST);
  else if(percent > 72) led(SECOND, SECOND, FIRST, FIRST);
  else if(percent > 60) led(SECOND, FIRST, FIRST, FIRST);
  else if(percent > 48) led(FIRST, FIRST, FIRST, FIRST);
  else if(percent > 36) led(FIRST, FIRST, FIRST, BLACK);
  else if(percent > 24) led(FIRST, FIRST, BLACK, BLACK);
  else if(percent > 12) led(FIRST, BLACK, BLACK, BLACK);
  else if(percent > 0) led(BLACK, BLACK, BLACK, BLACK);
}


void ledPercentOld(int percent){
  while(percent > 200)
    percent -= 200;
  if(percent > 200) led(GREEN, BLACK, BLACK, BLACK);
  else if(percent > 188) led(BLACK, BLACK, BLACK, BLACK);
  else if(percent > 180) led(BLACK, BLACK, BLACK, BLUE);
  else if(percent > 172) led(BLACK, BLACK, BLACK, YELLOW);
  else if(percent > 164) led(BLACK, BLACK, BLACK, WHITE);
  else if(percent > 156) led(BLACK, BLACK, BLUE, WHITE);
  else if(percent > 148) led(BLACK, BLACK, YELLOW, WHITE);
  else if(percent > 140) led(BLACK, BLACK, WHITE, WHITE);
  else if(percent > 132) led(BLACK, BLUE, WHITE, WHITE);
  else if(percent > 124) led(BLACK, YELLOW, WHITE, WHITE);
  else if(percent > 116) led(BLACK, WHITE, WHITE, WHITE);
  else if(percent > 108) led(BLUE, WHITE, WHITE, WHITE);
  else if(percent > 100) led(YELLOW, WHITE, WHITE, WHITE);
  else if(percent > 96) led(WHITE, WHITE, WHITE, WHITE);
  else if(percent > 88) led(WHITE, WHITE, WHITE, YELLOW);
  else if(percent > 80) led(WHITE, WHITE, WHITE, RED);
  else if(percent > 72) led(WHITE, WHITE, WHITE, BLACK);
  else if(percent > 64) led(WHITE, WHITE, YELLOW, BLACK);
  else if(percent > 56) led(WHITE, WHITE, RED, BLACK);
  else if(percent > 48) led(WHITE, WHITE, BLACK, BLACK);
  else if(percent > 40) led(WHITE, YELLOW, BLACK, BLACK);
  else if(percent > 32) led(WHITE, RED, BLACK, BLACK);
  else if(percent > 24) led(WHITE, BLACK, BLACK, BLACK);
  else if(percent > 16) led(YELLOW, BLACK, BLACK, BLACK);
  else if(percent > 8) led(RED, BLACK, BLACK, BLACK);
  else if(percent > 0) led(BLACK, BLACK, BLACK, BLACK);
}

void led(int l1c1, int l1c2, int l2c1, int l2c2, int l3c1, int l3c2, int l4c1, int l4c2){
  led1_color1 = l1c1;
  led2_color1 = l2c1;
  led3_color1 = l3c1;
  led4_color1 = l4c1;
  led1_color2 = l1c2;
  led2_color2 = l2c2;
  led3_color2 = l3c2;
  led4_color2 = l4c2;
}

void led(int c1, int c2, int c3, int c4){
  led1_color1 = c1;
  led2_color1 = c2;
  led3_color1 = c3;
  led4_color1 = c4;
  led1_color2 = c1;
  led2_color2 = c2;
  led3_color2 = c3;
  led4_color2 = c4;
  led1(c1);
  led2(c2);
  led3(c3);
  led4(c4);
}
void led1(int color){
  digitalWrite(led1R_pin, (color == RED || color == YELLOW || color == MAGENTA || color == WHITE?HIGH:LOW));
  digitalWrite(led1G_pin, (color == GREEN || color == YELLOW || color == CYAN || color == WHITE?HIGH:LOW));
  digitalWrite(led1B_pin, (color == BLUE || color == CYAN || color == MAGENTA || color == WHITE?HIGH:LOW));
}
void led2(int color){
  digitalWrite(led2R_pin, (color == RED || color == YELLOW || color == MAGENTA || color == WHITE?HIGH:LOW));
  digitalWrite(led2G_pin, (color == GREEN || color == YELLOW || color == CYAN || color == WHITE?HIGH:LOW));
  digitalWrite(led2B_pin, (color == BLUE || color == CYAN || color == MAGENTA || color == WHITE?HIGH:LOW));
}
void led3(int color){
  digitalWrite(led3R_pin, (color == RED || color == YELLOW || color == MAGENTA || color == WHITE?HIGH:LOW));
  digitalWrite(led3G_pin, (color == GREEN || color == YELLOW || color == CYAN || color == WHITE?HIGH:LOW));
  digitalWrite(led3B_pin, (color == BLUE || color == CYAN || color == MAGENTA || color == WHITE?HIGH:LOW));
}
void led4(int color){
  digitalWrite(led4R_pin, (color == RED || color == YELLOW || color == MAGENTA || color == WHITE?HIGH:LOW));
  digitalWrite(led4G_pin, (color == GREEN || color == YELLOW || color == CYAN || color == WHITE?HIGH:LOW));
  digitalWrite(led4B_pin, (color == BLUE || color == CYAN || color == MAGENTA || color == WHITE?HIGH:LOW));
}
