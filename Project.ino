#include <Adafruit_LiquidCrystal.h>
Adafruit_LiquidCrystal lcd(0);

int green = 13;
int yellow = 12;
int red = 8;

void setup()
{
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("CountDown : ");
}

void countdown(){
  lcd.setCursor(12,0);
  lcd.print("5");
  delay(1000);
  lcd.setCursor(12,0);
  lcd.print("4");
  delay(1000);
  lcd.setCursor(12,0);
  lcd.print("3");
  delay(1000);
  lcd.setCursor(12,0);
  lcd.print("2");
  delay(1000);
  lcd.setCursor(12,0);
  lcd.print("1");
  delay(1800);
}
void loop()
{
  digitalWrite(green, HIGH);
  countdown();
  digitalWrite(green,LOW);
  digitalWrite(yellow, HIGH);
  delay(500);
  digitalWrite(yellow, LOW);
  delay(100);
  digitalWrite(red, HIGH);
  countdown();
  digitalWrite(red, LOW);
  digitalWrite(yellow, HIGH);
  delay(500);
  digitalWrite(yellow,LOW);
  delay(100);
}
