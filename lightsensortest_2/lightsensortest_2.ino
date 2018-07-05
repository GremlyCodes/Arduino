#include <Stepper.h>

#define STEPS_PER_MOTOR_REVOLUTION 32   
#define STEPS_PER_OUTPUT_REVOLUTION 32 * 64  //2048  
#define STEPS_MAX 100
#define STEPS_MID 70
#define STEPS_MIN 30

Stepper stepperOne (STEPS_PER_MOTOR_REVOLUTION,0,1,2,3);
Stepper stepperTwo (STEPS_PER_MOTOR_REVOLUTION,4,5,6,7);
Stepper stepperThree (STEPS_PER_MOTOR_REVOLUTION,8,9,10,11);

int Steps2Take;
int StepsBack;

int portStart = A0; //refers to analog pin 0 A0
int portEnd = A1; //change to the last analog pin attached A5

float minimumSoFar = 1000; //change this to the maximum reading the attached sensor can give
float currentPinVal;
int whichPinItWas;

float readingZero;
float readingOne;
float readingTwo;
float readingThree;
float readingFour;
float readingFive; 

void setup() {
  Serial.begin(9600);
}

void loop() {
  readingZero = analogRead(A4);
  readingOne = analogRead(A5);

  //Serial.print("Reading Zero: ");
  //Serial.println(readingZero);
  //Serial.print("Reading One: ");
  //Serial.println(readingOne);

  if (readingZero<200 || readingOne<200) {
    for(int i = portStart; i<=portEnd; i++){
      currentPinVal = analogRead(i);
      Serial.print("Current Pin Value: ");
      Serial.print(i);
      Serial.println(currentPinVal);

      if (currentPinVal<minimumSoFar){
        minimumSoFar = currentPinVal;
        whichPinItWas = i;
        Serial.print("Current Pin Value:");
        Serial.println(currentPinVal);
        Serial.print("Which Pin It Was:");
        Serial.println(whichPinItWas);
        }
      }
    }

  switch (whichPinItWas){
    
    case 0:
      Serial.println("Case Zero");
      Steps2Take  =  STEPS_MAX ;  // Rotate CW 30deg
      StepsBack = -STEPS_MAX;
      stepperThree.setSpeed(500);   
      stepperThree.step(Steps2Take);
      delay(100);
      stepperThree.step(StepsBack);
      delay(1000);
      break;

    case 1:
      Serial.println("Case One");
      Steps2Take  =  -STEPS_MAX;  // Rotate CCW 30deg
      StepsBack = STEPS_MAX;
      stepperThree.setSpeed(500);  // 700 a good max speed??
      stepperThree.step(Steps2Take);
      delay(100);
      stepperThree.step(StepsBack);
      delay(1000);
      break;

    default:
      //do nothing
      break;
    }

    */
    
  delay(1000);
}
