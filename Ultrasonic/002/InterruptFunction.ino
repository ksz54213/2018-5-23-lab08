#include <Ultrasonic.h>
#include <LiquidCrystal.h>
#define Echo_pin 15
#define Trig_pin 16


Ultrasonic ultra(Trig_pin,Echo_pin);

LiquidCrystal lcd(12, 11, 5, 4, 3, 8);

volatile long microsec;
volatile float cmMs;
volatile boolean state =LOW;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16, 2); 

  
  pinMode(2,INPUT);
 
 
  attachInterrupt(6, int0,FALLING);
  digitalWrite(2,LOW);
 
}

void loop() {
  
  
    delay(500);
        
}
void int0(){
      
      microsec = ultra.Timing();
       cmMs = ultra.Ranging(CM); // Estimute CM;
       lcd.setCursor(0, 0);
       lcd.print("MS: ");
       lcd.print(microsec);
       lcd.print("ms");
        lcd.setCursor(0, 1);
        lcd.print("Stance: ");
       lcd.print(cmMs);
       lcd.print("cm");
}

