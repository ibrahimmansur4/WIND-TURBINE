#include <Stepper.h> 

#define STEPS 200


// Define stepper motor connections and motor interface type. Motor interface type must be set to 1 when using a driver

Stepper stepper(STEPS, 9, 8); // Pin 9 connected to DIRECTION & Pin 8 connected to STEP Pin of Driver

#define motorInterfaceType 1 //because the motor is connected through a driver module

int Pval = 0;

int potVal = 0;


void setup() {
  Serial.begin(9600);
  // Set the maximum speed in steps per second:
  //1000 rpm
  // after which torque falls
  stepper.setSpeed(1000); 

}

void loop() {
  potVal = map(analogRead(A0),0,1024,0,500);
//clockwise
  if (potVal>Pval){
      stepper.step(10);
      Serial.println("Clockwise motion");
  }
//anti clockwise
  if (potVal<Pval){
      stepper.step(-10);
      Serial.println("Anti-Clockwise motion");
  }
  else { 
     Serial.println("No motion");
  }

Pval = potVal;

}
