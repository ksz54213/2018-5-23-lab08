#include <Ultrasonic.h>
#include <LiquidCrystal.h>
#define Echo_pin 15
#define Trig_pin 16
//const byte Button = 6;

Ultrasonic ultra(Trig_pin,Echo_pin);

LiquidCrystal lcd(12, 11, 5, 4, 3, 8);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16, 2); 
 
}

void loop() {
  
    
       long microsec = ultra.Timing();
       float cmMs = ultra.Ranging(CM); // Estimute CM;
       lcd.setCursor(0, 0);
       lcd.print("MS: ");
       lcd.print(microsec);
       lcd.print("ms");
        lcd.setCursor(0, 1);
        lcd.print("Stance: ");
       lcd.print(cmMs);
       lcd.print("cm");
      Serial.print("Ms : "); Serial.print(microsec);Serial.print(" ms  ");
      Serial.print("Stance : "); Serial.print(cmMs); Serial.println(" cm");
      delay(1000);
    
}



