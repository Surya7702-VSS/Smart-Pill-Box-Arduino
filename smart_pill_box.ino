#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <TimeLib.h>

const int buzzer = 11;
const int button1 = 3;
const int button2 = 4;
const int button3 = 5;
const int button4 = 6;
const int button5 = 7;
const int Led1 = 10;
const int Led2 = 9;
int H, M, S, D, Month,  Y;
int hh=0, mm=0, ss=0;
int BState1 = 0;
int BState2 = 0;
int BState3 = 0;
int BState4 = 0;
int BState5 = 0;
int pos_P2, pos_P3, i, j, Alarm = 0, SN;
int A1H, A1M, A2H, A2M, A3H, A3M, A4H, A4M;
int ON1, ON2, ON3, ON4;
int Ch1, Ch2, Ch3, Ch4;
int S1M, S2M, S3M, S4M;

int PageNo = 0;
LiquidCrystal_I2C lcd(0x27, 20, 4);

byte Side[] = {
  B01110,
  B01110,
  B01110,
  B01110,
  B01110,
  B01110,
  B01110,
  B01110
};

byte Top1[] = {
  B00000,
  B00000,
  B00000,
  B01110,
  B01110,
  B00000,
  B00000,
  B00000
};

byte Bottom1[] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};

byte AlarmSet[] = {
  B00100,
  B01110,
  B01110,
  B01110,
  B11111,
  B00000,
  B00100,
  B00000
};

byte Heart[] = {  
  B00000,
  B01010,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000,
  B00000
};

byte Add[] = {  
  B00000,
  B00000,
  B00100,
  B00100,
  B11111,
  B00100,
  B00100,
  B00000
};

byte Music[] = {
  B00001,
  B00011,
  B00101,
  B01001,
  B01001,
  B01011,
  B11011,
  B11000
};

byte Pointer[] = {
  B10000,
  B11000,
  B11100,
  B11110,
  B11100,
  B11000,
  B10000,
  B00000
};


void setup() {
  Serial.begin(9600);
  lcd.init();         
  lcd.backlight();
  H = 12, M = 00, S = 00;
  lcd.createChar(0, Side);
  lcd.createChar(1, Top1);
  lcd.createChar(2, Bottom1);
  lcd.createChar(3, AlarmSet);
  lcd.createChar(4, Heart);
  lcd.createChar(5, Add);
  lcd.createChar(6, Music);
  lcd.createChar(7, Pointer);
  A1H = 0, A1M = 0, A2H = 0, A2M = 0, A3H = 0, A3M = 0, A4H = 0, A4M = 0, SN = 0;
  ON1 = 0, ON2 = 0, ON3 = 0, ON4 = 0;
  Ch1 = 0, Ch2 = 0, Ch3 = 0, Ch4 = 0;
  S1M = 0, S2M = 0, S3M = 0, S4M = 0;
  lcd.clear();
  
  setTime(H, M, S, 0, 0, 0);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  pinMode(button5, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);

  lcd.setCursor(0, 0);
  lcd.write(byte(0));
  lcd.setCursor(0, 1);
  lcd.write(byte(0));
  lcd.setCursor(0, 2);
  lcd.write(byte(0));
  lcd.setCursor(0, 3);
  lcd.write(byte(0));

  lcd.setCursor(1, 0);
  lcd.print("SMART");
  lcd.setCursor(1, 1);
  lcd.print("PILL");
  lcd.setCursor(1, 2);
  lcd.print("BOX");


  lcd.setCursor(14, 3);
  lcd.write(byte(1));
  delay(1000);
  lcd.write(byte(1));
  delay(1000);
  lcd.write(byte(1));
  delay(1000);
  lcd.write(byte(1));
  delay(1000);
  lcd.write(byte(1));
  delay(1000);
  lcd.write(byte(1));
  delay(1000);
  lcd.setCursor(14, 3);
  lcd.print("      ");
  delay(1000);
  lcd.setCursor(14, 3);
  lcd.write(byte(1));
  delay(1000);
  lcd.write(byte(1));
  delay(1000);
  lcd.write(byte(1));
  delay(1000);
  lcd.write(byte(1));
  delay(1000);
  lcd.write(byte(1));
  delay(1000);
  lcd.write(byte(1));
  delay(1000);
  

  lcd.clear();
  PageNo = 1;
  pos_P2 = 1;
  pos_P3 = 1;
}

void loop() {
  
  BState1 = digitalRead(button1);
  BState2 = digitalRead(button2);
  BState3 = digitalRead(button3);
  BState4 = digitalRead(button4);
  BState5 = digitalRead(button5);
  S1M = A1M + SN;
  S2M = A2M + SN;
  S3M = A3M + SN;
  S4M = A4M + SN;

  if(hour() == A1H && minute() == S1M && ON1 == 1 && Ch1 == 0 && second()<=5)
  {
    Ch1 = 1;
    lcd.clear(); 
    PageNo = 15;
  }
  if(hour() == A2H && minute() == S2M && ON2 == 1 && Ch2 == 0 && second()<=5)
  {
    Ch2 = 1;
    lcd.clear();
    PageNo = 16;
  }
  if(hour() == A3H && minute() == S3M && ON3 == 1 && Ch3 == 0 && second()<=5)
  {
    Ch3 = 1;
    lcd.clear();
    PageNo = 17;
  }
  if(hour() == A4H && minute() == S4M && ON4 == 1 && Ch4 == 0 && second()<=5)
  {
    Ch4 = 1;
    lcd.clear();
    PageNo = 18;
  }
  switch(PageNo)
  {
    case 1: page_1_display();
            break;
    case 2: page_2_display();
            break;
    case 3: page_3_display();
            break;
    case 4: page_4_display();
            break; 
    case 5: page_5_display();
            break;
    case 6: page_6_display();
            break;
    case 7: page_7_display();
            break;
    case 8: page_8_display();
            break;
    case 9: page_9_display();
            break;
    case 10: page_10_display();
            break;  
    case 11: page_11_display();
            break;
    case 12: page_12_display();
            break;
    case 13: page_13_display();
            break;
    case 14: page_14_display();
            break;
    case 15: page_15_display();
            break;
    case 16: page_16_display();
            break;      
    case 17: page_17_display();
            break;
    case 18: page_18_display();
            break;                          
    default:break;
  }
  
  digitalClockDisplay();
  delay(1000);
}

void digitalClockDisplay(){
  if(PageNo == 1)
  {
    lcd.setCursor(2, 0);
    lcd.print(hour());
    printDigits(minute());
    printDigits(second());
  }
 
}

void printDigits(int digits) {

  lcd.print(":");
  if(digits < 10)
    lcd.print('0');
    lcd.print(digits);
}

void page_1_display()
{
  lcd.setCursor(0, 0);
  lcd.write(byte(3));

  lcd.setCursor(0, 3);
  lcd.write(byte(0));
  lcd.setCursor(1, 3);
  lcd.print("MENU");

  lcd.setCursor(19,0);
  lcd.write(byte(0));
  lcd.setCursor(19,1);
  lcd.write(byte(0));
  lcd.setCursor(19,2);
  lcd.write(byte(0));
  lcd.setCursor(19,3);
  lcd.write(byte(0));
  //if(Alarm>=1)
  //{

  //}
  if(BState1 == HIGH)
  {
    lcd.clear();
    PageNo = 2;
  }
}


void page_2_display()
{
  lcd.setCursor(1, 0);
  lcd.print("CHANGE TIME");
  lcd.setCursor(1, 1);
  lcd.print("SET ALARMS");
  lcd.setCursor(0, 3);
  lcd.write(byte(0));
  lcd.setCursor(1, 3);
  lcd.print("SELECT");
  lcd.setCursor(8, 3);
  lcd.write(byte(0));
  lcd.setCursor(9,3);
  lcd.print("BACK");
  if(BState4 == HIGH)
  {
    pos_P2 = pos_P2 + 1;
  }
  if(pos_P2 > 2)
  {
    pos_P2 = 1;
  }
  if(BState3 == HIGH)
  {
    pos_P2 = pos_P2 - 1;
  }
  if(pos_P2 < 1)
  {
    pos_P2 = 2;
  }
  if(pos_P2 == 1)
  {
    lcd.setCursor(0, 1);
    lcd.print(" ");
    lcd.setCursor(0, 0);
    lcd.write(byte(7));
  }
  if(pos_P2 == 2)
  {
    lcd.setCursor(0, 0);
    lcd.print(" ");
    lcd.setCursor(0, 1);
    lcd.write(byte(7));
  }
  
  if(pos_P2 == 1 && BState1 == HIGH)
  {
    lcd.clear();
    PageNo = 3;
  }
  else if(pos_P2 == 2 && BState1 == HIGH)
  {
    lcd.clear();
    PageNo = 6;
  }
  else if(BState2 == HIGH)
  {
    lcd.clear();
    PageNo = 1;
  }
}

void page_3_display()
{
  lcd.setCursor(2, 0);
  lcd.print("SET HOURS");
  lcd.setCursor(2, 2);
  lcd.print("HOURS:");
  lcd.setCursor(8, 2);
  lcd.print(hh);
  lcd.setCursor(15,3);
  lcd.write(byte(0));  
  lcd.setCursor(16,3);
  lcd.print("NEXT");
  if(BState3 == HIGH)
  {
    lcd.setCursor(8, 2);
    if(hh>10)
      lcd.print("0");
    lcd.print(hh);
    if(hh>=24)
      hh = 0;
    hh++;
    delay(100);  
  }
  if(BState4 == HIGH)
  {
    lcd.setCursor(8, 2);
    if(hh>10)
      lcd.print("0");
    lcd.print(hh);
    if(hh<=0)
      hh = 24;
    hh--;
    delay(100);
  }
  if(BState5 == HIGH)
  {
    lcd.clear();
    PageNo = 4;
  }
}

void page_4_display()
{
  lcd.setCursor(2, 0);
  lcd.print("SET MINUTES");
  lcd.setCursor(2, 2);
  lcd.print("MINUTES:");
  lcd.setCursor(10, 2);
  if(mm>10)
      lcd.print("0");
  lcd.print(mm);
  lcd.setCursor(15, 3);
  lcd.write(byte(0));
  lcd.setCursor(16, 3);
  lcd.print("NEXT");
  lcd.setCursor(7, 3);
  lcd.write(byte(0));
  lcd.setCursor(8, 3);
  lcd.print("BACK");

  if(BState3 == HIGH)
  {
    lcd.setCursor(10, 2);
    if(mm>10)
      lcd.print("0");
    lcd.print(mm);
    if(mm>=60)
      mm = 0;
    mm++;
    delay(100);  
  }
  if(BState4 == HIGH)
  {
    lcd.setCursor(10, 2);
    if(mm>10)
      lcd.print("0");
    lcd.print(mm);
    if(mm<=0)
      mm = 60;
    mm--;
    delay(100);
  }
  if(BState5 == HIGH)
  {
    lcd.clear();
    PageNo = 5;
  }
  if(BState2 == HIGH)
  {
    lcd.clear();
    PageNo = 3;
  }
}

void page_5_display()
{
  lcd.setCursor(2, 0);
  lcd.print("SET SECONDS");
  lcd.setCursor(2, 2);
  lcd.print("SECONDS:");
  lcd.setCursor(10, 2);
  if(ss<10)
    lcd.print("0");
  lcd.print(ss);
  lcd.setCursor(15, 3);
  lcd.write(byte(0));
  lcd.setCursor(16, 3);
  lcd.print("NEXT");
  lcd.setCursor(7, 3);
  lcd.write(byte(0));
  lcd.setCursor(8, 3);
  lcd.print("BACK");

  if(BState3 == HIGH)
  {
    lcd.setCursor(10, 2);
    if(ss<10)
      lcd.print("0");
    lcd.print(ss);
    if(ss>=60)
      ss = 0;
    ss++;
    delay(100);  
  }
  if(BState4 == HIGH)
  {
    lcd.setCursor(10, 2);
    if(ss<10)
      lcd.print("0");
    lcd.print(ss);
    if(ss<=0)
      ss = 60;
    ss--;
    delay(100);
  }
  if(BState5 == HIGH)
  {
    lcd.clear();
    setTime(hh, mm, ss, 0, 0, 0);
    PageNo = 1;
  }
  if(BState2 == HIGH)
  {
    lcd.clear();
    PageNo = 4;
  }
}

void page_6_display()
{
  lcd.setCursor(0, 3);
  lcd.write(byte(5));
  lcd.setCursor(1, 3);
  lcd.print("ADD");
  lcd.setCursor(5, 3);
  lcd.write(byte(0));
  lcd.setCursor(6, 3);
  lcd.print("DELETE");
  lcd.setCursor(15, 3);
  lcd.write(byte(0));
  lcd.setCursor(16, 3);
  lcd.print("BACK");
  lcd.setCursor(1, 0);
  lcd.write(byte(5));
  lcd.setCursor(1, 1);
  lcd.write(byte(5));
  lcd.setCursor(1, 2);
  lcd.write(byte(5));
  lcd.setCursor(12, 0);
  lcd.write(byte(5));
  if(ON1 == 1)
  {
    lcd.setCursor(2, 0);
    if(A1H<10)
      lcd.print("0");
    lcd.print(A1H);
    lcd.print(":");
    if(A1M<10)
      lcd.print("0");
    lcd.print(A1M);
  }
  if(ON2 == 1)
  {
    lcd.setCursor(2, 1);
    if(A2H<10)
      lcd.print("0");
    lcd.print(A2H);
    lcd.print(":");
    if(A2M<10)
      lcd.print("0");
    lcd.print(A2M);
  }
  if(ON3 == 1)
  {
    lcd.setCursor(2, 2);
    if(A3H<10)
      lcd.print("0");
    lcd.print(A3H);
    lcd.print(":");
    if(A3M<10)
      lcd.print("0");
    lcd.print(A3M);
  }
  if(ON4 == 1)
  {
    lcd.setCursor(13, 0);
    if(A4H<10)
      lcd.print("0");
    lcd.print(A4H);
    lcd.print(":");
    if(A4M<10)
      lcd.print("0");
    lcd.print(A4M);
  }

  if(ON1 == 0)
  {
    lcd.setCursor(2, 0);
    lcd.print("       ");
  }
  if(ON2 == 0)
  {
    lcd.setCursor(2, 1);
    lcd.print("       ");
  }
  if(ON3 == 0)
  {
    lcd.setCursor(2, 2);
    lcd.print("       ");
  }
  if(ON4 == 0)
  {
    lcd.setCursor(13, 0);
    lcd.print("       ");
  }
  if(BState5 == HIGH)
  {
    lcd.clear();
    PageNo = 1;
  }
  if(pos_P3==1 && BState1==HIGH)
  {
    Alarm++;
    PageNo = 7;
  }
  if(pos_P3==2 && BState1==HIGH)
  {
    Alarm++;
    PageNo = 9;
  }
  if(pos_P3==3 && BState1==HIGH)
  {
    Alarm++;
    PageNo = 11;
  }
  if(pos_P3==4 && BState1==HIGH)
  {
    Alarm++;
    PageNo = 13;
  }
  if(pos_P3==1 && BState2==HIGH)
  {
    Alarm--;
    ON1 = 0, A1H = 0, A1M = 0;
    lcd.setCursor(2, 0);
    lcd.print("       ");
  }
  if(pos_P3==2 && BState2==HIGH)
  {
    Alarm--;
    ON2 = 0, A2H = 0, A2M = 0;
    lcd.setCursor(2, 1);
    lcd.print("       ");
  }
  if(pos_P3==3 && BState2==HIGH)
  {
    Alarm--;
    ON3 = 0, A3H = 0, A3M = 0;
    lcd.setCursor(2, 2);
    lcd.print("       ");
  }
  if(pos_P3==4 && BState2==HIGH)
  {
    Alarm--;
    ON4 = 0, A4H = 0, A4M = 0;
    lcd.setCursor(13, 0);
    lcd.print("       ");
  }
  

  if(BState4 == HIGH)
  {
    pos_P3 = pos_P3 + 1;
  }
  if(pos_P3 > 4)
  {
    pos_P3 = 1;
  }
  if(BState3 == HIGH)
  {
    pos_P3 = pos_P3 - 1;
  }
  if(pos_P3 < 1)
  {
    pos_P3 = 4;
  }
  if(pos_P3 == 1)
  {
    lcd.setCursor(0, 1);
    lcd.print(" ");
    lcd.setCursor(11, 0);
    lcd.print(" ");
    lcd.setCursor(0, 0);
    lcd.write(byte(7));
  }
  else if(pos_P3 == 2)
  {
    lcd.setCursor(0, 0);
    lcd.print(" ");
    lcd.setCursor(0, 2);
    lcd.print(" ");
    lcd.setCursor(0, 1);
    lcd.write(byte(7));
  }
  else if(pos_P3 == 3)
  {
    lcd.setCursor(0, 1);
    lcd.print(" ");
    lcd.setCursor(11, 0);
    lcd.print(" ");
    lcd.setCursor(0, 2);
    lcd.write(byte(7));
  }
  else if(pos_P3 == 4)
  {
    lcd.setCursor(0, 2);
    lcd.print(" ");
    lcd.setCursor(0, 0);
    lcd.print(" ");
    lcd.setCursor(11, 0);
    lcd.write(byte(7));
  }
  
}

void page_7_display()
{
  lcd.clear();
  ON1 = 1;
  lcd.setCursor(2, 0);
  lcd.print("SET ALARM:");
  lcd.setCursor(3, 2);
  lcd.print("Hours:");
  lcd.setCursor(9, 2);
  if(A1H<10)
      lcd.print("0");
  lcd.print(A1H);
  lcd.setCursor(15, 3);
  lcd.write(byte(0));
  lcd.setCursor(16, 3);
  lcd.print("NEXT");
  if(BState3 == HIGH)
  {
    lcd.setCursor(9, 2);
    if(A1H<10)
      lcd.print("0");
    lcd.print(A1H);
    if(A1H>=24)
      A1H = 0;
    A1H++;
    delay(100);  
  }
  if(BState4 == HIGH)
  {
    lcd.setCursor(9, 2);
    if(A1H<10)
      lcd.print("0");
    lcd.print(A1H);
    if(A1H<=0)
      A1H = 24;
    A1H--;
    delay(100);
  }
  if(BState5 == HIGH)
  {
    lcd.clear();
    PageNo = 8;
  }
  
}
void page_8_display()
{
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("SET ALARM:");
  lcd.setCursor(3, 2);
  lcd.print("Minutes:");
  lcd.setCursor(11, 2);
  if(A1M<10)
      lcd.print("0");
  lcd.print(A1M);
  lcd.setCursor(14, 3);
  lcd.write(byte(0));
  lcd.setCursor(15,3);
  lcd.print("ENTER");
  lcd.setCursor(6, 3);
  lcd.write(byte(0));
  lcd.setCursor(7,3);
  lcd.print("BACK");
  if(BState3 == HIGH)
  {
    lcd.setCursor(11, 2);
    if(A1M<10)
      lcd.print("0");
    lcd.print(A1M);
    if(A1M>=60)
      A1M = 0;
    A1M++;
    delay(100);  
  }
  if(BState4 == HIGH)
  {
    lcd.setCursor(11, 2);
    if(A1M<10)
      lcd.print("0");
    lcd.print(A1M);
    if(A1M<=0)
      A1M = 6;
    A1M--;
    delay(100);
  }
  if(BState5 == HIGH)
  {
    lcd.clear();
    PageNo = 6;
  }
  if(BState2 == HIGH)
  {
    lcd.clear();
    PageNo = 7;
  }
}

void page_9_display()
{
  lcd.clear();
  ON2 = 1;
  lcd.setCursor(2, 0);
  lcd.print("SET ALARM:");
  lcd.setCursor(3, 2);
  lcd.print("Hours:");
  lcd.setCursor(9, 2);
  if(A2H<10)
      lcd.print("0");
  lcd.print(A2H);
  lcd.setCursor(15, 3);
  lcd.write(byte(0));
  lcd.setCursor(16, 3);
  lcd.print("NEXT");
  if(BState3 == HIGH)
  {
    lcd.setCursor(9, 2);
    if(A2H<10)
      lcd.print("0");
    lcd.print(A2H);
    if(A2H>=24)
      A2H = 0;
    A2H++;
    delay(100);  
  }
  if(BState4 == HIGH)
  {
    lcd.setCursor(9, 2);
    if(A2H<10)
      lcd.print("0");
    lcd.print(A2H);
    if(A2H<=0)
      A2H = 24;
    A2H--;
    delay(100);
  }
  if(BState5 == HIGH)
  {
    lcd.clear();
    PageNo = 10;
  }
}

void page_10_display()
{
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("SET ALARM:");
  lcd.setCursor(3, 2);
  lcd.print("Minutes:");
  lcd.setCursor(11, 2);
  if(A2M<10)
      lcd.print("0");
  lcd.print(A2M);
  lcd.setCursor(14, 3);
  lcd.write(byte(0));
  lcd.setCursor(15,3);
  lcd.print("ENTER");
  lcd.setCursor(6, 3);
  lcd.write(byte(0));
  lcd.setCursor(7,3);
  lcd.print("BACK");
  if(BState3 == HIGH)
  {
    lcd.setCursor(11, 2);
    if(A2M<10)
      lcd.print("0");
    lcd.print(A2M);
    if(A2M>=60)
      A2M = 0;
    A2M++;
    delay(100);  
  }
  if(BState4 == HIGH)
  {
    lcd.setCursor(11, 2);
    if(A2M<10)
      lcd.print("0");
    lcd.print(A2M);
    if(A2M<=0)
      A2M = 6;
    A2M--;
    delay(100);
  }
  if(BState5 == HIGH)
  {
    lcd.clear();
    PageNo = 6;
  }
  if(BState2 == HIGH)
  {
    lcd.clear();
    PageNo = 9;
  }
}

void page_11_display()
{
  lcd.clear();
  ON3 = 1;
  lcd.setCursor(2, 0);
  lcd.print("SET ALARM:");
  lcd.setCursor(3, 2);
  lcd.print("Hours:");
  lcd.setCursor(9, 2);
  if(A3H<10)
      lcd.print("0");
  lcd.print(A3H);
  lcd.setCursor(15, 3);
  lcd.write(byte(0));
  lcd.setCursor(16, 3);
  lcd.print("NEXT");
  if(BState3 == HIGH)
  {
    lcd.setCursor(9, 2);
    if(A3H<10)
      lcd.print("0");
    lcd.print(A3H);
    if(A3H>=24)
      A3H = 0;
    A3H++;
    delay(100);  
  }
  if(BState4 == HIGH)
  {
    lcd.setCursor(9, 2);
    if(A3H<10)
      lcd.print("0");
    lcd.print(A3H);
    if(A3H<=0)
      A3H = 24;
    A3H--;
    delay(100);
  }
  if(BState5 == HIGH)
  {
    lcd.clear();
    PageNo = 12;
  }
}

void page_12_display()
{
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("SET ALARM:");
  lcd.setCursor(3, 2);
  lcd.print("Minutes:");
  lcd.setCursor(11, 2);
  if(A3M<10)
      lcd.print("0");
  lcd.print(A3M);
  lcd.setCursor(14, 3);
  lcd.write(byte(0));
  lcd.setCursor(15,3);
  lcd.print("ENTER");
  lcd.setCursor(6, 3);
  lcd.write(byte(0));
  lcd.setCursor(7,3);
  lcd.print("BACK");
  if(BState3 == HIGH)
  {
    lcd.setCursor(11, 2);
    if(A3M<10)
      lcd.print("0");
    lcd.print(A3M);
    if(A3M>=60)
      A3M = 0;
    A3M++;
    delay(100);  
  }
  if(BState4 == HIGH)
  {
    lcd.setCursor(11, 2);
    if(A3M<10)
      lcd.print("0");
    lcd.print(A3M);
    if(A3M<=0)
      A3M = 6;
    A3M--;
    delay(100);
  }
  if(BState5 == HIGH)
  {
    lcd.clear();
    PageNo = 6;
  }
  if(BState2 == HIGH)
  {
    lcd.clear();
    PageNo = 11;
  }
}

void page_13_display()
{
  lcd.clear();
  ON4 = 1;
  lcd.setCursor(2, 0);
  lcd.print("SET ALARM:");
  lcd.setCursor(3, 2);
  lcd.print("Hours:");
  lcd.setCursor(9, 2);
  if(A4H<10)
      lcd.print("0");
  lcd.print(A4H);
  lcd.setCursor(15, 3);
  lcd.write(byte(0));
  lcd.setCursor(16, 3);
  lcd.print("NEXT");
  if(BState3 == HIGH)
  {
    lcd.setCursor(9, 2);
    if(A4H<10)
      lcd.print("0");
    lcd.print(A4H);
    if(A4H>=24)
      A4H = 0;
    A4H++;
    delay(100);  
  }
  if(BState4 == HIGH)
  {
    lcd.setCursor(9, 2);
    if(A4H<10)
      lcd.print("0");
    lcd.print(A4H);
    if(A4H<=0)
      A4H = 24;
    A4H--;
    delay(100);
  }
  if(BState5 == HIGH)
  {
    lcd.clear();
    PageNo = 14;
  }
}

void page_14_display()
{
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("SET ALARM:");
  lcd.setCursor(3, 2);
  lcd.print("Minutes:");
  lcd.setCursor(11, 2);
  if(A4M<10)
      lcd.print("0");
  lcd.print(A4M);
  lcd.setCursor(14, 3);
  lcd.write(byte(0));
  lcd.setCursor(15, 3);
  lcd.print("ENTER");
  lcd.setCursor(6, 3);
  lcd.write(byte(0));
  lcd.setCursor(7,3);
  lcd.print("BACK");
  if(BState3 == HIGH)
  {
    lcd.setCursor(11, 2);
    if(A4M<10)
      lcd.print("0");
    lcd.print(A4M);
    if(A4M>=60)
      A4M = 0;
    A4M++;
    delay(100);  
  }
  if(BState4 == HIGH)
  {
    lcd.setCursor(11, 2);
    if(A4M<10)
      lcd.print("0");
    lcd.print(A4M);
    if(A4M<=0)
      A4M = 6;
    A4M--;
    delay(100);
  }
  if(BState5 == HIGH)
  {
    lcd.clear();
    PageNo = 6;
  }
  if(BState2 == HIGH)
  {
    lcd.clear();
    PageNo = 13;
  }
}

void page_15_display()
{
  lcd.setCursor(3, 0);
  lcd.print("Take your pills.");
  
  lcd.setCursor(11, 2);
  if(A1H<10)
      lcd.print("0");
  lcd.print(A1H);
  lcd.print(":");
  if(A1M<10)
      lcd.print("0");
  lcd.print(A1M);
  lcd.setCursor(0, 3);
  lcd.write(byte(0));
  lcd.setCursor(1, 3);
  lcd.print("DONE");
  
  lcd.setCursor(3, 3);
  lcd.write(byte(0));
  lcd.setCursor(14, 3);
  lcd.print("SNOOZE");

  digitalWrite(buzzer, HIGH);
  digitalWrite(Led1, HIGH);
  digitalWrite(Led2, HIGH);
  lcd.setCursor(3, 2);
  lcd.write(byte(3));
  delay(100);
  digitalWrite(buzzer, LOW);
  digitalWrite(Led1, LOW);
  digitalWrite(Led2, LOW);
  lcd.setCursor(3, 2);
  lcd.print(" ");
  delay(300);
  digitalWrite(buzzer, HIGH);
  digitalWrite(Led1, HIGH);
  digitalWrite(Led2, HIGH);
  lcd.setCursor(3, 2);
  lcd.write(byte(3));
  delay(100);
  digitalWrite(buzzer, LOW);
  digitalWrite(Led1, LOW);
  digitalWrite(Led2, LOW);
  lcd.setCursor(3, 2);
  lcd.print(" ");
  delay(300);
  if(BState1 == HIGH)
  {
    Ch1 = 0;
    lcd.clear();
    PageNo = 1; 
  }
  if(BState5 == HIGH)
  {
    SN = 5;
    Ch4 = 0;
    lcd.clear();
    PageNo = 1; 
  }
}
void page_16_display()
{
  
  lcd.setCursor(3, 0);
  lcd.print("Take your pills.");
  
  lcd.setCursor(11, 2);
  if(A2H<10)
      lcd.print("0");
  lcd.print(A2H);
  lcd.print(":");
  if(A2M<10)
      lcd.print("0");
  lcd.print(A2M);
  lcd.setCursor(0, 3);
  lcd.write(byte(0));
  lcd.setCursor(1, 3);
  lcd.print("DONE");
  
  lcd.setCursor(3, 3);
  lcd.write(byte(0));
  lcd.setCursor(14, 3);
  lcd.print("SNOOZE");

  digitalWrite(buzzer, HIGH);
  digitalWrite(Led1, HIGH);
  digitalWrite(Led2, HIGH);
  lcd.setCursor(3, 2);
  lcd.write(byte(3));
  delay(100);
  digitalWrite(buzzer, LOW);
  digitalWrite(Led1, LOW);
  digitalWrite(Led2, LOW);
  lcd.setCursor(3, 2);
  lcd.print(" ");
  delay(300);
  digitalWrite(buzzer, HIGH);
  digitalWrite(Led1, HIGH);
  digitalWrite(Led2, HIGH);
  lcd.setCursor(3, 2);
  lcd.write(byte(3));
  delay(100);
  digitalWrite(buzzer, LOW);
  digitalWrite(Led1, LOW);
  digitalWrite(Led2, LOW);
  lcd.setCursor(3, 2);
  lcd.print(" ");
  delay(300);
  if(BState1 == HIGH)
  {
    Ch2 = 0;
    lcd.clear();
    PageNo = 1; 
  }
  if(BState5 == HIGH)
  {
    SN = 5;
    Ch4 = 0;
    lcd.clear();
    PageNo = 1; 
  }
}
void page_17_display()
{
  
  lcd.setCursor(3, 0);
  lcd.print("Take your pills.");
  
  lcd.setCursor(11, 2);
  if(A3H<10)
      lcd.print("0");
  lcd.print(A3H);
  lcd.print(":");
  if(A3M<10)
      lcd.print("0");
  lcd.print(A3M);
  lcd.setCursor(0, 3);
  lcd.write(byte(0));
  lcd.setCursor(1, 3);
  lcd.print("DONE");
  
  lcd.setCursor(3, 3);
  lcd.write(byte(0));
  lcd.setCursor(14, 3);
  lcd.print("SNOOZE");

  digitalWrite(buzzer, HIGH);
  digitalWrite(Led1, HIGH);
  digitalWrite(Led2, HIGH);
  lcd.setCursor(3, 2);
  lcd.write(byte(3));
  delay(100);
  digitalWrite(buzzer, LOW);
  digitalWrite(Led1, LOW);
  digitalWrite(Led2, LOW);
  lcd.setCursor(3, 2);
  lcd.print(" ");
  delay(300);
  digitalWrite(buzzer, HIGH);
  digitalWrite(Led1, HIGH);
  digitalWrite(Led2, HIGH);
  lcd.setCursor(3, 2);
  lcd.write(byte(3));
  delay(100);
  digitalWrite(buzzer, LOW);
  digitalWrite(Led1, LOW);
  digitalWrite(Led2, LOW);
  lcd.setCursor(3, 2);
  lcd.setCursor(3, 2);
  lcd.print(" ");
  delay(300);
  if(BState1 == HIGH)
  {
    Ch3 = 0;
    lcd.clear();
    PageNo = 1; 
  }
  if(BState5 == HIGH)
  {
    SN = 5;
    Ch3 = 0;
    lcd.clear();
    PageNo = 1; 
  }
}
void page_18_display()
{
  lcd.setCursor(3, 0);
  lcd.print("Take your pills.");
  
  lcd.setCursor(11, 2);
  if(A4H<10)
      lcd.print("0");
  lcd.print(A4H);
  lcd.print(":");
  if(A4M<10)
      lcd.print("0");
  lcd.print(A4M);
  lcd.setCursor(0, 3);
  lcd.write(byte(0));
  lcd.setCursor(1, 3);
  lcd.print("DONE");

  lcd.setCursor(3, 3);
  lcd.write(byte(0));
  lcd.setCursor(14, 3);
  lcd.print("SNOOZE");

  digitalWrite(buzzer, HIGH);
  digitalWrite(Led1, HIGH);
  digitalWrite(Led2, HIGH);
  lcd.setCursor(3, 2);
  lcd.write(byte(3));
  delay(100);
  digitalWrite(buzzer, LOW);
  digitalWrite(Led1, LOW);
  digitalWrite(Led2, LOW);
  lcd.setCursor(3, 2);
  lcd.print(" ");
  delay(300);
  digitalWrite(buzzer, HIGH);
  digitalWrite(Led1, HIGH);
  digitalWrite(Led2, HIGH);
  lcd.setCursor(3, 2);
  lcd.write(byte(3));
  delay(100);
  digitalWrite(buzzer, LOW);
  digitalWrite(Led1, LOW);
  digitalWrite(Led2, LOW);
  lcd.setCursor(3, 2);
  lcd.print(" ");
  delay(300);
  if(BState1 == HIGH)
  {
    Ch4 = 0;
    lcd.clear();
    PageNo = 1; 
  }
  if(BState5 == HIGH)
  {
    SN = 5;
    Ch4 = 0;
    lcd.clear();
    PageNo = 1; 
  }
}







