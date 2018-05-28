#include <Ultrasonic.h>

const byte Trig_pin = 12;
const byte Echo_pin =11;
Ultrasonic ultrasonic(Trig_pin,Echo_pin);
volatile float cmMsec;
volatile long microsec;
#define  interrupts() INT0(); 



void setup() {
  Serial.begin(9600);

  pinMode(6,INPUT);
  attachInterrupt(0, INT0,LOW); 

}
void loop() { 
  
  if(digitalRead(6)){
        noInterrupts();
        delay(1000);
  } 
  else{
    interrupts();
    delay(1000);
  }
}

void INT0(){
        
        microsec = ultrasonic.Timing();
        cmMsec = ultrasonic.Ranging(CM);
        Serial.print("Ms : "); Serial.print(microsec);Serial.print(" ms  ");
        Serial.print("Stance : "); Serial.print(cmMsec); Serial.println(" cm");
}
