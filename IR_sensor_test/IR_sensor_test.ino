#include <Stepper.h>

#define STEPS_PER_MOTOR_REVOLUTION 32   
#define STEPS_PER_OUTPUT_REVOLUTION 32 * 64  //2048  
#define STEPS_MAX 100

Stepper stepperOne (STEPS_PER_MOTOR_REVOLUTION,8,9,10,11);

int Steps2Take;
int StepsBack;

float readingZero;

void setup() {
  Serial.begin(9600);

}

void loop() {
  readingZero = analogRead(A0);
  Serial.print("Reading Zero: ");
  Serial.println(readingZero);

   if (readingZero>400) {
      Steps2Take  =  STEPS_MAX ;  // Rotate CW 30deg
      StepsBack = - STEPS_MAX;
      stepperOne.setSpeed(250);   
      stepperOne.step(Steps2Take);
      delay(100);
      stepperOne.step(StepsBack);
      delay(1000);
    }

   else{
    Serial.println("Reading is _____ threshold");
    delay(200);
    }

  delay(1000);
}
