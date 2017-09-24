/* Soil Moisture Detection Control Module (FC-28) [S022] : http://rdiot.tistory.com/59 [RDIoT Demo] */

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // LCD2004
int pin = A0; 

void setup()
{
  lcd.init();  // initialize the lcd 
  lcd.backlight();
  lcd.print("start LCD2004");

  pinMode(pin,INPUT);
  delay(1000);

  lcd.clear();
}

void loop()
{ 
  lcd.setCursor(0,0);
  lcd.print("S022:FC-28");
  
  int sensorValue = analogRead(pin);
  sensorValue = constrain(sensorValue, 485, 1023);

  int soil = map(sensorValue, 485, 1023, 100, 0);

  lcd.setCursor(0,1);
  lcd.print("sensorValue=" + (String)sensorValue);

  lcd.setCursor(0,2);
  if(soil<10)
    lcd.print("soil=00" + (String)soil + "\%");
  else if(soil == 100)
    lcd.print("soil=" + (String)soil + "\%");
  else 
   lcd.print("soil=0" + (String)soil + "\%");
 
  delay(1000);        // delay in between reads for stability

}
