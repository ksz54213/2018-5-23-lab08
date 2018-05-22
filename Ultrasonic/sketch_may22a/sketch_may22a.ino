#include <Ultrasonic.h>
#define Echo_pin 11
#define Trig_pin 12
const byte Button = 6;
volatile boolean state = LOW;
Ultrasonic ultra(Trig_pin,Echo_pin);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Button,INPUT);
  attachInterrupt(0 , int0, LOW);
  //            No   Source mode
}

void loop() {
  // put your main code here, to run repeatedly:
  float cmMs;
    if(state){
         long microsec = ultra.Timing();
        cmMs = ultra.Ranging(CM); // Estimute CM;
      Serial.print("Ms : "); Serial.print(microsec);Serial.print(" ms  ");
      Serial.print("Stance : "); Serial.print(cmMs); Serial.println(" cm");
      delay(1000);
    }
    else{
      Serial.println(" interrupt happened ");
    }
}

void int0(){
  state =! state;
 
}

