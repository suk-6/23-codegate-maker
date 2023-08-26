#include <Wire.h>
#include <TEA5767Radio.h>
#include <LiquidCrystal_I2C.h>

TEA5767Radio radio = TEA5767Radio();
LiquidCrystal_I2C lcd(0x27,16,2); // LCD 인터페이스 찾기과정에서 메모했던 주소값으로 바꿔주세요.


int upButtonPin = 4;
int downButtonPin = 5;

float RadioMHz = 90.7;

void setup()
{ 
  Serial.begin(9600);
  pinMode(upButtonPin,INPUT);
  pinMode(downButtonPin,INPUT);
  
  Wire.begin();
  
  lcd.init();  
  lcd.backlight();
  lcd.print(RadioMHz);
  lcd.print("Mhz");
  
  radio.setFrequency(RadioMHz); // pick your own frequency
}

void loop()
{
  int upButton = !digitalRead(upButtonPin);
  int downButton = !digitalRead(downButtonPin);

  if(upButton == 1)
  {
      if(RadioMHz < 107.9) RadioMHz = RadioMHz + 0.1;
      lcd.clear();
      lcd.print(RadioMHz);
      lcd.print("Mhz");
      radio.setFrequency(RadioMHz); // pick your own frequency
      delay(10);
  }
  else if(downButton == 1)
  {
      if(RadioMHz > 87.6) RadioMHz = RadioMHz - 0.1;
      lcd.clear();
      lcd.print(RadioMHz);
      lcd.print("Mhz");
      radio.setFrequency(RadioMHz); // pick your own frequency
      delay(10);
  }
}
