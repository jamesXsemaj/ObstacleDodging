#include  <Servo.h>     //Servo library
 
Servo servo_test;        //initialize a servo object for the connected servo  
const int toggleSwitch = 2; // Digital Pin 2 connects to the toggle switch
const int onSwitch = 5; // Digital Pin 5 connects to the on switch
const int motorTerminal1 = 3; // Digital Pin 3 connects to motor terminal 1
const int motorTerminal2 = 4; // Digital Pin 4 connects to motor terminal 2
const int motorPin = 6;// motor speed
const int enablePin = 9; // Digital pin 9 connects to the enable pin 
int angle = 0;    
 
void setup() 
{ 
  servo_test.attach(8);      // attach the signal pin of servo to pin9 of arduino
  pinMode(toggleSwitch, INPUT); //the toggle switch functions as an input 
  pinMode(onSwitch, INPUT); //the toggle on functions as an input 
  pinMode(motorPin, OUTPUT);//motor

  //The rest of the pins function as outputs
  pinMode(motorTerminal1, OUTPUT);
  pinMode(motorTerminal2, OUTPUT);
  pinMode(enablePin, OUTPUT);

  digitalWrite(enablePin, HIGH);
} 
  
void loop() 
{ 
  int speed = 55;
    analogWrite(motorPin, speed);
  if(digitalRead(onSwitch) == LOW){//hold push bottom to turn motor on
    if (digitalRead(toggleSwitch) == HIGH) { 
    digitalWrite(motorTerminal1, LOW); //these logic levels create forward direction
    digitalWrite(motorTerminal2, HIGH); 
    }
    else {
      digitalWrite(motorTerminal1, HIGH); // these logic levels create reverse direction
      digitalWrite(motorTerminal2, LOW); 
    }

    int speed = 55;
    analogWrite(motorPin, speed);
    for(angle = 0; angle < 180; angle += 1)    // command to move from 0 degrees to 180 degrees 
    {                                  
      servo_test.write(angle);                 //command to rotate the servo to the specified angle
      delay(50);                       
    } 
    speed = 255;
    analogWrite(motorPin, speed);
    for(angle = 180; angle>=1; angle-=5)     // command to move from 180 degrees to 0 degrees 
    {                                
      servo_test.write(angle);              //command to rotate the servo to the specified angle
      delay(150);                       
    } 
  }
  else{
    digitalWrite(motorTerminal1, LOW);
    digitalWrite(motorTerminal2, LOW); 
    for(angle = 0; angle < 180; angle += 1)    // command to move from 0 degrees to 180 degrees 
    {                                  
      servo_test.write(angle);                 //command to rotate the servo to the specified angle
      delay(15);                       
      //delay there 
    } 
 
    delay(1000);
  
    for(angle = 180; angle>=1; angle-=5)     // command to move from 180 degrees to 0 degrees 
    {                                
      servo_test.write(angle);              //command to rotate the servo to the specified angle
      delay(5);                       
    } 
  }
  
  

 
}

