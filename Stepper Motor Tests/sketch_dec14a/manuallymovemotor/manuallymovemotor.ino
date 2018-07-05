#include <Stepper.h>

#define STEPS_PER_MOTOR_REVOLUTION 32   
#define STEPS_PER_OUTPUT_REVOLUTION 32 * 64  //2048  
#define STEPS_SMALL 10

Stepper small_stepper(STEPS_PER_MOTOR_REVOLUTION, A0, A1, A2, A3);
 
int  Steps2Take;

const unsigned int BUTTON_PIN = 2;
 
void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT);
}
 
void loop() {
  
  const int CURRENT_BUTTON_STATE = digitalRead(BUTTON_PIN);
 
  //if (CURRENT_BUTTON_STATE == HIGH){
    Steps2Take  =  STEPS_SMALL ;  
    small_stepper.setSpeed(500);   
    small_stepper.step(Steps2Take);
    //Serial.println(CURRENT_BUTTON_STATE);
    //delay(100);
    
  //}
  
}
