#include<Ultrasonic.h>
#define Trig_pin 12
#define Echo_pin 11
Ultrasonic ultrasonic(Trig_pin,Echo_pin);
volatile float cmMsec;
volatile long Ms;
volatile boolean state = LOW;
void setup(){
  
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  digitalWrite(2,state);
  attachInterrupt(0,INT0,LOW);

}

void loop(){
  
 if(digitalRead(2)){
    delay(1000);
 }
  else{
    INT0();
    delay(1000);
  }
}

void INT0(){
  state = !state;
  Serial.println( "HIGH" );
  Ms =ultrasonic.Timing();
  cmMsec = ultrasonic.Ranging(CM);
  Serial.print("Ms : "); Serial.print(Ms);Serial.print(" ms  ");
  Serial.print("Stance : "); Serial.print(cmMsec); Serial.println(" cm");
}

