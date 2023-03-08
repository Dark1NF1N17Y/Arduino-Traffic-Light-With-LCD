#include <Keypad.h>
#include <Adafruit_LiquidCrystal.h>
Adafruit_LiquidCrystal lcd(0);

int green = 13;
int yellow = 12;
int red = 8;
int maincount = 60;
int count = maincount;


void countdown(){
  lcd.setCursor(12,0);
  count -= 1;
  lcd.print(count);
  delay(500);
  if(count == 0){
  count = maincount;
  count += 1;
  loop();
  }
  if(count <= 10 && count > 9){
  lcd.setCursor(13,0);
  delay(400);
  lcd.print(" ");
  countdown();
  }
  if(count <= 100 && count > 99){
  lcd.setCursor(14,0);
  delay(400);
  lcd.print(" ");
  countdown();
  }
  if(count <= 1000 && count > 999){
  lcd.setCursor(15,0);
  delay(400);
  lcd.print(" ");
  countdown();
  }
  else{
  delay(500);
  countdown();
  }
  }
void setup(){
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  if(maincount > 9999){
  lcd.print("Not Valid Timer!");
  setup();
  }
  else{
  lcd.print("CountDown : ");
  count += 1;
  digitalWrite(green, HIGH);
  countdown();
  }
}
void loop()
{
  if(digitalRead(green) == HIGH){
  digitalWrite(green, LOW);
  digitalWrite(yellow, HIGH);
  delay(500);
  digitalWrite(yellow, LOW);
  delay(100);
  digitalWrite(red, HIGH);
  countdown();
  }else{
  digitalWrite(red, LOW);
  digitalWrite(yellow, HIGH);
  delay(500);
  digitalWrite(yellow, LOW);
  delay(100);
  digitalWrite(green, HIGH);
  countdown();
  }
}
