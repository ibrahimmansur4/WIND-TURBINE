  /*     Stepper Motor using a Rotary Encoder
 *      
 *  Semester Project of Wind Turbine
 *  
 */


// defines pins numbers
 #define stepPin 8 
 #define dirPin  9
 #define outputA 2
 #define outputB 3

 int counter = 0;
 int angle = 0; 
 int aState;
 int aLastState;  
 
void setup() {
  // Sets the two pins as Outputs and two as inputs
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  pinMode (outputA,INPUT);
  pinMode (outputB,INPUT);

  Serial.begin (9600); //starts serial communication
  aLastState = digitalRead(outputA); //reads the intial value of the encoder
  
}
void loop() {

  aState = digitalRead(outputA);  //the value is read again for different variable
     //logic
    //if the encoder is rotated the two above values will be changed 
    //so it will act as an indicator of movement
  if (aState != aLastState){     
    //logic
    //if output b has different value than output a it would mean cw motion
     if (digitalRead(outputB) != aState) { 
      //increases the counter and moves the turbine CW
       counter ++;
       angle ++;
       rotateCW();  
     }
     else {
       counter--;
       angle --;
       rotateCCW(); 
     }
     //resets the value on serial monitor after a full revoltuion
     //the encoder is a 30 step 
     if (counter >=30 or counter <= -30) {
      counter =0;
     }
     Serial.print("Position: ");
     Serial.println(counter);
    
     
     Serial.print(int(angle*(1.8)));
     Serial.println("deg"); 
     
     
   }
  aLastState = aState; //the variable is updated
}
//functions to make the motion of motor
void rotateCW() {
    digitalWrite(dirPin,LOW); //enables movement in a specific direction
   for(int x = 0; x < 7; x++){ // a loop to make the encoder and motor be in sync
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(1000); 
   }
}
void rotateCCW() {
    digitalWrite(dirPin,HIGH);
  for(int x = 0; x <7; x++){
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(1000);   
  }
}
