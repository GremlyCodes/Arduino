#include <Stepper.h>

const int stepsPerRevolution = 2048;
int inPin = 2;

int state = HIGH;
int reading;
int previous = LOW;
int direct = 0;

long time = 0;
long debounce = 200;

Stepper myStepper (stepsPerRevolution,8,9,10,11);

int stepCount = 0;

void setup() {
  Serial.begin(9600);
  pinMode(inPin, INPUT);
  }

void loop() {
  reading = digitalRead(inPin);

  if (reading == HIGH && previous == LOW && millis() - time>debounce){

   if (state == HIGH){
    state = LOW;
    direct = direct +1;
    Serial.print("Direct:");
    Serial.println(direct);
    }
   else {
    state = HIGH;
    direct = direct-1;
    Serial.print("Direct:");
    Serial.println(direct);
    }
   }
  previous = reading;
  Serial.println(reading);
  
    if (direct == 0){
      for(int i=0; i < 2048; i++){
        myStepper.step(1);
        Serial.print("Steps:");
        Serial.println(stepCount);
        stepCount++;
        //delay(10);
        }
       
      }
      
     else if (direct == 1){
      for(int i=0; i < 2048; i++){
        myStepper.step(-1);
        Serial.print("Steps:");
        Serial.println(stepCount);
        stepCount--;
        //delay(10);
        }
        
      }
     else {
      Serial.println("Direction not specified.");
      Serial.print("Direction:");
      Serial.println(direct);
      }
  
  }
